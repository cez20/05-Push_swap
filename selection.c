/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:24:18 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/23 17:45:14 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	selection_sort(t_stacks *s, int length)
{
	int min_pos;
	
	while (dlst_len(s->stack_b->head) <= (length / 2))
	{
		min_pos = smallest_num(s->stack_a);
		while (s->stack_a->head->pos != min_pos)
	}	
}*/

void	simple_sort(t_stacks *s)
{
	int	max_pos; 

	max_pos = biggest_num(s->stack_a); // big devient le chiffre le plus element de la liste. 
	if (s->stack_a->head->pos == max_pos) //si la pos de la head est le chiffre le plus gros, faire RA et le pousser en dernier 
		rotate_a(s->stack_a);
	else if (s->stack_a->head->next->pos == max_pos) // si l'element apres le head est la plus gros, faire RRA
		reverse_rotate_a(s->stack_a);
	if (s->stack_a->head->next->pos == 1 && s->stack_a->tail->pos == max_pos) // si la position de la tail est differente de la longueur de la liste.n
		swap_a(s->stack_a); //swap les 2 premiers elements de la stack_a
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
