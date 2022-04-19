/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:14:13 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/19 18:24:05 by cemenjiv         ###   ########.fr       */
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
