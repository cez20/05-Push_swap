/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:45:01 by cezmenji          #+#    #+#             */
/*   Updated: 2022/04/19 18:20:38 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(int len, t_node *lst)
{
	t_node	*temp;
	t_node	*smallest;
	int		index;

	index = 1;
	while (index <= len)
	{
		temp = lst;
		while (temp->index != 0)
			temp = temp->next;
		smallest = temp;
		while (temp != NULL)
		{
			if (smallest->data > temp->data && temp->index == 0)
				smallest = temp;
			temp = temp->next;
		}
		smallest->index = index;
		index++;
	}
}

int	is_sorted(t_node *node)
{
	if (node->index != 1)
		return (0);
	while (node->next)
	{
		if (node->data < node->next->data)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	c;
	int	swap;

	i = 0;
	c = 0;
	while (c < size)
	{
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
		i = 0;
		c++;
	}
}

int	find_median(t_stacks *s, int len)
{
	t_node	*temp;
	int		temp_stack[500];
	int		i;
	int		median;

	i = 0;
	temp = s->stack_b->head;
	while (temp)
	{
		temp_stack[i++] = temp->index;
		temp = temp->next;
	}
	temp_stack[i] = '\0';
	bubble_sort(temp_stack, len);
	median = temp_stack[len / 2];
	return (median);
}

void	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}
