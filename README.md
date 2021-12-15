# FdF @ 42

A simple 3D height-map renderer. You can rotate models, color is defined by
relative height in the map. More features planned!

## Features
* Simple file format definition (array of space-separated integers)
* Rotations
* Camera controls (zoom, translate)
* Colors parsed from the map

## Compiling and running
Run `make`. An executable will compile. Currently only tested on OS X.

Run it with `./fdf [map]`. A bunch of sample maps are provided in the `test_maps`
directory.

Controls are shown in the window of the compiled project
