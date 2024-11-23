# fractols
## A 42-project that displays fractals in C

A small programm that can display the [Mandelbrot](https://en.wikipedia.org/wiki/Mandelbrot_set), [Julia](https://en.wikipedia.org/wiki/Julia_set) and the [Burning Ship](https://en.wikipedia.org/wiki/Burning_Ship_fractal) sets.  

![Mandelbrot set](/pictures/mandelbrot.png)



## Usage

Clone the repository and build the binary with the Makefile.
```
git clone git@github.com:LouisMahe/fractols.git
cd fractols
make
```
You can then execute the programm without arguments to obtain a list of possible arguments and commands. For example
`./fractols m` will draw the Mandelbrot set.
Once a picture is displayed you can use the arrow keys to move, scroll to zoom/unzoom. Pressing the key `m` will enable disable a "smooth mode" (see [Continuous smooth coloring here](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set)). You can also switch between some predefined color sets using `c`.  

## Screenshots

![Zoomed Mandelbrot](/pictures/mandelbrotzoomed.png)

![Julia set for c = -0.4 + 0.6i](/pictures/julia_04_06.png)

![Burning Ship](/pictures/bs.png)
