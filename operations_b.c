/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:06:20 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/12 21:35:43 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *stack)
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
		write (1, "sb\n", 3);
	}
}

void	rotate_b(t_stack *stack)
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
		write (1, "rb\n", 3);
	}
}

void	reverse_rotate_b(t_stack *stack)
{
	t_node	*temp;

	if (stack->head != stack->tail && stack->head && stack->tail)
	{
		temp = stack->tail->prev;
		temp->next = NULL;
		stack->tail->next = stack->head;
		stack->head->prev = stack->tail;
		stack->head = stack->tail;
		stack->tail = temp;
		write (1, "rrb\n", 4);
	}
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a->head)
		return ;
	temp = stack_a->head->next;
	if (!stack_b->head)
	{
		stack_a->head->next = NULL;
		stack_b->head = stack_a->head;
		stack_b->tail = stack_b->head;
		stack_b->head->prev = NULL;
	}
	else
	{
		stack_a->head->next = stack_b->head;
		stack_b->head->prev = stack_a->head;
		stack_b->head = stack_a->head;
		stack_b->head->prev = NULL;
	}
	stack_a->head = temp;
	write(1, "pb\n", 3);
}
