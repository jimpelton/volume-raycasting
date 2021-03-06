# GPU-accelerated single-pass raycaster

![screenshot](https://user-images.githubusercontent.com/8300317/43370649-35fc6d96-9383-11e8-99b5-885f74435480.png)

This project is a simple visualiser based on GPU-accelerated single-pass
[volumetric raycasting](https://en.wikipedia.org/wiki/Volume_ray_casting),
implemented in [GLSL](https://www.khronos.org/opengl/wiki/OpenGL_Shading_Language)
and C++ with the [Qt](https://www.qt.io/) framework. It aims to provide a basic
skeleton for a visualiser that can be easily extended with a feature-rich GUI. Three
simple examples of shaders are provided for [isosurface](https://en.wikipedia.org/wiki/Isosurface)
rendering, front-to-back [alpha-blending](https://en.wikipedia.org/wiki/Alpha_compositing),
and [maximum intensity projection](https://en.wikipedia.org/wiki/Maximum_intensity_projection).
It includes a simple [VTK](https://www.vtk.org/) reader to load volumes from file.

# Build

The project can be built with [QtCreator](https://doc.qt.io/qtcreator/) or
from the command line, with [qmake](https://doc.qt.io/qt-5/qmake-manual.html)
```bash
mkdir build
cd build
qmake ../3d_raycaster.pro
make
```

# License

The software is distributed under the MIT license.
