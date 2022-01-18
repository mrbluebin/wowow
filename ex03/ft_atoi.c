/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanbpar <chanbpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:20:11 by chanbpar          #+#    #+#             */
/*   Updated: 2022/01/17 18:00:25 by chanbpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	return (0);
}

int	ft_is_space(char a)
{
	if (a == ' ' || (a >= 9 && a <= 13))
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	index;
	int	neg;
	int	num;

	neg = 1;
	index = 0;
	num = 0;
	while (ft_is_space(str[index]) == 1)
	{
		index++;
	}
	while (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			neg = -neg;
		index++;
	}
	while (ft_isdigit(str[index]) == 1)
		num = (num * 10) + (str[index++] - '0');
	return (num * neg);
}
