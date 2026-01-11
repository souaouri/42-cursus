/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:12:31 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/26 17:11:48 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char	*s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			j++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (j);
}

static size_t	count_len(const char	*s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	*free_all(char	**ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const	*s, char c)
{
	char	**ptr;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	size = count_word(s, c);
	i = 0;
	j = 0;
	ptr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ptr)
		return (NULL);
	while (s[j] && size--)
	{
		while (s[j] == c)
			j++;
		ptr[i] = ft_substr(s, j, count_len(&s[j], c));
		if (!ptr[i])
			return (free_all(ptr), NULL);
		j += count_len(&s[j], c);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
//  int main()
// {
//    char string[1000] = "hello! ";
//    char **p;
//    int i;
//
//    i = 0;
//    p =  ft_split(string, 32);
//    while (p[i])
//    {
// 	 printf("%s\n",p[i]);
// 	 i++;
//    }
//    return 0;
// } 
