/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 21:13:12 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/01 22:49:27 by iissoufo         ###   ########.fr       */
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


#endif