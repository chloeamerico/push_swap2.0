/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:50:14 by camerico          #+#    #+#             */
/*   Updated: 2025/01/09 15:07:31 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	rotate(int *stack, int size)
{
	int	i;
	int	tmp;

	if (size < 2)
		return;

	tmp = stack[0];
	i = 0;
	while(i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = tmp;
}

void	ra(int *a, int size_a)
{
	rotate(a, size_a);
	printf("ra\n");
}

void	rb(int *b, int size_b)
{
	rotate(b, size_b);
	printf("rb\n");
}

void	rr(int *a, int *b, int size_a, int size_b)
{
	rotate(a, size_a);
	rotate(b, size_b);
	printf("rr\n");
}