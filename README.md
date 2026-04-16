*This project has been created as part of the 42 curriculum by grivault.*

## Description
so_long is a small 2D game built using the MiniLibX graphics library. The objective of the game is to navigate a map, collect all available items, and reach the exit in the fewest moves possible.

The engine features a custom double-buffered rendering system to prevent screen tearing, cross-platform compilation support for both macOS and Linux X11, and strict map validation using a recursive flood-fill algorithm to ensure all objectives are reachable. It also ensures complete memory safety with zero leaks during execution or error handling.

## Instructions

### Compilation
You can compile the project using the provided Makefile. The available rules are:
- [cite_start]`make` : Compiles the executable `so_long`[cite: 3].
- [cite_start]`make clean` : Removes the object files[cite: 3].
- [cite_start]`make fclean` : Removes the object files and the executable[cite: 3].
- [cite_start]`make re` : Fully recompiles the project[cite: 3].
- [cite_start]`make redo` : Recompiles and immediately cleans the object files[cite: 3].

### Execution
To run the game, pass a valid `.ber` map file as an argument:
`./so_long Maps/Valid/map_subject.ber`

### Controls
- **W / Up Arrow** : Move Up
- **S / Down Arrow** : Move Down
- **A / Left Arrow** : Move Left
- **D / Right Arrow** : Move Right
- **ESC** : Close the window and exit the game safely

## Resources
- **MiniLibX Documentation**: Official 42 library references for window management, image rendering, and event hooking.
- **X11 / AppKit**: Underlying window systems utilized by the library on Linux and macOS respectively.
- **AI Usage**: AI (Gemini) was utilized as an interactive debugging assistant during this project. It was used specifically to help identify and resolve Valgrind memory leaks (specifically related to X11 display destruction), to implement the off-screen double-buffering logic to fix OS-level screen tearing, and to format this README file.

## Map Format
The map must be a rectangular grid strictly surrounded by walls. It can contain the following characters:
- `1` : Wall
- `0` : Empty space
- `C` : Collectible
- `E` : Exit
- `P` : Player starting position

## Exit Codes
If the program encounters an error, it will exit cleanly, free all memory, and return one of the following codes:
- **3** : Invalid file: The file provided is not a .ber file
- **4** : Invalid file: The file provided does not exist
- **5** : Invalid map: Invalid caracter in the provided map
- **6** : Malloc failed
- **7** : Invalid map: Incorrect number of P or E
- **8** : Invalid map: Map is not delimited by ones
- **9** : Invalid map: Map is not rectangular
- **10** : Invalid argument: expects exactly one argument
- **11** : Bug: no P found in map
- **12** : Invalid map: Cannot reach all C or E
- **13** : Invalid map: No C on the map
