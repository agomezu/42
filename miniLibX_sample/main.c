#include "minilibx.h"

int		handleEvent(XEvent *event)
{
	if (event->type == EnterNotify)
	{
		printf("Hello!\n");
	}
	else if (event->type == LeaveNotify)
	{
		printf("Bye!\n");
	}
	return (0);
}

void	freemem(t_program *g)
{
	free(g->mlx_pointer);
	free(g->window);
}

int	b_close(t_program *g)
{
	mlx_destroy_window(g->mlx_pointer, g->window);
	printf("Program closed.\n");
	freemem(g);
	exit(0);
}

int	close(t_program *g)
{
	mlx_destroy_window(g->mlx_pointer, g->window);
	freemem(g);
	exit(0);
}

int	main(void)
{
	t_program g;
	Display *display;
	Window	window;
	XEvent	event;
	
	g.mlx_pointer = mlx_init();
	g.window = mlx_new_window(g.mlx_pointer, W, H, "Test miniLibX");
	display = XOpenDisplay(NULL);
	window = DefaultRootWindow(display);
	XSelectInput(display, window, EnterWindowMask | LeaveWindowMask);
	mlx_hook(g.window, EnterNotify, 0, handleEvent, &g.mlx_pointer);
	mlx_hook(g.window, LeaveNotify, 0, handleEvent, &g.mlx_pointer);
	mlx_hook(g.window, 2, 1L<<0, close, &g);
	mlx_hook(g.window, 17, 1L<<2, b_close, &g);
	while (1)
	{
		mlx_do_sync(g.mlx_pointer);
		XNextEvent(display, &event);
		mlx_hook(g.window, event.type, 0, handleEvent, g.mlx_pointer);
	}
	XCloseDisplay(display);
	mlx_loop(g.mlx_pointer);
	return(0);
}
