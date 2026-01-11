/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:10:54 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/26 16:46:55 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t	len)
{
	char	*h;
	size_t	nee;
	size_t	i;
	size_t	j;

	if ((haystack == NULL || needle == NULL) && len == 0)
		return (NULL);
	h = (char *)haystack;
	nee = ft_strlen(needle);
	i = 0;
	if (nee == 0)
		return (h);
	while (h[i])
	{
		j = 0;
		while (h[i + j] && needle[j] && h[i + j] == needle[j] && i + j < len)
			j++;
		if (j == nee)
		{
			return (h + i);
		}
		i++;
	}
	return (0);
}

// int main() 
// {

//     char    *h = "shalkhsia o machi rkhas les winners ga3 classe";
//     char    *n = "machi";
//     printf("\n%s",ft_strnstr(NULL,n,0));
//     printf("\n\n\n\n%s",strnstr(NULL,n,0)); 

//     return (0);
// }
