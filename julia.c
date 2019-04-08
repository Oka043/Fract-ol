/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:08:35 by olaktion          #+#    #+#             */
/*   Updated: 2018/08/28 18:08:37 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia_mo(int x, int y, t_fractol *data)
{
	if (data->fract == 1 && data->julia_mouse == 1)
	{
		data->c_r = x * 2;
		data->c_i = y * 2 - 800;
		fract_calculatulation(data);
	}
	return (0);
}

void	julia_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = 200;
	data->x1 = -2.0;
	data->y1 = -1.9;
	data->color = 222;
	data->c_r = 0.285;
	data->c_i = 0.01;
	data->julia_mouse = 1;
}

void	julia_calculation(t_fractol *data)
{
	data->z_r = data->x / data->zoom + data->x1;
	data->z_i = data->y / data->zoom + data->y1;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i
			* data->z_i < 4 && data->it < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r -
			data->z_i * data->z_i - 0.8 + (data->c_r / WIDTH);
		data->z_i = 2 * data->z_i * data->tmp + data->c_i / WIDTH;
		data->it++;
	}
	if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, 0x000000);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}

void	*julia(void *tab)
{
	double		tmp;
	t_fractol	*data;

	data = (t_fractol *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			julia_calculation(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	julia_pthread(t_fractol *data)
{
	t_fractol	tab[8];
	pthread_t	t[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_fractol));
		tab[i].y = 100 * i;
		tab[i].y_max = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 8)
		pthread_create(&t[i - 1], NULL, julia, &tab[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
