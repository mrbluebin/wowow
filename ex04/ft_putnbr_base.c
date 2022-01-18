/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanbpar <chanbpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:37:06 by chanbpar          #+#    #+#             */
/*   Updated: 2022/01/18 13:35:15 by chanbpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

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
int	check_same(int len, char *base)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
void	re_print(int nbr, int len, char *base)
{
	if (nbr == 0)
		return ;
	re_print(nbr / len, len, base);
	write(1, &base[nbr % len], 1);
}
void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long long	num;
	num = nbr;
	len = get_base(base);
	if (len <= 1)
		return ;
	if (check_same(len, base))
		return ;
	if (num < 0)
	{
		write(1, "-", 1);
		num = num * -1;
	}
	re_print(num / len, len, base);
	write(1, &base[num % len], 1);
}