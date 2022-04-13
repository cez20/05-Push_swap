/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:45:01 by cezmenji          #+#    #+#             */
/*   Updated: 2022/04/12 23:34:04 by cemenjiv         ###   ########.fr       */
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

void	print_node(t_node *head)
{
	int	i;

	i = 1;
	printf("NUMBERS		INDEX\n");
	while (head != NULL)
	{
		printf("%d		[%d]\n", head->data, head->index);
		head = head->next;
		i++;
	}
	printf("\n");
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

void	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit (EXIT_FAILURE);
}
