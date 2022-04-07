/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:55:12 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/07 14:55:13 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

// void	quick_sort(t_stacks *s)
// {
// 	int 	median;
// 	int		count;

// 	median = 10;
// 	count = 0;
// 	while(s->stack_a->head != NULL)
// 	{
// 		while (dlst_len(s->stack_b->head) < median)
// 		{
// 			if (s->stack_a->head->pos <= median)
// 				push_b(s->stack_a, s->stack_b);
// 			else if (s->stack_a->head->pos > median)
// 				rotate_a(s->stack_a);
// 			if (dlst_len(s->stack_b->head) >= 2)
// 			{
// 				if((s->stack_b->head->data < s->stack_b->head->next->data) && (s->stack_b->head->data < s->stack_b->tail->data))
// 					rotate_b(s->stack_b);
// 				else if((s->stack_b->head->data < s->stack_b->head->next->data) && (s->stack_b->head->data > s->stack_b->head->next->next->data))
// 					swap_b(s->stack_b);
// 				while (s->stack_b->head->data < s->stack_b->head->next->data)
// 				{
// 					swap_b(s->stack_b);
// 					if (s->stack_a->head->pos > median && dlst_len(s->stack_a->head) >= 3)
// 					 	rotate_both(s->stack_a, s->stack_b);
// 					else
// 						rotate_b(s->stack_b);
// 					count++;
// 				}
// 				while (count > 0)
// 				{
// 					reverse_rotate_b(s->stack_b);
// 					count--;
// 				}
// 				count = 0;
// 			}
// 		}
// 		median += 10;
// 	}
// 	while (s->stack_b->head != NULL)
// 		push_a(s->stack_b, s->stack_a);
// }


void	quick_sort(t_stacks *s, int len)
{
	(void)len;
	int		chunks[50];
	int 	median;
	int		count;
	int 	temp;
	int		nb_of_rotate;
	int 	i;

	i = 0;
	count = 0;
	median = (len / 2); // si chiffre impair on arrondi a la hausse.
	while (dlst_len(s->stack_a->head) > 1) 
	{
		while (dlst_len(s->stack_b->head) < median)
		{
			if (s->stack_a->head->pos <= median)
			{
				push_b(s->stack_a, s->stack_b);
				count++;
			}
			else if(s->stack_a->head->pos > median)
				rotate_a(s->stack_a);
		}
		chunks[i++] = count;
		median += (dlst_len(s->stack_a->head) / 2);
		count = 0;
	}
	i--;
	temp = 0;
	nb_of_rotate = 0;
	while (s->stack_b->head)
	{
		count = chunks[i--];
		while (count > 0)
		{
			temp = (count + 2) / 2; // Cela semble fonctionner pour l'instant, mais l'ideal serait de bien analyser que les median tombe sur ce que je veux. 
			median = median - temp;
			while (count >= temp)
			{
				if (s->stack_b->head->pos > median)
				{
					push_a(s->stack_b, s->stack_a);
					count--;
				}
				else
				{
					rotate_b(s->stack_b);
					nb_of_rotate++;
				}
			}
			while (nb_of_rotate > 0)
			{
				reverse_rotate_b(s->stack_b);
				nb_of_rotate--;
			}
			nb_of_rotate = 0;
		}
	}

	//while (i >= 0)
		//printf("%d\n", chunks[i--];

	







	
	// temp = median;
	// while (s->stack_b->head)
	// {
	// 	temp = temp - ;
	// 	while (count > 0)
	// 	{
	// 		push_a(s->stack_b, s->stack_a);
	// 		count--;
	// 		if (dlst_len(s->stack_a->head) >= 2)
	// 		{
	// 			if((s->stack_a->head->data > s->stack_a->head->next->data) && (s->stack_a->head->data > s->stack_a->tail->data))
	// 				rotate_a(s->stack_a);
	// 			else if((s->stack_a->head->data > s->stack_a->head->next->data) && (s->stack_a->head->data < s->stack_a->head->next->next->data))
	// 				swap_a(s->stack_a);
	// 			while (s->stack_a->head->data > s->stack_a->head->next->data)
	// 			{
	// 				swap_a(s->stack_a);
	// 				rotate_a(s->stack_a);
	// 				nb_of_rotation++;
	// 			}
	// 			while (nb_of_rotation > 0)
	// 			{
	// 				reverse_rotate_a(s->stack_a);
	// 				nb_of_rotation--;
	// 			}
	// 		}
	// 	}
	// 	count = 10;
	// }
}