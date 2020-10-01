/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 15:40:49 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/28 14:55:56 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_test_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
			c == ' ')
		return (1);
	return (0);
}

int		ft_test_base(char *base)
{
	int i;
	int j;
	int ln_base;

	i = 0;
	j = i + 1;
	ln_base = ft_strlen(base);
	if (ln_base < 2)
		return (0);
	while (i < ln_base)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		if (ft_test_whitespace(base[i]))
			return (0);
		while (j < ln_base)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

char	*ft_iota_base_2(int count, int nb, char *rtn, char *base)
{
	unsigned int a;
	unsigned int ln_bs;

	ln_bs = ft_strlen(base);
	a = (nb >= 0) ? nb : nb * (-1);
	count--;
	rtn[count] = '\0';
	count--;
	while (count >= 0)
	{
		rtn[count] = base[a % ln_bs];
		a = a / ln_bs;
		count--;
		if (nb < 0)
			rtn[0] = '-';
	}
	return (rtn);
}
