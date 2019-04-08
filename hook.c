/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:08:27 by olaktion          #+#    #+#             */
/*   Updated: 2018/08/28 18:08:28 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook2(int keycode, t_fractol *data)
{
	if (keycode == 19)
		data->color = 2050;
	else if (keycode == 20)
		data->color = 265;
	else if (keycode == 35)
	{
		if (data->julia_mouse == 1)
			data->julia_mouse = 0;
		else
			data->julia_mouse = 1;
	}
	return (0);
}

int		key_hook(int keycode, t_fractol *data)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69)
		data->it_max++;
	else if (keycode == 78)
		data->it_max--;
	else if (keycode == 123)
		data->x1 -= 30 / data->zoom;
	else if (keycode == 124)
		data->x1 += 30 / data->zoom;
	else if (keycode == 125)
		data->y1 += 30 / data->zoom;
	else if (keycode == 126)
		data->y1 -= 30 / data->zoom;
	else if (keycode == 49)
		fract_init(data);
	else if (keycode == 18)
		data->color = 1677216;
	key_hook2(keycode, data);
	fract_calculatulation(data);
	return (0);
}

void	zoom(int x, int y, t_fractol *data)
{
	data->x2 = x;
	data->y2 = y;
	data->x1 = (x / data->zoom + data->x1) - ((data->zoom * 1.3) / 2);
	data->x1 += ((data->zoom * 1.3) / 2) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - ((data->zoom * 1.3) / 2);
	data->y1 += ((data->zoom * 1.3) / 2) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->it_max++;
}

void	unzoom(t_fractol *data)
{
	data->x1 = (data->x2 / data->zoom + data->x1) - ((data->zoom / 1.3) / 2);
	data->x1 += ((data->zoom / 1.3) / 2) - (data->x2 / (data->zoom / 1.3));
	data->y1 = (data->y2 / data->zoom + data->y1) - ((data->zoom / 1.3) / 2);
	data->y1 += ((data->zoom / 1.3) / 2) - (data->y2 / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->it_max--;
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *data)
{
	if (mousecode == 4 || mousecode == 1)
		zoom(x, y, data);
	else if (mousecode == 5 || mousecode == 2)
		unzoom(data);
	fract_calculatulation(data);
	return (0);
}
