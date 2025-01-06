#!/bin/bash
# I made this for my own use. You mightn't have any use of it...
make
./src/RayTracing > out.ppm
nsxiv . & disown
