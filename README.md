# Console Digital Clock

A simple command-line digital clock written in C. You enter a starting hour and minute, and the program counts upward in real time, displaying the time in `HH:MM:SS` format on a single line that updates every second.

## Features

- Prompts for a starting hour (0-23) and minute (0-59)
- Re-prompts if the value entered is out of range
- Updates the display in place every second using a carriage return (`\r`)
- Handles rollover correctly: seconds to minutes, minutes to hours, and 23:59:59 back to 00:00:00
- 24-hour time format

## Requirements

- A **Windows** system (the program uses `<windows.h>` and the `Sleep()` function)
- A C compiler, such as:
  - [MinGW-w64 / GCC](https://www.mingw-w64.org/)
  - Microsoft Visual C++ (MSVC)

## Build

Assuming the source file is named `clock.c`:

**GCC (MinGW):**

```bash
gcc clock.c -o clock.exe
```

**MSVC (Developer Command Prompt):**

```bash
cl clock.c
```

## Run

```bash
clock.exe
```

## Example

```
Enter the hour (0-23): 14
Enter the minute (0-59): 30
14:30:07
```

The last line updates in place each second. Press `Ctrl + C` to stop the program.

## How It Works

1. The user enters the starting hour and minute. The seconds always start at `0`.
2. Inside an infinite loop, the program prints the current time with `printf("\r%02d:%02d:%02d", ...)`. The `\r` moves the cursor back to the start of the line so the time is overwritten instead of printed on a new line.
3. `fflush(stdout)` forces the output to appear immediately.
4. `Sleep(1000)` pauses the program for one second.
5. The seconds counter is incremented, and the minute and hour values roll over when they reach 60 and 24 respectively.

## Known Limitations

- **Windows only.** `windows.h` and `Sleep()` are not available on Linux or macOS. To port it, replace `Sleep(1000)`
