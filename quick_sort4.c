/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:14:52 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/10 11:00:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void	push_back_to_a(t_stacks *s, int count);
int		temp_array(t_stack *stack, int len);
void	bubble_sort(int *tab, int size);
void    prior_sort(t_stacks *s);

void	quick_sort4(t_stacks *s, int len)
{
	int 	median;
	int		count;

	//median = (len / 2); // si chiffre impair on arrondi a la hausse.
	median = 0;
	count = 0;
	while (s->stack_a->head)
	{
		len = dlst_len(s->stack_a->head);
    	median = temp_array(s->stack_a, len);
		while ((dlst_len(s->stack_a->head) > (len / 2))) // CEci ne fonctionne pas
		{
			if (dlst_len(s->stack_a->head) <= 20) // Si lorsqu'il rentre dans cette boucle, je me rends compte que la longueur de stack_b est plus petit que 13, je fais selection_sort
		    {
			    selection_sort2(s, dlst_len(s->stack_a->head));
			    break;
		    }
			if (s->stack_a->head->pos <= median)
        	{
				push_b(s->stack_a, s->stack_b);
				count++;
			}
			else if (s->stack_a->head->pos > median)
				rotate_a(s->stack_a);
		}
	}
	//push_back_to_a(s, count);

    // while ((is_sorted(s->stack_a->head) != 1) && (dlst_len(s->stack_b->head) == 0))
    // {
    //     prior_sort(s);
    //     while (s->stack_b->head)
	//     {
	//         len = dlst_len(s->stack_b->head);
    //         median = temp_array(s, len); // Nous avons la position qui represente la mediane.
	//         while ((dlst_len(s->stack_b->head) > (len / 2))) //&& s->stack_b->head) // IMPORTANT = Je suis rendu a changer la loop, lorsqu'il ne rentre plus dans cette boucle, on refait bubble_sort et on recalcule mediane
    //         {
	// 	        if (dlst_len(s->stack_b->head) <= 20) // Si lorsqu'il rentre dans cette boucle, je me rends compte que la longueur de stack_b est plus petit que 13, je fais selection_sort
	// 	        {
	// 		        selection_sort1(s, dlst_len(s->stack_b->head));
	// 		        break;
	// 	        }
	// 	        if (s->stack_b->head->pos >= median)
	// 		        push_a(s->stack_b, s->stack_a);
	// 	        else
	// 		        rotate_b(s->stack_b); // C'est ici que ca semble bogue
	//         }
    //     }
    // }
}

void    prior_sort(t_stacks *s)
{
    while (s->stack_a->head->pos != 1)
	{
		if (s->stack_a->head->pos == s->stack_a->tail->pos + 1)
			rotate_a(s->stack_a);
		else
			push_b(s->stack_a, s->stack_b);
	}
	if (dlst_len(s->stack_b->head) <= 20) // Si le nombre d'element qui sont pousse a la stack_b est plus petit que 13, un selection sort se fait. 
		selection_sort1(s, dlst_len(s->stack_b->head));
}


int	temp_array(t_stack *stack, int len)
{
	t_dlist *temp;
	int 	temp_stack[500];
	int		i;
	int 	median;

	i = 0;
	temp = stack->head;
	while (temp)
	{
		temp_stack[i++] = temp->pos;
		temp = temp->next;
	}
	temp_stack[i] = '\0';
	bubble_sort(temp_stack, len);
	median = temp_stack[len / 2];
	return (median);
}

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	c;
	int	swap;

	i = 0;
	c = 0;
	while (c < size)
	{
		while (i < (size - 1))
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
		i = 0;
		c++;
	}
}

void	push_back_to_a(t_stacks *s, int count) // Cette fonction devra etre ameliorer pour sur
{
	int new_median;

	while (count > 20)
	{
		new_median = count / 2;
		while ((count > 20) && (count > new_median))
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