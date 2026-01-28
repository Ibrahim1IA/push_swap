#ifndef CHECKER_H
# define CHECKER_H

#include "get_next_line/get_next_line.h"
# include <stdbool.h>
#include <unistd.h>
# include <stdlib.h>
# include <limits.h>

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

typedef struct s_checker
{
	char		*command;
	struct s_checker	*next;
}	t_checker;


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

void					free_checker(t_checker *commands);
void					performe_sorting(t_stack_node **a, t_stack_node **b, t_checker *commands);
void					save_command(t_checker **head);

void					parste_and_init(char *str, t_stack_node **a);
int						verify_args(char **args, char **av);
int						error_syntax(char *str_n);
int						error_duplicate(t_stack_node *a, int n);
int						verify_args(char **args, char **av);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **a, char **av);
void					free_split_args(char **arr);
void					init_stack_a(t_stack_node **a, char **av);
bool					stack_sorted(t_stack_node *s);
char					**ft_split(char const *s, char c);
void					init_sort_index(t_stack_node *a);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strdup(const char *s);
size_t					ft_strlen(const char *s);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);

# endif