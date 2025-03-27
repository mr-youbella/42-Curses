/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youbella <youbella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:57:21 by youbella          #+#    #+#             */
/*   Updated: 2025/03/20 10:11:48 by youbella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*p;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	p = ft_calloc(len + 1, 1);
	if (!p)
		return (NULL);
	while (i < len)
		p[i++] = s[start++];
	return (p);
}
