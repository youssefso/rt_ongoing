/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:01:19 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/10/18 23:50:56 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t t;

	i = 0;
	j = 0;
	i = ft_strlen(src);
	j = ft_strlen(dst);
	t = i + j;
	if (j > size)
		return (i + size);
	while (*src && j < size - 1)
		dst[j++] = *src++;
	dst[j] = '\0';
	return (t);
}
