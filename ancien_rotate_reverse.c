/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:31:33 by camerico          #+#    #+#             */
/*   Updated: 2025/01/09 15:07:24 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	reverse_rotate(int *stack, int size)
{
	int	i;
	int	tmp;

	if (size < 2)
		return;

	tmp = stack[size - 1];
	i = size - 1;
	while(i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = tmp;
}

void	rra(int *a, int size_a)
{
	reverse_rotate(a, size_a);
	printf("rra\n");
}

void	rrb(int *b, int size_b)
{
	reverse_rotate(b, size_b);
	printf("rrb\n");
}

void	rrr(int *a, int *b, int size_a, int size_b)
{
	reverse_rotate(a, size_a);
	reverse_rotate(b, size_b);
	printf("rrr\n");
}