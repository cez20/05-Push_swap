/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:55:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/04 16:24:49 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	median_as_tail (t_stack *stacks, int median, int location);
void	put_in_order (t_stacks *s, int median);

void	quick_sort(t_stacks *s, int len)
{
	(void)len;
	int 	median;
	int		nb_location;
	int		count;

	median = 10;
	count = 0;
	//median = len / 2;
	nb_location = which_half(s->stack_a, median);
	while (dlst_len(s->stack_a->head) >= 2) 
	{
		median_as_tail(s->stack_a, median, nb_location);
		while (s->stack_a->head->pos != median)
		{
			if (s->stack_a->head->pos <= median)
				push_b(s->stack_a, s->stack_b);
			else if (s->stack_a->head->pos > median)
				rotate_a(s->stack_a);
			if (dlst_len(s->stack_b->head) >= 2)
			{
				if((s->stack_b->head->data < s->stack_b->head->next->data) && (s->stack_b->head->data < s->stack_b->tail->data))
					rotate_b(s->stack_b);
				if((s->stack_b->head->data < s->stack_b->head->next->data && s->stack_b->head->data > s->stack_b->head->next->next->data))
					swap_b(s->stack_b);
				while (s->stack_b->head->data < s->stack_b->head->next->data)
				{
					swap_b(s->stack_b);
					//rotate_b(s->stack_b);
					push_a(s->stack_b, s->stack_a);
					count++;
				}
				while (count > 0)
				{
					//reverse_rotate_b(s->stack_b);
					push_b(s->stack_a, s->stack_b);
					count--;
				}
				//if((s->stack_b->head->data < s->stack_b->head->next->data))
					//swap_b(s->stack_b);
				count = 0;
			}
		}
		median += 10;
		//median += (dlst_len(s->stack_a->head) / 2);
	}
	while (s->stack_b->head != NULL)
	{
		push_a(s->stack_b, s->stack_a);
		// if (s->stack_a->head->pos > s->stack_a->head->next->pos)
		// 	swap_a(s->stack_a);
		// if ((s->stack_a->head->data > s->stack_a->head->next->data) && (s->stack_a->head->data > s->stack_a->head->next->next->data))
		// {
		// 	swap_a(s->stack_a);
		// 	rotate_a(s->stack_a);
		// 	swap_a(s->stack_a);
		// 	reverse_rotate_a(s->stack_a);
		// }	
		// if((s->stack_a->head->data > s->stack_a->head->next->data))
		// 	swap_a(s->stack_a);
	}
}

void	median_as_tail(t_stack *stacks, int median, int location)
{
	while (stacks->tail->pos != median)
	{
		if (location <= median)
			rotate_a(stacks);
		else if(location >= median)
			reverse_rotate_a(stacks);
	}
}
