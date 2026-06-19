*This project has been created as part of the 42 curriculum by lgrigore and juan-her.*

---

# cub3D

A 3D raycasting engine inspired by the legendary Wolfenstein 3D, built in C using the miniLibX graphics library.

---

## Description

**cub3D** is a first-person perspective 3D renderer that uses the **raycasting** technique to simulate a 3D environment from a 2D map.

The project is structured into four main modules:

| Module | Responsibility |
|--------|---------------|
| `parser/` | Reads and validates the `.cub` scene file (map layout, textures, colors) |
| `game/engine/` | Core raycasting logic, wall detection, distance calculation, rendering |
| `game/player/` | Player state: position, direction, field of view, and movement |
| `screen/` | Window management, frame rendering, and texture loading |


---

## Instructions

### Requirements

- miniLibX


### Compilation

```bash
make
```

This will produce the `cub3D` executable in the project root.

To clean object files:

```bash
make clean
```

To remove all generated files including the binary:

```bash
make fclean
```

### Execution

```bash
./cub3D <path/to/scene.cub>
```

**Example:**

```bash
./cub3D maps/example.cub
```

### Scene File Format (`.cub`)

The scene file defines the environment. It must contain:

- **Texture paths** for the four cardinal wall directions:
  ```
  NO ./textures/north.xpm
  SO ./textures/south.xpm
  WE ./textures/west.xpm
  EA ./textures/east.xpm
  ```
- **Floor and ceiling colors** in RGB:
  ```
  F 220,100,0
  C 100,180,255
  ```
- **Map** (composed of `0`, `1`, and `N`/`S`/`E`/`W` for player spawn):
  ```
  111111
  100001
  1000N1
  111111
  ```

### Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move forward |
| `S` / `↓` | Move backward |
| `A` | Strafe left |
| `D` | Strafe right |
| `←` / `→` | Rotate camera |
| `ESC` | Exit |

---

## Project Structure

```
.
├── main.c
├── game/
│   ├── engine/
│   │   ├── calc_wall.c       # Wall height and distance calculation
│   │   ├── engine.c          # Main render loop
│   │   ├── engine_create.c   # Engine initialization
│   │   ├── engine_move.c     # Movement and collision detection
│   │   └── ray.c             # Ray direction and DDA algorithm
│   └── player/
│       └── player.c          # Player position, angle, and state
├── parser/
│   ├── get_next_line.c
│   ├── parser.c              # Entry point for scene file parsing
│   ├── parser_check.c        # General validation
│   ├── parser_color.c        # RGB color parsing
│   ├── parser_header.c       # Texture/color header parsing
│   ├── parser_header_b.c
│   ├── parser_header_utils.c
│   ├── parser_line_list.c    # Line-by-line file reading
│   ├── parse_line_list_utils.c
│   ├── parser_map.c          # Map section extraction
│   ├── parser_utils.c
│   ├── parser_validate_map_chars.c   # Character validation
│   └── parser_validate_map_flood.c   # Flood-fill map enclosure check
└── screen/
    ├── screen.c              # Window and event hooks
    ├── screen_life_cycle.c   # Init and teardown
    └── textures.c            # XPM texture loading
```

---

## Resources

- [miniLibX Linux documentation](https://harm-smits.github.io/42docs/libs/minilibx) — Unofficial but thorough community reference for the 42 graphics library.

- [DDA Algorithm — Wikipedia](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)) — Background on the Digital Differential Analyzer used for grid traversal.

