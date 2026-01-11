/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:27:25 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/26 12:13:12 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	l_src;
	size_t	l_dst;
	size_t	i;

	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	l_src = ft_strlen(src);
	l_dst = ft_strlen(dst);
	if (l_dst >= dstsize)
		return (dstsize + l_src);
	while (src[i] && i + l_dst < dstsize - 1)
	{
		dst[l_dst + i] = src[i];
		i++;
	}
	dst[l_dst + i] = '\0';
	return (l_src + l_dst);
}
// int main()
// {     
// char dst[] = "kj";
// char src[]= "jhdkjaz";
// printf("%zu",ft_strlcat(NULL,"srhfgc",0)); // seg fault
// printf("\n\n\n%zu",strlcat(NULL,"srhfgc",0)); // 
// }
