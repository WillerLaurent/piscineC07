/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:10:32 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/30 13:50:00 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_charset(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_count_words(char *str, char *charset)
{
	int i;
	int nb_words;

	i = 0;
	nb_words = 0;
	while (str[i])
	{
		while (ft_is_charset(charset, str[i]) && str[i])
			i++;
		if (!ft_is_charset(charset, str[i]) && str[i])
		{
			nb_words++;
			while (!ft_is_charset(charset, str[i]) && str[i])
			{
				i++;
			}
		}
	}
	return (nb_words);
}

char	*ft_make_strings(char *str, char *charset, int count)
{
	int		i;
	int		j;
	int		size;
	char	*rtn;

	i = count;
	size = 0;
	while (!ft_is_charset(charset, str[i]) && str[i])
	{
		size++;
		i++;
	}
	if (!(rtn = malloc((size + 1) * sizeof(char))))
		return (0);
	j = 0;
	i = count;
	while (j < size)
	{
		rtn[j] = str[i];
		j++;
		i++;
	}
	rtn[size] = 0;
	return (rtn);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		nb_words;
	char	**tab_str;

	nb_words = ft_count_words(str, charset);
	if (!(tab_str = malloc((nb_words + 1) * sizeof(char*))))
		return (0);
	tab_str[nb_words] = 0;
	i = 0;
	j = 0;
	while (str[j])
	{
		while (ft_is_charset(charset, str[j]) && str[j])
			j++;
		if (!ft_is_charset(charset, str[j]) && str[j])
		{
			tab_str[i] = ft_make_strings(str, charset, j);
			i++;
			while (!ft_is_charset(charset, str[j]) && str[j])
				j++;
		}
	}
	return (tab_str);
}
