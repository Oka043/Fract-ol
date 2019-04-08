/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaktion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:44:05 by olaktion          #+#    #+#             */
/*   Updated: 2018/01/03 13:44:09 by olaktion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int n)
{
	int		j;
	char	c;

	c = (char)n;
	j = 0;
	while (str[j])
		j++;
	while (j >= 0)
	{
		if (str[j] != c)
			j--;
		if (str[j] == c)
			return ((char *)str + j);
	}
	return (0);
}
