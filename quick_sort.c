/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:55:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/04 14:14:56 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stacks *s)
{
	int 	median;
	int		count;

	median = 10;
	count = 0;
	while(s->stack_a->head != NULL)
	{
		while (dlst_len(s->stack_b->head) < median)
		{
			if (s->stack_a->head->pos <= median)
				push_b(s->stack_a, s->stack_b);
			//else if ((s->stack_a->head->pos > median) && (s->stack_b->head->data < s->stack_b->tail->data))
				//rotate_both (s->stack_a, s->stack_b);
			else if (s->stack_a->head->pos > median)
				rotate_a(s->stack_a);
			if (dlst_len(s->stack_b->head) >= 2)
			{
				if((s->stack_b->head->data < s->stack_b->head->next->data) && (s->stack_b->head->data < s->stack_b->tail->data))
					rotate_b(s->stack_b);
				else if((s->stack_b->head->data < s->stack_b->head->next->data) && (s->stack_b->head->data > s->stack_b->head->next->next->data))
					swap_b(s->stack_b);
				while (s->stack_b->head->data < s->stack_b->head->next->data)
				{
					swap_b(s->stack_b);
					rotate_b(s->stack_b);
					count++;
				}
				while (count > 0)
				{
					reverse_rotate_b(s->stack_b);
					count--;
				}
				count = 0;
			}
		}
		median += 10;
	}
	while (s->stack_b->head != NULL)
		push_a(s->stack_b, s->stack_a);
}
