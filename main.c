/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/21 17:28:39 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			length;

	stacks = initialize_stacks();
	if (argc > 1)
	{
		create_dlist(stacks->stack_a, argv);
		print_dlist(stacks->stack_a->head);
		length = dlst_len(stacks->stack_a->head);
		assign_pos(length, 1, stacks->stack_a->head);
		/*while (stacks->stack_a->head)
		{
			printf("%d\n", stacks->stack_a->head->pos);
			stacks->stack_a->head = stacks->stack_a->head->next;
		}*/
		if (length < 30)
			selectionsort(stacks, length);
		//else
			//sort_radix(stacks->stack_a, stacks->stack_b, length);
		
		
	}
	return (0);
}
