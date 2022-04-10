/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:21:49 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/08 09:24:30 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort1(t_stacks *s, int len)
{
	int 	median;

	median = len / 2; // si chiffre impair on arrondi a la hausse.
	//while (dlst_len(s->stack_a->head) > 1) 
	//{
		while (dlst_len(s->stack_b->head) < median)
		{
			if (s->stack_a->head->pos <= median)
				push_b(s->stack_a, s->stack_b);
			else 
				rotate_a(s->stack_a);
		}
		stack_in_order (s, median);
		//median += (dlst_len(s->stack_a->head) / 2);
}

void	stack_in_order (t_stacks *s, int median)
{
	int nb_location;
	int big;

	big = biggest_nb(s->stack_b);
	nb_location = which_half(s->stack_b, big);
	while (s->stack_b->head)
	{
		while (s->stack_b->head->pos != big)
		{
			if (nb_location <= (dlst_len(s->stack_b->head) / 2))
				rotate_b(s->stack_b);
			else 
				reverse_rotate_b(s->stack_b);
		}
		push_a(s->stack_b, s->stack_a);
		big--;
	}
	while (s->stack_a->head->pos < median)
		push_b(s->stack_a, s->stack_b);
}


// void	quick_sort(t_stacks *s, int len)
// {
// 	(void)len;
// 	int		chunks[50];
// 	int 	median;
// 	int		count;
// 	int 	temp;
// 	int		nb_of_rotate;
// 	int		nb_of_rotation;
// 	int 	i;

// 	i = 0;
// 	count = 0;
// 	median = (len / 2); // si chiffre impair on arrondi a la hausse.
// 	while (dlst_len(s->stack_a->head) > 1) 
// 	{
// 		while (dlst_len(s->stack_b->head) < median)
// 		{
// 			if (s->stack_a->head->pos <= median)
// 			{
// 				push_b(s->stack_a, s->stack_b);
// 				count++;
// 			}
// 			else if(s->stack_a->head->pos > median)
// 				rotate_a(s->stack_a);
// 		}
// 		chunks[i++] = count;
// 		median += (dlst_len(s->stack_a->head) / 2);
// 		count = 0;
// 	}
// 	i--;
// 	temp = 0;
// 	nb_of_rotate = 0;
// 	nb_of_rotation = 0;
// 	while (s->stack_b->head)
// 	{
// 		count = chunks[i--];
// 		while (count > 0)
// 		{
// 			temp = (count + 2) / 2; // Cela semble fonctionner pour l'instant, mais l'ideal serait de bien analyser que les median tombe sur ce que je veux. 
// 			median = median - temp;
// 			while (count >= temp)
// 			{
// 				if (s->stack_b->head->pos > median)
// 				{
// 					push_a(s->stack_b, s->stack_a);
// 					count--;
// 					if((s->stack_a->head->data > s->stack_a->head->next->data) && (s->stack_a->head->data > s->stack_a->tail->data))
// 						rotate_a(s->stack_a);
// 					else if((s->stack_a->head->data > s->stack_a->head->next->data) && (s->stack_a->head->data < s->stack_a->head->next->next->data))
// 						swap_a(s->stack_a);
// 					while (s->stack_a->head->data > s->stack_a->head->next->data)
// 					{
// 						swap_a(s->stack_a);
// 						rotate_a(s->stack_a);
// 						nb_of_rotation++;
// 					}
// 					while (nb_of_rotation > 0)
// 					{
// 						reverse_rotate_a(s->stack_a);
// 						nb_of_rotation--;
// 					}
// 				}
// 				else
// 				{
// 					rotate_b(s->stack_b);
// 					nb_of_rotate++;
// 				}
// 			}
// 			while (nb_of_rotate > 0)
// 			{
// 				reverse_rotate_b(s->stack_b);
// 				nb_of_rotate--;
// 			}
// 			nb_of_rotate = 0;
// 		}
// 	}

