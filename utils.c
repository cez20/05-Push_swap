/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cezmenji <cezmenji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:45:01 by cezmenji          #+#    #+#             */
/*   Updated: 2022/03/07 17:24:36 by cezmenji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Cette fonction cree un nouveau node et retourne ce nouveau node
t_stack   *new_node (int data)
{
    t_stack   *new_node;

    new_node = malloc(sizeof(new_node));
    new_node->data = data;
    new_node->next = NULL;
    return (new_node);
}

//Cette fonction "push" un element au dessus de la stack 
void    push (t_stack **head, int data)
{
    t_stack   *add_node = new_node(data);
    add_node->next = *head;  //add_note->next devient NULL;
    *head = add_node; // *root gloabl comprenant data et next prend les valeur respectives de 4 et next = NULL: 
    printf("%d pushed to stack\n", data);
    return;
}
