/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:27:32 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/24 12:43:44 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	t_dlist	*temp;

	if (stack->head != stack->tail && stack->head && stack->tail)
	{	
		temp = stack->head->next;
		stack->head->next = temp->next;
		stack->head->prev = temp;
		temp->prev = NULL;
		if (temp->next)
			temp->next->prev = stack->head;
		temp->next = stack->head;
		stack->head = temp;
		if (stack->tail->data == stack->head->data)
			stack->tail = stack->head->next;
		write (1, "sa\n", 3);
	}
}

void	rotate_a(t_stack *stack)
{
	t_dlist	*temp;

	if (stack->head != stack->tail && stack->head && stack->tail)//Si stack->head et stack->tail sont differents? et que chaque element n'est pas NULL.
	{	
		temp = stack->head->next; // temp devient la node suivant
		temp->prev = NULL;
		stack->head->next = NULL; // le stack->head devient le dernier element et devient NULL.
		stack->head->prev = stack->tail; // stack->head-> prev devient le tail, car le tail precedera le head, car le head est place a la fin. // temp->prev devient NULL>
		stack->tail->next = stack->head;  // stack->tail->next qui est normalement a NULL pointe vers le head qui est maintenant dernier
		stack->tail = stack->head; // stack->tail (le tail) devient le head qui est le dernier elements
		stack->head = temp; //le nouveau head devient l'element qui etaitn initalement le 2e
		write (1, "ra\n", 3);
	}
}

void	reverse_rotate_a(t_stack *stack)
{
	t_dlist	*temp;

	if (stack->head != stack->tail && stack->head && stack->tail) //Si stack->head et stack->tail sont differents? et que chaque element n'est pas NULL.
	{
		temp = stack->tail->prev; //temp devient le node avant le stack->tail
		temp->next = NULL; // le temp->next va pointer vers NULL maintenant qu'il devient le dernier element
		stack->tail->next = stack->head; //le stack->tail->next qui est normalement a NULL devient le stack->head
		stack->head->prev = stack->tail; //le stack->head->prev devient le tail car tial 1er element de la liste.
		stack->head = stack->tail; // le head devient le tail. 
		stack->tail = temp; // le nouveau tail est l'element anterieur a l'ancien tail. 
		write (1, "rra\n", 4); 
	}
}
