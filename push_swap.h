/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cezmenji <cezmenji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:04:51 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/07 17:32:47 by cezmenji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <limits.h>  // Pas sur que c'est necessaire
#include <math.h>  // Pas sur que c'est necessaires 
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct s_stack  
{
    int data;
    struct s_stack *next;  // Il est important de nommer ce pointeur (struct stack), car ce pointeur va pointer vers une variable de meme type compose d'un int et pointeur.
}               t_stack;


// Prototype of functions in list.c
t_stack     *new_node (int data);
void        push (t_stack **head, int data);

#endif