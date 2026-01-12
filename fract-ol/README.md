# Fract-ol

A fractal visualization program that renders beautiful mathematical fractals using the MiniLibX graphics library.

## Description

This project explores the world of fractals by implementing a program that can display various types of fractals including:
- Mandelbrot set
- Julia sets
- Other fractal variations

## Files

- [`fractol.h`](fractol.h) - Header file with function prototypes and structures
- [`fractol.c`](fractol.c) - Main program logic
- [`building.c`](building.c) - Fractal construction functions
- [`control_way.c`](control_way.c) - User input handling and controls
- [`fractol_utile.c`](fractol_utile.c) - Utility functions
- [`window_construction.c`](window_construction.c) - Window initialization and setup
- [`Makefile`](Makefile) - Build configuration

## Usage

```bash
make
./fractol [fractal_type] [optional_parameters]
```

## Features

- Interactive fractal exploration
- Zoom functionality
- Color variations
- Real-time parameter adjustments
- Multiple fractal types

## Controls

- Mouse scroll: Zoom in/out
- Arrow keys: Navigate
- Various keys for color and parameter adjustments