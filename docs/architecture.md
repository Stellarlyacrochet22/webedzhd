# Architecture

## Overview

HWID Spoofer is split into a thin CLI/GUI front-end and pluggable spoof modules. All modules implement `ISpoofModule` and register through `ModuleRegistry`.

```
┌─────────────┐     ┌──────────────┐     ┌─────────────────┐
│  CLI / GUI  │────▶│  SpoofEngine │────▶│  ISpoofModule   │
└─────────────┘     └──────┬───────┘     └─────────────────┘
                           │
                    ┌──────▼───────┐
                    │ BackupManager │
                    └──────────────┘
```

## Modules

| Module | Layer | Persistence |
|--------|-------|-------------|
| `DiskSerialSpoofer` | User-mode IOCTL / optional driver | Until reboot |
| `SmbiosSpoofer` | Registry + driver hook | Until reboot |
| `MacSpoofer` | `netsh` + registry | Until adapter reset |
| `VolumeSerialSpoofer` | Volume control | Until remount |
| `RegistryCleaner` | Registry delete | Permanent until re-created by OS |

## Backup Format

Backups are stored as JSON in `backup/hwid_backup.json`:

```json
{
  "timestamp": "2026-06-21T12:00:00Z",
  "disk_serial": "...",
  "smbios_uuid": "...",
  "mac_addresses": ["..."],
  "volume_serials": ["..."]
}
```

## Optional Kernel Driver

The `driver/` component provides block-level disk serial interception. Requires WDK and code signing for production use. User-mode-only builds skip this module at compile time via `HWID_NO_DRIVER`.

## Logging

Logs write to `%TEMP%\hwid-spoofer.log` with rotation at 5 MB.
