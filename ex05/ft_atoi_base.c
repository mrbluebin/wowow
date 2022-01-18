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

int	check_base_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == ' ' || base[i] == '-' || base[i] == '+' || \
			(base[i] >= 9 && base[i] <= 13))
			return (0);
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int len;
	int str_len;
	int num;
	int i;
	int j;
	int mult;

	if (!(len = check_base_error(base)))
		return (0);
	str_len = 0;
	while (str[str_len++]);
	num = 0;
	str_len--;
	i = str_len - 1;
	mult = 1;
	while (i > -1)
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				num = num + (mult * (j));
				break;
			}
			j++;
		}
		i--;
		mult *= len;
	}
	return (num);
	
}

int	main(void)
{
	char a[50] = "2021";
	char b[50] = "012";
	printf("%d",ft_atoi_base(a,b));
}
