/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_maintenance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:14:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/12 22:34:18 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nodes_len(t_node *node)
{
	int	len;

	len = 0;
	if (node)
	{
		len++;
		while (node->next)
		{
			node = node->next;
			len++;
		}
	}
	return (len);
}

void	node_deletion(t_stack *stack)
{	
	t_node	*temp;

	if (stack->head == NULL)
		return ;
	while (stack->head)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
}
