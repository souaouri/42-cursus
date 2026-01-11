/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:00:28 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/25 19:02:03 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void	*src, size_t	n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	d = dst;
	s = src;
	i = 0;
	if (d == NULL && s == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
//  int main()
//  {
//  	char src[] = "hello world";
//  	char dest[] = "hsdjejh";
//  	printf("%s\n\n\n\n", memcpy(NULL,NULL,7));
//  	printf("%s",ft_memcpy(NULL,NULL,7));
//  }
