/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:27:32 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/12 21:35:38 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	t_node	*temp;

	if (stack->head && stack->tail)
	{	
		temp = stack->head->next;
		stack->head->next = temp->next;
		stack->head->prev = temp;
		temp->prev = NULL;
		if (temp->next)
			temp->next->prev = stack->head;
		temp->next = stack->head;
		stack->head = temp;
		if (stack->tail->data == stack->head->data)
			stack->tail = stack->head->next;
		write (1, "sa\n", 3);
	}
}

void	rotate_a(t_stack *stack)
{
	t_node	*temp;

	if (stack->head && stack->tail)
	{	
		temp = stack->head->next;
		temp->prev = NULL;
		stack->head->next = NULL;
		stack->head->prev = stack->tail;
		stack->tail->next = stack->head;
		stack->tail = stack->head;
		stack->head = temp;
		write (1, "ra\n", 3);
	}
}

void	reverse_rotate_a(t_stack *stack)
{
	t_node	*temp;

	if (stack->head && stack->tail)
	{
		temp = stack->tail->prev;
		temp->next = NULL;
		stack->tail->next = stack->head;
		stack->head->prev = stack->tail;
		stack->head = stack->tail;
		stack->tail = temp;
		write (1, "rra\n", 4);
	}
}

void	push_a(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*temp;

	temp = stack_a->head;
	if (!stack_a->head)
	{
		temp = stack_b->head->next;
		stack_a->head = stack_b->head;
		stack_a->tail = stack_a->head;
		stack_a->head->next = NULL;
		stack_b->head = temp;
	}	
	else if (stack_b->head != NULL)
	{
		stack_a->head->prev = stack_b->head;
		stack_a->head = stack_b->head;
		stack_b->head = stack_a->head->next;
		stack_a->head->next = temp;
		stack_a->head->prev = NULL;
	}
	write(1, "pa\n", 3);
}
