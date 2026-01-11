/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:10:58 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/26 16:38:42 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	capa;
	char	*ptr;

	capa = count * size;
	ptr = malloc(capa);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, capa);
	return (ptr);
}
// int main() 
// {
// 	printf("%s",ft_calloc(20,5));
// 	printf("\n\n\n\n%s",calloc(20,0));
// }
