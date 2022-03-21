/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:27:32 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/21 17:57:30 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, char *str)
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
		if (str)
		{
			ft_putstr_fd(str, 1);
			ft_putstr_fd("\n", 1);
		}
	}
}

void	rotate(t_stack *stack, char *str)
{
	t_dlist	*temp;

	if (stack->head != stack->tail && stack->head && stack->tail)//Si stack->head et stack->tail sont differents? et que chaque element n'est pas NULL.
	{	
		temp = stack->head->next; // temp devient la node suivant
		stack->head->next = NULL; // le stack->head devient le dernier element et devient NULL.
		stack->head->prev = stack->tail; // stack->head-> prev devient le tail, car le tail precedera le head, car le head est place a la fin.
		temp->prev = NULL; // temp->prev devient NULL>
		stack->tail->next = stack->head;  // stack->tail->next qui est normalement a NULL pointe vers le head qui est maintenant dernier
		stack->tail = stack->head; // stack->tail (le tail) devient le head qui est le dernier elements
		stack->head = temp; //le nouveau head devient l'element qui etaitn initalement le 2e
		ft_putstr_fd(str, 1); //affiche le terme 'ra' a l'ecran sur le STDOUT
		ft_putstr_fd("\n", 1); //affiche un saut de ligne. 
	}
}

void	reverse_rotate(t_stack *stack, char *str)
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
		ft_putstr_fd(str, 1); //affiche rra
		ft_putstr_fd("\n", 1); //affiche saut de ligne.  
	}
}

void	push(t_stack *src, t_stack *dest, char *str)
{
	if (src->head) // if stack->head est different de NULL.
	{
		push1(src, dest);
		ft_putstr_fd(str, 1); //affiche pb pour push to stack b
		ft_putstr_fd("\n", 1); //affiche un saut de ligne. 
	}
}

void	push1(t_stack *src, t_stack *dest)
{
	t_dlist		*temp;

	temp = NULL;
	if (src->head->next) //if src->head->next est different de NULL
	{
		temp = src->head->next; //temp devient prochain node 
		temp->prev = NULL; //temp->prev du 2e node devient NULL.
	}
	if (dest->tail == NULL) //si la dest->tail est egal a NULL.
	{
		src->head->next = NULL; // le next du head devient NULL.
		dest->tail = src->head; // dest->tail devient le head de la stack a, car il a ete push sur la stack_b
	}
	else
	{
		src->head->next = dest->head; // src->head->next pointe vers la dest->head qui est deja en place
		dest->head->prev = src->head; // le prev de l'element en place devient l'element qu'on pousse.
	}
	dest->head = src->head; //dest->head devient le premier element de la stack_a
	dest->head->prev = NULL; //l'element prev de la head est NULL, car il s'agit de la head. 
	src->head = temp; // devient l'element suivant sur la stack_a 
	if (src->head == NULL) // Si le head de la stack_a est NULL.
		src->tail = NULL; // tail est NULL. 
}