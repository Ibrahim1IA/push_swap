#include "checker_bonus.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	execute_command(char *command, t_stack_node **a, t_stack_node **b)
{
	if (ft_strcmp(command, "sa") == 0)
		sa(a, 1);
	else if (ft_strcmp(command, "sb") == 0)
		sb(b, 1);
	else if (ft_strcmp(command, "ss") == 0)
		ss(a, b, 1);
	else if (ft_strcmp(command, "pa") == 0)
		pa(a, b, 1);
	else if (ft_strcmp(command, "pb") == 0)
		pb(a, b, 1);
	else if (ft_strcmp(command, "ra") == 0)
		ra(a, 1);
	else if (ft_strcmp(command, "rb") == 0)
		rb(b, 1);
	else if (ft_strcmp(command, "rr") == 0)
		rr(a, b, 1);
	else if (ft_strcmp(command, "rra") == 0)
		rra(a, 1);
	else if (ft_strcmp(command, "rrb") == 0)
		rrb(b, 1);
	else if (ft_strcmp(command, "rrr") == 0)
		rrr(a, b, 1);
	else
		return (0);
	return (1);
}

void	performe_sorting(t_stack_node **a, t_stack_node **b, t_checker *commands)
{
	t_checker	*current;

	current = commands;
	while (current)
	{
		if (!execute_command(current->command, a, b))
		{
			write(2, "Error\n", 6);
			free_stack(a);
			free_stack(b);
			free_checker(commands);
			exit(1);
		}
		current = current->next;
	}
}

static void append_node(t_checker **head, t_checker *new_node)
{
	t_checker	*temp;

	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

void save_command(t_checker **head)
{
	char	*command;
	int		len;
	t_checker	*new_node;

	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		len = ft_strlen(command);
		if (len > 0 && command[len - 1] == '\n')
			command[len - 1] = '\0';
		new_node = (t_checker *)malloc(sizeof(t_checker));
		if (!new_node)
			return;
		new_node->command = ft_strdup(command);
		new_node->next = NULL;
		if (*head == NULL)
			*head = new_node;
		else
			append_node(head, new_node);
		free(command);
	}
}