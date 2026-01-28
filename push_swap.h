/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:13:12 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/21 17:58:26 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index[2];
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
}						t_stack_node;

void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **a, t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);

void					three_sort(t_stack_node **a);
void					sort_stack(t_stack_node **a, t_stack_node **b);
int						error_syntax(char *str_n);
int						error_duplicate(t_stack_node *a, int n);
int						verify_args(char **args, char **av);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **a, char **av);
void					free_split_args(char **arr);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strdup(const char *s);
size_t					ft_strlen(const char *s);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);

int						stack_lenght(t_stack_node *s);
bool					stack_sorted(t_stack_node *s);
t_stack_node			*find_min(t_stack_node *s);
t_stack_node			*find_max(t_stack_node *s);
t_stack_node			*find_last(t_stack_node *s);
t_stack_node			*get_cheapest(t_stack_node *stack);

void					parste_and_init(char *str, t_stack_node **a);
void					init_stack_a(t_stack_node **a, char **av);
void					bring_on_top(t_stack_node **stack, t_stack_node *top,
							bool i);
void					set_cheapest(t_stack_node *stack);
void					refresh_index(t_stack_node *stack);
void					init_a(t_stack_node *a, t_stack_node *b);

int						*get_sorted_stack_in_array(t_stack_node *a);
char					**ft_split(char const *s, char c);
void					init_sort_index(t_stack_node *a);

#endif