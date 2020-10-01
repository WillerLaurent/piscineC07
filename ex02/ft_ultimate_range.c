/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:58:44 by lwiller           #+#    #+#             */
/*   Updated: 2020/10/01 11:26:57 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long	i;
	long	ln;
	int		*tab;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	ln = max - min;
	if (!(tab = malloc(sizeof(int) * ln)))
		return (-1);
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return ((int)ln);
}
