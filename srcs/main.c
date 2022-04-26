/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cemenjiv <cemenjiv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:36:43 by cemenjiv          #+#    #+#             */
/*   Updated: 2022/04/26 00:26:36 by cemenjiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			len;

	if (argc >= 2)
	{
		stacks = create_stacks();
		create_nodes(stacks->stack_a, argv);
		len = nodes_len(stacks->stack_a->head);
		indexing(len, stacks->stack_a->head);
		if (is_sorted(stacks->stack_a->head) == 0)
		{
			free_stacks(stacks);
			return (0);
		}
		if (len <= 5)
			selection_sort(stacks, len);
		if (len > 5)
			quick_sort(stacks, len);
		free_stacks(stacks);
	}
	return (0);
}
