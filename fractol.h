/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:08:16 by olaktion          #+#    #+#             */
/*   Updated: 2018/08/28 19:08:49 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include "libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"
# define WIDTH 800

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			fract;
	int			color;
	int			julia_mouse;
	double		zoom;
	double		it_max;
	double		x1;
	double		y1;
	double		x;
	double		y;
	double		y_max;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		it;
	double		tmp;
	double		x2;
	double		y2;
}				t_fractol;

int				key_hook(int keycode, t_fractol *data);
int				key_hook2(int keycode, t_fractol *data);
void			zoom(int x, int y, t_fractol *data);
void			unzoom(t_fractol *data);
int				mouse_hook(int mousecode, int x, int y, t_fractol *data);

void			mandelbrot_init(t_fractol *data);
void			mandelbrot_calculation(t_fractol *data);
void			*mandelbrot(void *tab);
void			mandelbrot_pthread(t_fractol *data);

int				julia_mo(int x, int y, t_fractol *data);
void			julia_init(t_fractol *data);
void			julia_calculation(t_fractol *data);
void			*julia(void *tab);
void			julia_pthread(t_fractol *data);

void			bship_init(t_fractol *data);
void			bship_calculation(t_fractol *data);
void			*bship(void *tab);
void			bship_pthread(t_fractol *data);

int				ft_close(void);
void			put_pxl_to_img(t_fractol *data, int x, int y, int color);

void			fract_calculatulation(t_fractol *data);
void			fract_init(t_fractol *data);
void			mlx_win_init(t_fractol *data);
int				fract_comp(char **av, t_fractol *data);
#endif
