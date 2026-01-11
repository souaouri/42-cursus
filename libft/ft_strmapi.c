/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:40:28 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/27 21:39:00 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	ptr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
// char jbb(unsigned int i,char c)
// {	

// 		c += i;
// 	return (c);
// }
// int main ()
// {
// 	char (*f)(unsigned int, char);
// 	f = &jbb;
// 	char *h = "solimi";
// 	printf ("%s\n", ft_strmapi(h,f));
// }
