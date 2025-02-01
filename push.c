/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeamerico <chloeamerico@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:48:31 by camerico          #+#    #+#             */
/*   Updated: 2025/01/31 16:00:48 by chloeameric      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*head_src;

	if (*src)
	{
		head_src = *src; // on initialise

		*src = head_src->next; // on donne au 2e noeud le role de tête de la pile
		head_src->next = *dest;  // on fait pointer la tête de a vers la tête de b (qui passera donc en 2eme noeud)
		*dest = head_src; // on place le premier noeud de a comme tête de b
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	printf("pa\n"); //ATTENTION !! mettre ft_printf avant de push
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	printf("pb\n");
}