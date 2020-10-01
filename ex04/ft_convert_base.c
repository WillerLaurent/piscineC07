/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:50:26 by lwiller           #+#    #+#             */
/*   Updated: 2020/10/01 09:49:58 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_test_whitespace(char c);
int		ft_test_base(char *base);
char	*ft_iota_base_2(int count, int nb, char *rtn, char *base);

int		ft_convert(char *str, int i, char *base)
{
	int j;
	int rtn;
	int ln_bs;

	rtn = 0;
	ln_bs = ft_strlen(base);
	while (str[i])
	{
		j = 0;
		while ((str[i] != base[j]))
		{
			j++;
			if (j > ln_bs)
				return (rtn);
		}
		rtn = (rtn * ln_bs) + j;
		i++;
	}
	return (rtn);
}

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int i;
	int rtn;

	i = 0;
	sign = 1;
	if (!ft_test_base(base))
	{
		return (0);
	}
	while (ft_test_whitespace(str[i]))
	{
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	rtn = ft_convert(str, i, base);
	return (rtn * sign);
}

char	*ft_iota_base(int nb, char *base)
{
	int				count;
	char			*rtn;
	unsigned int	ln_bs;
	unsigned int	a;

	count = 0;
	ln_bs = ft_strlen(base);
	if (!ft_test_base(base))
		return (0);
	a = (nb >= 0) ? nb : nb * (-1);
	count = (nb >= 0) ? 2 : 3;
	while (a > ln_bs - 1)
	{
		a = a / ln_bs;
		count++;
	}
	if (!(rtn = malloc(count * sizeof(char))))
		return (0);
	rtn = ft_iota_base_2(count, nb, rtn, base);
	return (rtn);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*rtn;

	if (!ft_test_base(base_from))
		return (NULL);
	if (!ft_test_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	rtn = ft_iota_base(nb, base_to);
	return (rtn);
}
