/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 03:56:45 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/11/07 23:55:45 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*sp;

	s = (char *)dst;
	sp = (char *)src;
	while (n--)
		*s++ = *sp++;
	return (dst);
}
