/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:24:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/22 11:49:35 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selectionsort(t_stacks *s, int len)
{
	int	small; //chiffre small
	int	big; // chiffre big
	
	while (dlst_len(s->stack_a->head) > 3) // Tant que la longueur de la liste est plus grande que 3
	{
		small = smallest_num(s->stack_a);
		if (is_in_order(s->stack_a->tail, 1) != dlst_len(s->stack_a->head)) // Si order est diffrent de la longueur de la linked list.
		{
			while (s->stack_a->head->pos != small) //Tant et aussi longtemps que la position de la head est different du chiffre le plus petit
				direction(s->stack_a, len, small); // Soit fait des rotate ou de reverse rotate
		}
		push(s->stack_a, s->stack_b, "pb"); //Pousse le premier element de la stack_a vers la stack_b
	}
	big = biggest_num(s->stack_a); // big devient le chiffre le plus element de la liste. 
	if (s->stack_a->head->pos == big) //si la pos de la head est le chiffre le plus gros, faire RA
		rotate(s->stack_a, "ra");
	else if (s->stack_a->head->next->pos == big) // si l'element apres le head est la plus gros, faire RRA
		reverse_rotate(s->stack_a, "rra");
	if (is_in_order(s->stack_a->tail, 1) != dlst_len(s->stack_a->head)) // si la position de la tail est differente de la longueur de la liste.n
		swap(s->stack_a, "sa"); //swap les 2 premiers elements de la stack_a
	while (s->stack_b->head != NULL)
		push(s->stack_b, s->stack_a, "pa");
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

int	is_in_order(t_dlist *lst, int i) // Prend en parametre le tail de la dlist et le chiffre 1
{
	int	order;

	order = 0;
	if (lst && lst->prev) //Si tail de la dlist et le node anterieur est different de NULL.
	{
		if (i == -1) //Si i = -1. Pourquoi i serait egal a -1??
		{
			if (lst->pos != 1) // la position du tail est differente de 1
				return (order);
		}
		order = 1;
		while (lst->prev && lst->pos == lst->prev->pos + i) //lst-prev different de NULL et position de la liste de la tail egale position anterieure + 1
		{
			order++; // on augmente l'ordre 
			lst = lst->prev; //tail devient element precedent. 
		}
	}
	return (order); //retourne le chiffre correspondant a l'ordre/ 
}

int	smallest_num(t_stack *stack) // Prend un pointeur de type *stack qui refere vers un pointeru head et tail
{
	t_dlist	*temp; // variable temporaire 
	int		small;

	temp = stack->head; //egale le node head ou node de depart de la liste. 
	small = stack->head->pos; //prend le numero de sa position 
	while (temp) //tant que temp n'est pas egal a NULL 
	{
		if (small > temp->pos) // Si la position small du head est plus grand que celui du prochain node
			small = temp->pos; // small prend la valeur plus petite du node suivant 
		temp = temp->next; //temp pointe vers le prochain node. 
	}
	return (small); //retourne la position indique par small (donc le plus petit chiffre)
}

int	biggest_num(t_stack *stack)// prend en parametre la stack_a
{
	t_dlist	*temp; // 
	int		big;

	temp = stack->head; //temp devient le node head
	big = stack->head->pos; // big devient le stack->head->pos 
	while (temp) // temp et aussi longtemps que temp n;est pas NULL.
	{
		if (big < temp->pos) // si big est plus petit que la position temporaire 
			big = temp->pos; // big prend la valeur du node pos ou il se trouve. 
		temp = temp->next; //temp devient le prochain node. 
	}
	return (big); //retourne le chiffre le plus eleve
}

void	direction(t_stack *stack, int len, int small) //stack refere head ou tail, length et plus petit chiffre.
{
	t_dlist	*temp;
	int		i;

	i = 0;
	temp = stack->head;
	while (temp->next) //Tant et aussi longtemps que temp->next est different de NULL
	{
		i++; //augment le i
		temp = temp->next; //temp pointe vers le prochain node
		if (temp->pos == small) //Si la position du node actuel est egale au plus petit chiffre
			break ; //break la loop
	}
	if (i < (len / 2)) // Si i est plus petit que la longueur de la dlist divise par 2 
		rotate(stack, "ra"); //Faire action rotate 
	else
		reverse_rotate(stack, "rra"); //Sinon faire reverse rotate.
}
