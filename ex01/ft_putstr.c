/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanbpar <chanbpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:54:48 by chanbpar          #+#    #+#             */
/*   Updated: 2022/01/17 14:58:48 by chanbpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	ft_putstr(char *str)
{
	int		index;
	char	a;

	index = 0;
	while (str[index])
	{
		a = str[index];
		write(1, &a, 1);
		index++;
	}
}
