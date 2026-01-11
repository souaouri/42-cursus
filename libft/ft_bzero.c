/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:17:55 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/20 11:10:47 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// int main()
// {
// 	char str[1100] = "solimisolimi";
// 	ft_bzero(str,9);
// 	printf("%s", str);
// 	printf("\n\n\n\n%s", bzero(str,50));
// 	return (0);
// }
