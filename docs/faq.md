# FAQ

## General

### What is a HWID?

A Hardware ID (HWID) is a fingerprint derived from components like disk serial, motherboard UUID, MAC address, and Windows registry keys. Software uses it to identify a specific machine.

### Is this tool legal?

Laws vary by jurisdiction. This project is provided for research and testing on hardware you own. You are responsible for how you use it.

### Does it bypass game bans?

This tool changes local identifiers. Whether that affects a ban depends entirely on what the target platform tracks. We make no claims about bypassing anti-cheat or account restrictions.

## Technical

### Why do I need Administrator?

Modifying volume serials, adapter MAC addresses, and certain registry keys requires elevated privileges on Windows.

### Will spoofing survive a reboot?

Most module changes are temporary and reset on reboot. Use `backup` and `restore` for controlled testing sessions.

### User-mode vs kernel driver?

| Capability | User-mode | Kernel driver |
|------------|-----------|---------------|
| MAC address | Yes | Yes |
| Volume serial | Yes | Yes |
| Registry cleanup | Yes | N/A |
| Disk serial at IOCTL level | Limited | Yes |
| SMBIOS from firmware path | Limited | Yes |

### Where are backups stored?

`backup/hwid_backup.json` in the working directory. This folder is gitignored — backups stay local.

## Repository

### Why does `last-updated.txt` change automatically?

GitHub Actions runs every 30 minutes (see `.github/workflows/auto-commit.yml`) to keep the repository timestamp fresh — same pattern as automated maintenance repos.

### How do I set the social preview image?

Upload `preview.png` (1280×640) under **Settings → General → Social preview** on GitHub, or rely on the Open Graph image linked from README.
