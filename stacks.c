/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:39:29 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/15 10:25:03 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*initialize_stacks(void)
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

void	clear_stacks(t_stacks *stacks)
{
	dlst_clear(stacks->stack_a);
	dlst_clear(stacks->stack_b);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}
