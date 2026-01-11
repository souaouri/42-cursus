/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:55:36 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/20 13:06:41 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*s;
	unsigned char		*b;

	b = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len--)
	{
		b[len] = s[len];
	}
	return (dst);
}
// int main()
// {
//     char x[40] = "is a goat";
//     printf("%s",ft_memmove(&x[4],x,20));

//     printf("%s",memmove(&x[4],x,20));
//     return (0);
// }
