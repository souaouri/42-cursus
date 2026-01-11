/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:56:03 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/20 13:00:31 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*b;
	size_t	i;

	i = 0;
	b = (char *)s;
	while (i < n)
	{
		if ((char)b[i] == (char)c)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
// int main()
// {
//     char *v = "solimi is a goat";
//    	printf("%s\n\n\n\n", memchr(v,'a',12));
//     printf("%s",ft_memchr(v,'a',12));
// }
