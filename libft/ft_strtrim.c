/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:39:59 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/26 21:41:14 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char const c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr; 
	size_t	start;
	size_t	end;

	if (!*s1)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	if (s1[0] == '\0')
	{
		end = 0;
		start += 1;
	}
	while (start < end && s1[start] && ft_check(s1[start], set))
		start++;
	while (end >= start && s1[end] && ft_check(s1[end], set))
		end--;
	ptr = malloc(end - start + 2);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], end - start + 2);
	return (ptr);
}
// int main ()
// {

// 	char	*v = "";
// 	char	*s = "";
// 	printf("%s",ft_strtrim(v,s));
// 	return (0);
// }