/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:55:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/28 20:25:00 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stacks *s, int len)
{
	int 	median;
	int		nb_location;

	median = (len / 2);
	nb_location = which_half(s->stack_a, median);
	while (s->stack_a->tail->pos != median)
	{
		if (nb_location <= median)
				rotate_a(s->stack_a);
		else if(nb_location >= median)
			reverse_rotate_a(s->stack_a);
	}
	while (dlst_len(s->stack_a->head) != 1) // ca bogue parce qu;il faut toujours repositionner le median comme tail sinon, ca ne marche pas
	{
		while (s->stack_a->head->pos != median)
		{
			if (s->stack_a->head->pos < median)
				push_b(s->stack_a, s->stack_b);
			else if (s->stack_a->head->pos > median)
				rotate_a(s->stack_a);
			if (s->stack_b->head->next != NULL)
			{
				if(s->stack_b->head->data < s->stack_b->head->next->data && s->stack_b->head->data > s->stack_b->tail->data)
					swap_b(s->stack_b);
			}
		}
		median += (dlst_len(s->stack_a->head) / 2);
	}
	push_a(s->stack_b, s->stack_a);
}