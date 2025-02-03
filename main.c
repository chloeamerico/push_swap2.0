/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:46:28 by chloeameric       #+#    #+#             */
/*   Updated: 2025/02/03 19:56:11 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		free_stack(&a);
		free_stack(&b);
		return (0);
	}

	if (check_args(argc, argv) == 1) //check si c'est valide et les limites
	{
		write(1, "Error\n", 6);
		return (0);
	}
	
	a = NULL;
	b = NULL;
	i = argc - 1;
	while(i > 1)
	{
		create_node_first(&a, ft_atoi(argv[i]));
		i--;
	}
	if (check_double(a)) // check les doubles dans a
	{
		write(1, "Error\n", 6);
		free_stack(&a);
		return (0);
	}
	which_algo(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
