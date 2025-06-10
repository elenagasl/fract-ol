# fract-ol

Este proyecto forma parte del plan de estudios de 42 y consiste en una representación gráfica de fractales utilizando la biblioteca MiniLibX. Se pueden visualizar fractales como el conjunto de Mandelbrot, Julia y Tricorn, con soporte para zoom, desplazamiento y parámetros dinámicos.

## Descripción

`fract-ol` genera fractales complejos en tiempo real mediante renderizado en una ventana gráfica. Permite la interacción con el ratón y el teclado para explorar los fractales, cambiar el número de iteraciones, la paleta de color y modificar la forma del fractal de Julia si se activa la opción correspondiente.

## Fractales soportados

- Mandelbrot
- Julia
- Tricorn

## Instalación

Clona el repositorio y asegúrate de tener las bibliotecas `libft` y `minilibx` en las carpetas correspondientes.

```bash
git clone https://github.com/tuusuario/fract-ol.git
cd fract-ol
make
```
Nota: si estás en macOS, utiliza minilibx_opengl. Si estás en Linux, utiliza minilibx-linux.

## Uso
```bash
./fractol <fractal> [opciones]
```

### Fractales disponibles

Mandelbrot

Julia

Tricorn

### Opciones disponibles

Número de iteraciones: cualquier número entre 1 y 1000

Paletas: White, Psico, Red, Green, Blue

Julia: número complejo en formato "Re Im", por ejemplo "0.285 0.01i"

### Ejemplos de uso 

```bash
./fractol Mandelbrot 100 Rainbow
./fractol Julia "0.285 0.01i" --motion 300 Psico
./fractol Tricorn Pastel 400
```

## Controles

Zoom in / out:	Rueda del ratón
Desplazar izquierda/derecha:	Flechas ← / →
Desplazar arriba/abajo:	Flechas ↑ / ↓
Cerrar la ventana:	Tecla ESC
Aumentar iteraciones:	Tecla i (requiere --dynamic)
Modificar Julia en tiempo real:	Mover el ratón

## Compilación 

Compilado con:

MiniLibX

libft (implementación propia)

Frameworks requeridos en macOS:

OpenGL

Cocoa

IOKit

Metal

QuartzCore

![Fractal renderizado](https://www3.gobiernodecanarias.org/medusa/ecoblog/mrodperv/files/2015/12/f.jpg)




