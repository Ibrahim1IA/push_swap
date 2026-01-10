/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:13:12 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/10 18:41:16 by iissoufo         ###   ########.fr       */
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

void    ra(t_stack_node **a);
void    rb(t_stack_node **b);
void	sa(t_stack_node **a);
void	sb(t_stack_node **b);
void    rra(t_stack_node **a);
void    rrb(t_stack_node **b);
void	ss(t_stack_node **a, t_stack_node **b);
void	pa(t_stack_node **a, t_stack_node **b);
void	pb(t_stack_node **a, t_stack_node **b);
void    rr(t_stack_node **a, t_stack_node **b);
void    rrr(t_stack_node **a, t_stack_node **b);

int	stack_lenght(t_stack_node *s);
bool	stack_sorted(t_stack_node *s);
t_stack_node    *find_min(t_stack_node *s);
t_stack_node    *find_max(t_stack_node *s);
t_stack_node    *find_last(t_stack_node *s);

void    init_stack_a(t_stack_node **a, char **av);


#endif