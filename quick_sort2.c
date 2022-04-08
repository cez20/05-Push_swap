/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:58:39 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/08 16:29:02 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back_to_a(t_stacks *s, int count);

void	quick_sort2(t_stacks *s, int len)
{
	int 	median;
	int		count;
	int		max;

	median = (len / 2); // si chiffre impair on arrondi a la hausse.
	max = median;
	while (is_sorted(s->stack_a->head) != 1)
	{
		count = 0;
		while (dlst_len(s->stack_b->head) < max) // CEci ne fonctionne pas
		{
			if (s->stack_a->head->pos <= median)
			{
				push_b(s->stack_a, s->stack_b);
				count++;
			}
			else if(s->stack_a->head->pos > median)
				rotate_a(s->stack_a);
		}
		median += (count / 2);
		max = median - (count / 2);
		push_back_to_a(s, count);
	}
}


void	push_back_to_a(t_stacks *s, int count) // Cette fonction devra etre ameliorer pour sur
{
	int new_median;

	while (count > 13)
	{
		new_median = count / 2;
		while ((count > 13) && (count > new_median))
		{
			if (s->stack_b->head->pos > new_median)
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