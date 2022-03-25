/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:24:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/25 16:03:35 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_stacks *s, int len)
{
	int 	small;
	int 	nb_location;
	
	while (len > 3)
	{
		small = smallest_nb(s->stack_a);
		nb_location = which_half(s->stack_a, small);
		while(s->stack_a->head->pos != small)
		{
			if (nb_location <= (len / 2))
				rotate_a(s->stack_a);
			else if(nb_location >= (len / 2))
				reverse_rotate_a(s->stack_a);
			if (is_sorted(s->stack_a->head) == 1)
		 		return;
		}
		push_b(s->stack_a, s->stack_b);
		len--;
	}
	simple_sort(s);
	while (s->stack_b->head != NULL)
		push_a(s->stack_b, s->stack_a);
}

int which_half(t_stack *stack, int small)
{
	t_dlist	*temp;
	int count;

	temp = stack->head;
	count = 1;
	while (temp->pos != small)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

void	simple_sort(t_stacks *s)
{
	int	big;
	int small;

	small = smallest_nb(s->stack_a); 
	big = biggest_nb(s->stack_a); // big devient le chiffre le plus element de la liste. 
	if (s->stack_a->head->pos == big) //si la pos de la head est le chiffre le plus gros, faire RA et le pousser en dernier 
		rotate_a(s->stack_a);
	else if (s->stack_a->head->next->pos == big) // si l'element apres le head est la plus gros, faire RRA
		reverse_rotate_a(s->stack_a);
	if (s->stack_a->head->next->pos == small && s->stack_a->tail->pos == big) 
		swap_a(s->stack_a); 
}


int	is_sorted(t_dlist *lst) // on prend le head de la linked list 
{
	if (lst->pos != 1) // Si la position du premier element de la liste est different de 1
		return (0); //retourne false.
	while (lst->next) //Tant que lst->next est different de NULL. 
	{
		if (lst->data < lst->next->data) // Si le chiffre du node actuel est plus petite que celui du node suivante
			lst = lst->next; // On saute au prochain node
		else
			return (0);
	}
	return (1);
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
