*This project has been created as part of the 42 curriculum by llepesqu and plepercq*

# Cub3D

[Subject](https://cdn.intra.42.fr/pdf/pdf/217058/en.subject.pdf)

## Description

Raycaster with miniLibX

## Instructions

### Compilation

```bash
make
```

Generates the `cub3D` executable.

Other available targets:

```bash
make clean   # removes object files
make fclean  # removes object files and the executable
make re      # rebuilds the whole project
```

### Usage

```bash
./cub3D scene_description_file
```

| Argument | Description |
|---|---|
| `scene_description_file` | A .cub file containing the file paths for wall textures, floor and ceiling colors, and the maze map |

#### Example

the .cub file must contains :

- The maze
```
        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```
- wall textures
```
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
```
- colors for ceiling and floor
```
F 220,100,0
C 225,30,0
```

If the file is correct, the following command will run the game with the specified settings.

```bash
./cub3D ./themes/doom.cub
```

## Resources

## Authors

- **Lucas LEPESQUEUX** — [llepesqu@student.42.fr]
- **Pierre LEPERCQ** — [plepercq@student.42.fr]
