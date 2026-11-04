# HW4 playable reference demos

These are playable reference programs for both games, not source code.
Use a UTF-8 ANSI truecolor terminal. Both games are silent; no audio setup
or editor is needed. Run each game from its own p1/ or p2/ folder.

## Choose your platform

- `linux-x86_64/`: Linux on x86_64. Built on Ubuntu 24.04.3 LTS with glibc;
  the binaries require glibc 2.34 or newer (highest required GLIBC symbol
  version observed with `objdump -T`). Other distributions need compatible glibc.
- `macos-arm64/`: macOS 11 or newer on Apple Silicon (arm64).
  Intel Macs are not supported.

After extracting, run these commands from the directory containing `hw4-demo/`.
Choose only the pair for your operating system. Run each example independently
from that starting directory (not from the other game's folder):

Linux:
```sh
cd hw4-demo/linux-x86_64/p1 && ./snake
cd hw4-demo/linux-x86_64/p2 && ./flappy
```

macOS (Apple Silicon):
```sh
cd hw4-demo/macos-arm64/p1 && ./snake
cd hw4-demo/macos-arm64/p2 && ./flappy
```

If executable permissions were lost, run `chmod +x ./snake` or
`chmod +x ./flappy` in the corresponding game folder before starting it.

## Controls

- P1 Snake: WASD or arrow keys to move; P pauses/resumes; R restarts; Q quits.
  If cells look stretched, run `./snake --calibrate` from the p1/ folder.
- P2 Flappy Bird: Space starts, flaps, or retries; P pauses/resumes;
  R returns to the ready screen; Q quits.

## macOS download security

The macOS binaries are ad-hoc signed, not Developer ID signed or notarized.
macOS quarantines downloaded files and may block these programs. If it does,
run this once in Terminal, from the directory containing `hw4-demo/`, then retry:

```sh
xattr -dr com.apple.quarantine hw4-demo
```

This removes the downloaded-file quarantine marker from this demo folder.
Only do this for a download you trust. If a macOS demo still does not start,
tell the course staff which macOS version you use.
