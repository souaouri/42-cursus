/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:19:25 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/16 17:46:24 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void	*s1, const void	*s2, size_t n)
{
	char	*src;
	char	*dst;
	size_t	i;

	i = 0;
	src = (char *)s1;
	dst = (char *)s2;
	while (i < n)
	{
		if (dst[i] != src[i])
			return ((unsigned char)src[i] - (unsigned char)dst[i]);
		i++;
	}
	return (0);
}
// int main ()
// {
//     char *a = "soliml";
//     char *b = "solinj";

//     printf("%d", ft_memcmp(a,b,9));
//     printf("%d", memcmp(a,b,9));

// }
