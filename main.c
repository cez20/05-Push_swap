/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/12 23:57:45 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			len;

	if (argc >= 2)
	{
		args_validation(argv);
		stacks = create_stacks();
		create_nodes(stacks->stack_a, argv);
		len = nodes_len(stacks->stack_a->head);
		indexing(len, stacks->stack_a->head);
		//print_node(stacks->stack_a->head);
		if (is_sorted(stacks->stack_a->head) == 1)
			return (0);
		if (len <= 5)
			selection_sort(stacks, len);
		if (len > 5)
			quick_sort(stacks, len);
		free_stacks(stacks);
	}
	return (0);
}
