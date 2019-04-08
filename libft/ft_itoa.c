/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:05:39 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 14:05:42 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_at(char *dst, char *s, int n)
{
	int			i;
	long int	tmp;
	int			cnt;

	i = 0;
	cnt = 0;
	tmp = n;
	if (n < 0)
		tmp = -tmp;
	while (tmp / 10 > 0)
	{
		i = tmp % 10;
		tmp = tmp / 10;
		dst[cnt] = 48 + i;
		cnt++;
	}
	i = tmp % 10;
	dst[cnt++] = 48 + i;
	if (n < 0)
		dst[cnt++] = '-';
	dst[cnt--] = '\0';
	i = 0;
	while (cnt >= 0)
		s[i++] = dst[cnt--];
	s[i] = '\0';
}

static int		ft_cnt(int c)
{
	int i;

	i = 0;
	while (c / 10 > 10)
	{
		i++;
		c = c / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*dst;
	char		*s;
	long int	tmp;
	int			cnt;

	tmp = n;
	cnt = 0;
	if (n < 0)
	{
		tmp = -tmp;
		cnt++;
		cnt = ft_cnt(tmp);
		dst = (char *)malloc(cnt + 1);
		s = (char *)malloc(cnt + 1);
	}
	else
	{
		cnt = ft_cnt(tmp);
		dst = (char *)malloc(cnt + 1);
		s = (char *)malloc(cnt + 1);
	}
	if (dst == 0 && s == 0)
		return (0);
	ft_at(dst, s, n);
	return (s);
}
