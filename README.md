# Ray Tracer in C++

A simple, dependency-free ray tracer implemented in C++. This project is inspired by the **"Ray Tracing in One Weekend"** tutorial and was developed during the **Hack Club HighSeas** event.

## Features
- Fully implemented in C++ with no external dependencies
- Generates stunning ray-traced images
- Supports spheres, diffuse lighting, and basic materials
- Educational and easy to extend

## Getting Started

### Prerequisites
This project requires a C++ compiler that supports C++17 or later & CMake.
### Building
1. Clone the repository:
   ```bash
   git clone https://github.com/AnkushRoy-code/RayTracing.git
   cd RayTracer
   ```
2. Compile the code using your preferred compiler:
   ```bash
   cmake -B build -DCMAKE_BUILD_TYPE=Release
   cmake --build build --config Release
   ```
3. Run the program:
   3.1. Unix - (Mac/Linux)
   ```bash
   cd build
   chmos +x ../run.sh
   ./../run.sh # it uses nsxiv(image viewer) to view the image.
   # if you do not have nsxiv in your system change the run.sh file
   # to use your favourite image viewer.
   ```
   3.2 Windows
   Figure your shit out yourself by looking at run.sh

### Output
The program generates an image (out.ppm) in the PPM format, which can be viewed using an image viewer or converted to other formats.

## Inspiration
This project follows the "Ray Tracing in One Weekend" tutorial, an excellent introduction to the concepts of ray tracing.

## Contributing
Contributions are welcome! Feel free to open issues or submit pull requests to enhance the project.

## License
This project is licensed under the MIT License. See the πLICENSEπ file for details.

## Acknowledgments
- [Ray Tracing in One Weekend](https://raytracing.github.io/) by Peter Shirley
- Hack Club HighSeas event for the inspiration and support
