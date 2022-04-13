/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:39:29 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/12 22:19:31 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*create_stacks(void)
{
	t_stacks	*temp;
	t_stack		*stack_a;
	t_stack		*stack_b;

	temp = malloc(sizeof(*temp));
	temp->stack_a = malloc(sizeof(*stack_a));
	temp->stack_b = malloc(sizeof(*stack_b));
	temp->stack_b->head = NULL;
	temp->stack_b->tail = NULL;
	if (temp == NULL || temp->stack_a == NULL || temp->stack_b == NULL)
		error();
	return (temp);
}

void	free_stacks(t_stacks *stacks)
{
	node_deletion(stacks->stack_a);
	node_deletion(stacks->stack_b);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}
