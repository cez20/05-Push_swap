/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:39:29 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/14 16:02:53 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks    *initialize_stacks(void)
{
    t_stacks    *temp;   //Creer une variable de type t_stacks afin de pouvoir accder a son contenu (qui sont 2 pointeurs).
    t_stack     *stack_a; //Le pointeur stack_a est le 1er pointeur, mais aucun memoire ne lui a ete assigne 
    t_stack     *stack_b; //le pointeur stack_b est le 2e pointeur, mais aucune memoire ne lui a ete assigne. 

    temp = malloc (sizeof(*temp)); // Assignation dynamique de la memoire. On malloc 16 bytes approximativement, car struct t_stakcs contient 2 pointeurs (2 bytes chaque)
    temp->stack_a = malloc (sizeof(*stack_a)); // Assignation dynamique memoire de 16 bytes pour le pointeur stack_a
    temp->stack_b = malloc (sizeof(*stack_b)); // Assignation dynamique memoire de 16 bytes, car stack_b pointe vers la structure t_stack qui contient 2 pointeurs 
	temp->stack_b->head = NULL; // Ayant de la memoire, on le fait pointer vers NULL, car la stack_b sera vide au debut
    temp->stack_b->tail = NULL; // Ayant de la memoire, on le fait pointer vers NULL, car ka stacj_b sera vide au debut 
    if (temp == NULL || temp->stack_a == NULL || temp->stack_b == NULL) // Si l'assignation de memoire echoue, on met un message d'erreur. On devrait rajouter if temp = NULL;
        error();
	// printf("\nThe size of pointer 't_stacks temp' is %lu bytes.\n", sizeof(temp));
	// printf("The size of pointer 't_stack stack_a' is %lu bytes.\n", sizeof(stack_a));
	// printf("The size of pointer 't_stack stack_b' is %lu bytes.\n", sizeof(stack_b));
	// printf("The value of stack_a->head is %p (NULL)\n", temp->stack_a->head);
	// printf("The value of stack_b->head is %p (NULL)\n", temp->stack_b->head);
	// printf("The value of pointer 'temp->stack_b->head' is %p (NULL)\n", temp->stack_b->head);
	// printf("The value of pointer 'temp->stack_b->tail' is address %p (NULL)\n\n", temp->stack_b->head);
    return (temp);
}

void	clear_stacks(t_stacks *stacks)
{
	dlst_clear(stacks->stack_a);
	dlst_clear(stacks->stack_b);
	free(stacks->stack_a);
	free(stacks->stack_b);
	free(stacks);
}

