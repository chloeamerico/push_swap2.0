/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:06:38 by camerico          #+#    #+#             */
/*   Updated: 2025/01/09 15:05:25 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	push(int *src, int *dest, int *size_src, int *size_dest)
{
	int	i;
	
	if (*size_src < 1)
		return;
	(*size_dest) += 1;
	i = *size_dest - 1;
	while (i != 0)
	{
		dest[i] = dest[i - 1];
		i--;
	}
	dest[0] = src[0];

	i = 0;
	while (i < *size_src - 1)
	{
		src[i] = src[i + 1];
		i++;
	}
	(*size_src) -= 1;
}

void 	pa(int *a, int *b, int *size_a, int *size_b)
{
	push(b, a, size_b, size_a);
	printf("pa\n");
}

void	pb(int *a, int *b, int *size_a, int *size_b)
{
	push(a, b, size_a, size_b);
	printf("pa\n");
}
