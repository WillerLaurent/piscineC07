/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 11:24:04 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/30 14:05:42 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_mk_final_str(char **strs, char *str_fin, int sz, char *sep)
{
	int i;

	i = 0;
	while (i < sz - 1)
	{
		str_fin = ft_strcat(str_fin, strs[i]);
		str_fin = ft_strcat(str_fin, sep);
		i++;
	}
	str_fin = ft_strcat(str_fin, strs[i]);
	return (str_fin);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str_finale;
	int		i;
	int		size_str_finale;

	i = -1;
	size_str_finale = 0;
	if (size == 0)
	{
		if (!(str_finale = malloc(1 * sizeof(char))))
			return (0);
		str_finale[0] = '\0';
		return (str_finale);
	}
	if (size < 0)
		return (0);
	while (++i < size)
		size_str_finale += ft_strlen(strs[i]) + ft_strlen(sep);
	size_str_finale = size_str_finale - ft_strlen(sep);
	if (!(str_finale = malloc(size_str_finale * sizeof(char))))
		return (0);
	str_finale[0] = '\0';
	str_finale = ft_mk_final_str(strs, str_finale, size, sep);
	return (str_finale);
}
