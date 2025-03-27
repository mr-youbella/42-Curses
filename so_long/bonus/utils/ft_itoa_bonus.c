/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 23:58:38 by youbella          #+#    #+#             */
/*   Updated: 2025/03/20 10:11:15 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

static int	ft_digit(int n)
{
	int	d;

	d = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		d++;
	}
	return (d);
}

char	*ft_itoa(int n)
{
	int		digit;
	char	*p;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	digit = ft_digit(n);
	if (n < 0)
		digit++;
	p = ft_calloc(digit + 1, 1);
	if (!p)
		return (NULL);
	if (n < 0)
	{
		p[0] = '-';
		n *= -1;
	}
	digit--;
	while (digit >= 0)
	{
		if (p[digit] == '-')
			break ;
		p[digit--] = (n % 10) + 48;
		n /= 10;
	}
	return (p);
}
