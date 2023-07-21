
#ifndef MINILIBX_H
# define MINILIBX_H

#include "./minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

# define W 500 
# define H 500 

typedef struct s_program
{
    void    *mlx_pointer;
    void    *window;
    // ...
}               t_program;

#endif