# Graphics library setup 

## Quick setup

```bash
git clone https://github.com/ullaskunder3/graphics.h-project-template.git
```

Detail setup can be found on my other repo [solution-to-graphics.h](https://github.com/ullaskunder3/Solution-to-graphics.h)

## My directory look like

```cmd
  D:.
├───.vscode
└───Home
    ├───build
    └───src
```

- Just `Ctrl+Shift+B` to run the build task you will get the executable file in build folder

## !mportant

- Folder `src` contains source code

- Folder `build` where compiler generate .exe

- .vscode contains c_cpp_properties.json and task require modification according to your environment and types compile
  #Computer Graphics Mini Projects

This repository contains mini projects related to **Computer Graphics** developed in **C++**. The `Home` folder includes various projects demonstrating the practical applications of fundamental computer graphics concepts.

## Key Concepts Covered

- **2D Transformations**: Operations like translation, rotation, scaling, reflection, and shearing applied to 2D objects.
- **3D Transformations**: Manipulation of 3D objects through translation, rotation, and scaling in three-dimensional space.
- **Bresenham's Algorithms**: Efficient algorithms for drawing lines and circles by minimizing floating-point calculations.
- **Clipping Algorithms**: Techniques like Cohen-Sutherland and Liang-Barsky algorithms for clipping lines and polygons within a defined viewport.
- **Bezier and B-Spline Curves**: Methods for designing smooth and scalable curves used in graphics design and modeling.

## Animation Techniques using `graphics.h`

- **Frame-by-Frame Animation**: Updating object positions and redrawing frames to create smooth motion.
- **Double Buffering**: Reducing flickering by drawing frames off-screen before displaying them.
- **Delays and Timing Control**: Using functions like `delay()` to control the speed of animation.
- **Transformation-Based Animation**: Applying continuous transformations (translation, rotation, scaling) to animate objects.
- **Object Path Animation**: Moving objects along predefined or dynamic paths for complex animations.

