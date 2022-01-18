/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanbpar <chanbpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:53:17 by chanbpar          #+#    #+#             */
/*   Updated: 2022/01/18 18:00:04 by chanbpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>

int g_num = 0;

int	check_one(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '-' || str[index] == '+' || str[index] == ' ' || \
				(str[index] >= 9 && str[index] <= 13))
		{
			return (1);
		}
		index++;
	}
	return (0);
}

int	check_same(char *base)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	while (base[index])
		index++;
	i = 0;
	j = 0;
	while (base[i] != base[index])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi(char *str, char *base, int baselen)
{
	int	index;
	int	neg;
	int	num;
	int j;
	int mult;

	neg = 1;
	index = 0;
	num = 0;
	mult = 1;
	while ((str[index] == ' ' || (str[index] >= 9 && str[index] <= 13)))
	{
		index++;
	}
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			neg = -neg;
		index++;
	}
	printf("%s",str);
	while (str[index])
	{
		j = baselen - 1;
		while (base[j] && j > -1)
		{
			if (str[index] == base[j])
			{
				num = num + (1 * mult * (baselen - j)) ;
				break;
			}
			j--;
		}
		index++;
		mult = mult * baselen;
	}
	return (num * neg);
}

int	get_base(char *base)
{
	int	len;

	len = 0;
	while (base[len])
	{
		if (base[len] == '-' || base[len] == '+')
			return (0);
		len++;
	}
	return (len);
}

void	re_print(int nbr, int len, char *base)
{
	if (nbr == 0)
		return ;
	re_print(nbr / len, len, base);
	g_num = ((g_num * 10) + (base[nbr % len] - '0'));
}

int	ft_atoi_base(char *str, char *base)
{
	int len;
	len = get_base(base);
	return (ft_atoi(str, base, len));	
}

int	main(void)
{
	char a[50] = "2021";
	char b[50] = "012";
	printf("%d", ft_atoi_base(a, b));
}