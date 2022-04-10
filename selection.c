/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:24:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/10 13:05:55 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stacks *s, int len)
{
	int	small;
	int	nb_location;

	while (len > 3)
	{
		small = smallest_nb(s->stack_a);
		nb_location = which_half(s->stack_a, small);
		while (s->stack_a->head->pos != small)
		{
			if (nb_location <= (len / 2))
				rotate_a(s->stack_a);
			else if (nb_location >= (len / 2))
				reverse_rotate_a(s->stack_a);
			if (is_sorted(s->stack_a->head) == 1)
				return ;
		}
		push_b(s->stack_a, s->stack_b);
		len--;
	}
	simple_sort(s);
	while (s->stack_b->head != NULL)
		push_a(s->stack_b, s->stack_a);
}

void	simple_sort(t_stacks *s)
{
	int	big;
	int	small;

	small = smallest_nb(s->stack_a);
	big = biggest_nb(s->stack_a);
	if (s->stack_a->head->pos == big)
		rotate_a(s->stack_a);
	else if (s->stack_a->head->next->pos == big)
		reverse_rotate_a(s->stack_a);
	if (s->stack_a->head->next->pos == small && s->stack_a->tail->pos == big)
		swap_a(s->stack_a);
}

int	which_half(t_stack *stack, int small)
{
	t_dlist	*temp;
	int		count;

	temp = stack->head;
	count = 1;
	while (temp->pos != small)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int	smallest_nb(t_stack *stack)
{
	t_dlist	*temp;
	int		small;

	temp = stack->head;
	small = stack->head->pos;
	while (temp)
	{
		if (small > temp->pos)
			small = temp->pos;
		temp = temp->next;
	}
	return (small);
}

int	biggest_nb(t_stack *stack)
{
	t_dlist	*temp;
	int		big;

	temp = stack->head;
	big = stack->head->pos;
	while (temp)
	{
		if (big < temp->pos)
			big = temp->pos;
		temp = temp->next;
	}
	return (big);
}
