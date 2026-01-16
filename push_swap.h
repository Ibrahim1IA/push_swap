/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:13:12 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/16 03:03:37 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdbool.h>
# include <limits.h>
typedef struct s_stack_node
{
	int	nbr;
	int index;
	int push_cost;
	bool above_median;
	bool cheapest;
	struct s_stack_node *next;
	struct s_stack_node *prev;
	struct s_stack_node *target_node;
}	t_stack_node;

void    ra(t_stack_node **a, bool print);
void    rb(t_stack_node **b, bool print);
void	sa(t_stack_node **a, bool print);
void	sb(t_stack_node **b, bool print);
void    rra(t_stack_node **a, bool print);
void    rrb(t_stack_node **b, bool print);
void	ss(t_stack_node **a, t_stack_node **b, bool print);
void	pa(t_stack_node **a, t_stack_node **b, bool print);
void	pb(t_stack_node **a, t_stack_node **b, bool print);
void    rr(t_stack_node **a, t_stack_node **b, bool print);
void    rrr(t_stack_node **a, t_stack_node **b, bool print);

void    three_sort(t_stack_node **a);
void    sort_stack(t_stack_node **a, t_stack_node **b);

int	stack_lenght(t_stack_node *s);
bool	stack_sorted(t_stack_node *s);
t_stack_node    *find_min(t_stack_node *s);
t_stack_node    *find_max(t_stack_node *s);
t_stack_node    *find_last(t_stack_node *s);
t_stack_node    *get_cheapest(t_stack_node *stack);

void    init_stack_a(t_stack_node **a, char **av);
void    bring_on_top(t_stack_node **stack, t_stack_node *top, bool i);
void    set_cheapest(t_stack_node *stack);
void	refresh_index(t_stack_node *stack);
void	init_a(t_stack_node *a, t_stack_node *b);



#endif