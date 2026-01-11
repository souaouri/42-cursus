/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:54:39 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/27 14:47:42 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str; 

	str = (char *)b;
	while (len > 0)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}
// int main()
// {
// 	int data;
// 	ft_memset((char *)&data, 255,sizeof(data));
// 	ft_memset((char *)&data ,96, 1);
// 	ft_memset((char *)&data + 1 ,240, 1);
// 	printf("%d",data);
// }
