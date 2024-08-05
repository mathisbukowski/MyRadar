# My Radar

My Radar is a 2D visualization panel simulating air traffic control (ATC), built using C and utilizing the CSFML library. The goal of this project is to simulate aircraft movements and control tower interactions on a 1920x1080 window.

## Table of Contents
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Script Format](#script-format)
- [Authorized Functions](#authorized-functions)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Aircraft Simulation**: Aircrafts fly from specified departure points to arrival points at constant speeds.
- **Collision Detection**: Aircrafts collide and are destroyed unless within control tower areas.
- **Control Towers**: Towers have control areas allowing safe passage for aircrafts.
- **Interactive Visualization**: Toggle visibility of hitboxes and sprites.

## Prerequisites

- GCC (GNU Compiler Collection)
- CSFML (C binding for the SFML library)
- Make

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/mathisbukowski/my_radar.git
    cd my_radar
    ```

2. Compile the project using the provided Makefile:
    ```sh
    make
    ```

## Usage

To run the program, execute the following command:
```sh
./my_radar path_to_script
