/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:33:49 by camerico          #+#    #+#             */
/*   Updated: 2025/01/09 16:42:46 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	swap(int *stack, int size)
{
	int	tmp;

	if (size < 2)
		return;
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
}

void	sa(int *a, int size_a)
{
	swap(a, size_a);
	printf("sa\n");
}

void	sb(int *b, int size_b)
{
	swap(b, size_b);
	printf("sb\n");
}

void	ss(int *a, int *b, int size_a, int size_b)
{
	swap(a, size_a);
	swap(b, size_b);
	printf("ss\n");
}