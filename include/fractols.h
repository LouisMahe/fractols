/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmahe <lmahe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:12:50 by lmahe             #+#    #+#             */
/*   Updated: 2023/12/28 13:04:35 by lmahe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOLS_H
# define FRACTOLS_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include "../lib/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include <X11/keysym.h>

# ifndef M_PI
#  define M_PI 3.1415926535
# endif
# define WIDTH 800
# define HEIGHT 800
# define SUBSIZE 32
# define BLACK 0x00000000

# define XSTEP 0.003
# define YSTEP 0.003
# define ZOOM 0.8

typedef struct s_fract
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			fract_set;
	int			smoothed;
	int			max_iter;
	double		smooth_bound;
	int			color_number;
	int			*palette;
	int			*palette2;
	int			*palette3;
	int			*palette4;
	double		julia_cx;
	double		julia_cy;
	double		zoom;
	double		x_center;
	double		y_center;
	double		x_min;
	double		y_max;
	double		xstep;
	double		ystep;
}			t_fract;

typedef struct s_data
{
	void	*pmlx;
	void	*pwin;
	t_fract	fract;
}				t_data;

typedef struct s_complex
{
	double	x;
	double	y;
	int		iter;
}				t_complex;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	pix_adr;
}			t_pixel;

typedef struct s_cubic
{
	double	x[6];
	double	y[6];
	double	d[6];
	double	m[6];
}			t_cubic;

typedef struct s_hermite
{
	double	h00;
	double	h10;
	double	h01;
	double	h11;
}			t_hermite;

//parse
t_data		ft_parse(int argc, char **argv, t_data data);
int			ft_draw_fract(t_data *data);
t_fract		ft_init_palettes(t_data data, t_fract fract);
//init
t_fract		ft_init_mandel(t_data data, t_fract t_mandel, void *mlx);
//mandel algo
int			ft_draw_mandel(t_data *data);
int			ft_get_mandel_iter(int pixelx, int pixely, \
	int max_iter, t_data data);
int			ft_mandel_get_color(int iteration, t_data data);
int			ft_cardio_check(double x, double y);
int			ft_get_iter(t_pixel pixel, t_data data);
//print pixel
void		ft_color_pixel(int color, int pixel, char *buffer);
void		ft_display_pixel(t_pixel pixel, char *s);
double		ft_get_smooth_iter(t_pixel pixel, t_data data);
double		ft_smoothen_iter(t_complex escape, t_data data);

//rectangle check
void		ft_check_rectangle(t_pixel up_left, \
	t_pixel down_right, int max_iter, t_data data);
void		ft_color_inside_black(t_pixel up_left, \
	t_pixel down_right, t_data data);
void		ft_color_inside(t_pixel up_left, \
	t_pixel down_right, int max_iter, t_data data);
int			ft_draw_mandel_rectangle(t_data *data);

//smooth algo
double		ft_get_smooth_mandel_iter(t_pixel pixel, t_data data);
int			ft_get_smooth_color(double iter, t_data data);
int			ft_draw_smooth_mandel(t_data *data);
void		ft_check_srectangle(t_pixel up_left, \
	t_pixel down_right, int max_iter, t_data data);
void		ft_color_smooth_inside(t_pixel up_left, \
	t_pixel down_right, int max_iter, t_data data);
//cubic interpol
void		ft_init_xpoint(t_cubic *t_color);
void		ft_get_delta(t_cubic *t_color);
void		ft_get_m(t_cubic *t_color);
void		ft_rescale(t_cubic *t_color);
void		ft_get_hermite(double t, t_hermite *t_h);
double		ft_interpol_val(double x, t_cubic color);
int			*ft_cubic_first_palette(int size);
int			*ft_cubic_scd_palette(int size);
int			*ft_cubic_thrd_palette(int size);
int			*ft_cubic_fourth_palette(int size);
//julia
double		ft_get_smooth_julia_iter(t_pixel pixel, t_data data);
t_fract		ft_init_julia(t_data data, t_fract t_julia, double x, double y);
int			ft_draw_julia(t_data *data);
//ship
double		ft_get_smooth_ship_iter(t_pixel pixel, t_data data);
int			ft_get_ship_iter(t_pixel pixel, t_data data);
int			ft_draw_ship(t_data *data);
t_fract		ft_init_ship(t_data data, t_fract t_ship, void *mlx);
t_complex	ft_ship_iter(t_pixel pixel, t_data data);
//hooks
int			ft_key_input(int key, t_data *data);
int			ft_mouse_input(int button, int x, int y, t_fract *fract);
int			ft_destroy(t_data *data);
void		ft_palette_error(t_data data, int *p1, int *p2, int *p3);
//colors
int			ft_gray(int iteration, int max_iter);
int			ft_interpol(int iteration, int max_iter);
int			ft_get_palette(int iter);
int			ft_get_first_palette(int iter, t_data data);
int			ft_simple_color(int iter);
//smooth color
int			ft_interpolate(double iter);
int			ft_sine_color(double iter, int iter_max);
int			ft_first_palette(double iter, t_data data);
int			ft_scd_palette(double iter, t_data data);
int			ft_thrd_palette(double iter, t_data data);
int			ft_fourth_palette(double iter, t_data data);
#endif
