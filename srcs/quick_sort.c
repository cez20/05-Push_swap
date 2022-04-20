/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:51:45 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/19 18:24:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stacks *s, int len)
{
	int	median;
	int	top_a;

	top_a = 0;
	first_sort(s, len, &top_a);
	while ((is_sorted(s->stack_a->head) != 1))
	{
		push_chunk(s, &top_a);
		while (s->stack_b->head)
		{
			len = nodes_len(s->stack_b->head);
			median = find_median(s, len);
			while (nodes_len(s->stack_b->head) > (len / 2))
			{
				if (s->stack_b->head->index >= median)
					push_a(s->stack_b, s->stack_a);
				else
					rotate_b(s->stack_b);
			}
			selection_sort1(s, nodes_len(s->stack_b->head));
		}
	}
}

void	first_sort(t_stacks *s, int len, int *top)
{
	while (nodes_len(s->stack_b->head) < (len / 2))
	{
		if (s->stack_a->head->index <= (len / 2))
			push_b(s->stack_a, s->stack_b);
		else
			rotate_a(s->stack_a);
	}
	*top = s->stack_a->head->index;
	push_to_a(s, nodes_len(s->stack_b->head));
}

void	push_to_a(t_stacks *s, int count)
{
	int	median;

	while (count > 20)
	{
		median = count / 2;
		while ((count > 20) && (count > median))
		{
			if (s->stack_b->head->index > median)
			{
				push_a(s->stack_b, s->stack_a);
				count--;
			}
			else
				rotate_b(s->stack_b);
		}
	}
	selection_sort1(s, count);
}

void	selection_sort1(t_stacks *s, int len)
{
	int	big;
	int	nb_location;

	while (len > 0)
	{
		big = biggest_nb(s->stack_b);
		nb_location = which_half(s->stack_b, big);
		while (s->stack_b->head->index != big)
		{
			if (s->stack_b->head->index == s->stack_a->tail->index + 1)
			{
				push_a(s->stack_b, s->stack_a);
				rotate_a(s->stack_a);
				len--;
			}
			else if (nb_location <= (len / 2))
				rotate_b(s->stack_b);
			else
				reverse_rotate_b(s->stack_b);
		}
		push_a(s->stack_b, s->stack_a);
		len--;
	}
	if (s->stack_a->head->index == 1 && is_sorted(s->stack_a->head) != 1)
		rotate_a(s->stack_a);
}

void	push_chunk(t_stacks *s, int *top)
{
	if (s->stack_a->head->index == *top)
		*top = 1;
	while (s->stack_a->head->index != *top)
	{
		if (s->stack_a->head->index == s->stack_a->tail->index + 1)
			rotate_a(s->stack_a);
		else
			push_b(s->stack_a, s->stack_b);
	}
}
