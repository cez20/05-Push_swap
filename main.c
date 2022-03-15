/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/15 09:52:50 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
    t_stacks    *stacks;  
    int         length;  

    stacks = initialize_stacks(); 
    if (argc > 1) 
    {
        create_dlist(stacks->stack_a, argv);
        length = dlst_len(stacks->stack_a->head);
        assign_pos(length, 1, stacks->stack_a->head);
    }
	clear_stacks(stacks);
    return (0);
}

