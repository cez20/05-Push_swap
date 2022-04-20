/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:39:29 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/19 16:56:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*create_stacks(void)
{
	t_stacks	*stacks;
	t_stack		*stack_a;
	t_stack		*stack_b;

	stacks = malloc(sizeof(*stacks));
	stacks->stack_a = malloc(sizeof(*stack_a));
	stacks->stack_b = malloc(sizeof(*stack_b));
	stacks->stack_b->head = NULL;
	stacks->stack_b->tail = NULL;
	if (stacks == NULL || stacks->stack_a == NULL || stacks->stack_b == NULL)
		error();
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	node_deletion(stacks->stack_a);
	node_deletion(stacks->stack_b);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}
