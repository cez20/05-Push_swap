/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/03/23 17:03:52 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int 		length;

	if (argc > 1)
	{
		int_validation(argv);
		stacks = initialize_stacks();
		dlist_creation(stacks->stack_a, argv);
		//print_dlist(stacks->stack_a->head);
		length = dlst_len(stacks->stack_a->head);
		positioning(length, stacks->stack_a->head);
		if (is_sorted(stacks->stack_a->head) == 1)
		 	return (0);
		if (length <= 3)
		 	simple_sort(stacks);
		// if (length > 3 && length < 6)
		// 	selection_sort(stacks, length);
		clear_stacks(stacks);
	}
	//return (0);
}


/*while (stacks->stack_a->head)
		{
			printf("%d\n", stacks->stack_a->head->pos);
			stacks->stack_a->head = stacks->stack_a->head->next;
		}*/