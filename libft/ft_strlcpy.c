/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:45:58 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/11 19:34:29 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	i = 0;
	if (dstsize != 0)
	{
		while (src[i] && --dstsize > 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}
// int	main (void)
// {
// 	char t[22];
// 	printf("al asel : %zu\n\n\n\n",strlcpy(t, "aaa", 3));
// 	printf ("num ; %s\n\n\n\n",t);
//
// 	printf("return of ft_strlcpy : %zu\n",ft_strlcpy(t, "aaa", 3));
// 	return (0);
// }
