/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:06:37 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/04 19:29:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort1(t_stacks *s, int len)
{
	//int 	count;
	int 	median;
	
	median = (len / 2) + 1;
	while (dlst_len(s->stack_a->head) > 1) // Tant et aussi longtemps que stack_a->head n'est pas NULL ou qu'il contient des elements
	{
		//printf("%d\n", median);
		while (dlst_len(s->stack_b->head) < (median - 1))
		{
			if(s->stack_a->head->pos < median)
				push_b(s->stack_a, s->stack_b);
			else
				rotate_a(s->stack_a);
		}
		median += ((dlst_len(s->stack_a->head) / 2));
	}
}
