# Security Policy

## Supported Versions

| Version | Supported |
|---------|-----------|
| latest release on `main` | yes |
| older releases | best effort |

## Reporting a Vulnerability

**Do not** open a public GitHub issue for security vulnerabilities.

Instead:

1. Go to **Security → Report a vulnerability** on the repository page, or
2. Email the maintainers with subject `[SECURITY] hwid-spoofer`

Include:

- Description of the issue
- Steps to reproduce
- Impact assessment
- Suggested fix (optional)

We aim to acknowledge reports within 72 hours.

## Scope

In scope:

- Privilege escalation beyond documented admin requirement
- Arbitrary code execution via malformed backup/config files
- Driver module memory safety issues

Out of scope:

- Effectiveness against third-party anti-cheat or ban systems
- Social engineering
- Issues requiring physical access

## Safe Usage

- Run only on machines you control
- Review source before building
- Never run untrusted pre-built binaries from unofficial sources
