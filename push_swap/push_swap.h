/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 07:30:23 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/10 16:49:33 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

typedef struct push_swap
{
	int					content;
	int					index;
	int					position;
	struct push_swap	*next;
}						t_list;

typedef struct utile_var
{
	int		i;
	int		j;
	int		num;
}			t_utile_var;

typedef struct right_hand
{
	int	chunk;
	int	list_size;
	int	num;
	int	devide;
	int	big_index;
	int	se_big_index;
}		t_right_hand;

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *buff);
size_t	ft_strlen(const char *s);
char	*print_the_line(char *line);
char	*rest_line(char *line);
char	*get_the_line(char	*str, int fd);
char	*get_next_line(int fd);
char	*ft_strdup(char *str);

void	sa(t_list **stack_a, int w);
void	sb(t_list **stack_b, int w);
void	ss(t_list **stack_a, t_list **stack_b, int w);
void	pa(t_list **stack_a, t_list **stack_b, int w);
void	pb(t_list **stack_a, t_list **stack_b, int w);
void	ra(t_list **stack_a, int w);
void	rb(t_list **stack_b, int w);
void	rr(t_list **stack_a, t_list **stack_b, int w);
void	rra(t_list **stack_a, int w);
void	rrb(t_list	**stack_b, int w);
void	rrr(t_list **stack_a, t_list **stack_b, int w);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back2(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
char	**ft_split(char	*s, char c);
int		ft_strncmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	ft_error(void);
int		is_sorted(t_list *stack_a);
int		find_biggest(t_list	*stack);
int		find_second_bigest(t_list	*stack);
int		find_smallest(t_list *stack);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	shose_sort(int argc, t_list **stack_a, t_list **stack_b);
int		is_there(t_list *stack_a, int chunk);
void	sort_other(t_list **stack_a, t_list **stack_b, t_right_hand var);
void	ft_help(t_list *stack_a, t_right_hand *var);
int		numbering(t_list *stack_b, int num);
void	push_to_stack_a(t_list **stack_a, t_list **stack_b);
char	*ft_strdup(char *s1);
size_t	ft_strlen(const char *s);
void	tester(t_list	*stack_a);
char	**ft_read(t_list *stack_a, t_list *stack_b);
void	freee(char **spliter);
void	freee_list(t_list	**stack);
void	ft_free_error(t_list	**stack);
int		check_swap(char *line, t_list **stack_a, t_list **stack_b);
int		check_push(char *line, t_list **stack_a, t_list **stack_b);
int		check_rotate(char *line, t_list **stack_a, t_list **stack_b);
int		check_reverse_rotate(char *line, t_list **stack_a, t_list **stack_b);
void	move(t_list **stack_b, int max, int index);
void	who_is_first(t_list **stack_a, t_list **stack_b, \
				t_right_hand helpers, int se_big);
int		there_is_more(t_list *stack_a, int chunk);

#endif