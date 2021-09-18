#include <mlx.h>

int main()
{
	void	*gnrl_ptr;
	void	*win_ptr;
	int g;
	int h;

	gnrl_ptr = mlx_init();
	win_ptr = mlx_new_window(gnrl_ptr, 1500, 900, "Cat");
	g = -1;
	while (g++ < 1500)
	{
		h = -1;
		while (h++ < 100)
		{
			mlx_pixel_put (gnrl_ptr, win_ptr, g, h, 16776960);
		}
	}
	g = -1;
	while (g++ < 1500)
	{
		h = 99;
		while (h++ < 200)
		{
			mlx_pixel_put (gnrl_ptr, win_ptr, g, h, 16711680);
		}
	}
	g = -1;
	while (g++ < 1500)
	{
		h = 199;
		while (h++ < 300)
		{
			mlx_pixel_put (gnrl_ptr, win_ptr, g, h, 16776960);
		}
	}
	g = -1;
	while (g++ < 1500)
	{
		h = 299;
		while (h++ < 400)
		{
			mlx_pixel_put (gnrl_ptr, win_ptr, g, h, 16711680);
		}
	}
	g = -1;
	while (g++ < 1500)
	{
		h = 399;
		while (h++ < 500)
		{
			mlx_pixel_put (gnrl_ptr, win_ptr, g, h, 16776960);
		}
	}
	g = -1;
	while (g++ < 1500)
	{
		h = 499;
		while (h++ < 600)
		{
			mlx_pixel_put (gnrl_ptr, win_ptr, g, h, 16711680);
		}
	}
	g = -1;
	while (g++ < 1500)
	{
		h = 599;
		while (h++ < 700)
		{
			mlx_pixel_put (gnrl_ptr, win_ptr, g, h, 16776960);
		}
	}
	g = -1;
	while (g++ < 1500)
	{
		h = 699;
		while (h++ < 800)
		{
			mlx_pixel_put (gnrl_ptr, win_ptr, g, h, 16711680);
		}
	}
	g = -1;
	while (g++ < 1500)
	{
		h = 799;
		while (h++ < 900)
		{
			mlx_pixel_put (gnrl_ptr, win_ptr, g, h, 16776960);
		}
	}
	mlx_pixel_put (gnrl_ptr, win_ptr, -2000, -2000, 255);
	mlx_loop(gnrl_ptr);
}