/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woosekim <woosekim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:44:13 by woosekim          #+#    #+#             */
/*   Updated: 2022/12/06 17:23:37 by woosekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*cuc_s = s;
	unsigned char			uc_c;
	size_t					i;

	uc_c = c;
	i = 0;
	while (i < n)
	{
		if (cuc_s[i] == uc_c)
			return ((void *)(cuc_s + i));
		i++;
	}
	return (0);
}
