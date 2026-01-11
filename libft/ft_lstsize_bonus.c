/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:49:49 by souaouri          #+#    #+#             */
/*   Updated: 2023/11/27 15:19:06 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++; 
	}
	return (i);
}
// int main()
// {
// 	t_list *head = NULL;

// 	ft_lstadd_back(&head, ft_lstnew("hi 1"));
// 	ft_lstadd_back(&head, ft_lstnew("hi 2"));
// 	ft_lstadd_back(&head, ft_lstnew("hi 3"));
// 	ft_lstadd_back(&head, ft_lstnew("hi 4"));
// 	ft_lstadd_back(&head, ft_lstnew("hi 5"));
// 	ft_lstadd_front(&head, ft_lstnew("hi 0"));
// 	t_list *p = head;
// 	// while (p)
// 	// {
// 	// 	printf("%s\n", p->content);
// 	// 	p =p->next;
// 	// }
// 	t_list *h = ft_lstlast(head);
// 	printf ("%s\n", h->content);

// }