/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/07 16:40:38 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			length;

	if (argc >= 2)
	{
		int_validation(argv);
		stacks = initialize_stacks();
		dlist_creation(stacks->stack_a, argv);
		length = dlst_len(stacks->stack_a->head);
		positioning(length, stacks->stack_a->head);
		if (is_sorted(stacks->stack_a->head) == 1)
			return (0);
		if (length <= 5)
			selection_sort(stacks, length);
		if (length > 5)
			quick_sort(stacks, length);
		// if (length > 5)
		// 	quick_sort(stacks, length);
		//if (length > 100)
		 	//quick_sort1(stacks);
		clear_stacks(stacks);
	}
	return (0);
}

//print_dlist(stacks->stack_a->head);
/*while (stacks->stack_a->head)
		{
			printf("%d\n", stacks->stack_a->head->pos);
			stacks->stack_a->head = stacks->stack_a->head->next;
		}*/