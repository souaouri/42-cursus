/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:48:35 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/27 14:51:18 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_toupper(int c)
{
	int	i;

	i = c;
	if (c >= 'a' && c <= 'z')
	{
		i -= 32;
	}
	return (i);
}
// int main()
// {
// 	printf("%c",ft_toupper('5'));
// 	printf("\n\n\n\n\n%c",toupper('5'));
// }
