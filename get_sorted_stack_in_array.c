/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sorted_stack_in_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 17:30:23 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/18 20:35:49 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    sort_array(int array[], int len)
{
    int i;
    int j;
    int tmp;

    i = 0;
    if (!array)
        return ;
    while (i < len -1)
    {
        j = i + 1;
        while (array[j])
        {
            if (array[i] > array[j])
            {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
            j++;
        }
        i++;
    }
}

static void    init_array(t_stack_node *a, int array[])
{
    int i;

    i = 0;
    while (a)
    {
        array[i] = a->nbr;
        i++;
        a = a->next;
    }
}
int find_index_in_array(int nbr, int *array)
{
    int i;

    i = 0;
    while (array[i] != '\0')
    {
        if (nbr == array[i])
            return (i);
        i++;
    }
    return (i);
}
int *get_sorted_stack_in_array(t_stack_node *a)
{
    int len;
    int *array;
    len = stack_lenght(a);
    array = malloc(sizeof(int)* (len +1));
    if (!array)
        return (NULL);
    array[len] = '\0';
    init_array(a, array);
    sort_array(array, len);
    return (array);
}