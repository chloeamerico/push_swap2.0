/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:43:44 by chloeameric       #+#    #+#             */
/*   Updated: 2025/02/06 15:46:13 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// //Décale d’une position vers le bas tous les élements de la pile a. 
// //Le dernier élément devient le premier.
// void	reverse_rotate(t_stack **stack)
// {
// 	t_stack	*last;
// 	t_stack	*before_last;
	
// 	if (*stack && (*stack)->next)
// 	{
// 		last = *stack;
// 		before_last = NULL;

// 		while (last->next)
// 		{
// 			before_last = last;
// 			last = last->next;
// 		}
		
// 		before_last->next = last;

// 		last->next = *stack;
// 		before_last->next = NULL;
// 		*stack = last;	
// 	}	
// }


void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*before_last; //actuel avant-dernier
	
	if (*stack && (*stack)->next)
	{
		first = *stack; //on stocke la tête actuelle
		before_last = *stack;

		while (before_last->next->next) //tant que before_last n'est pas en position d'avant dernier
			before_last = before_last->next; //on parcours la pile

		//echange de pointeurs
		before_last->next->next = first;
		*stack = before_last->next;
		before_last->next = NULL;
	}	
}

void	rra(t_stack **a, int *steps)
{
	reverse_rotate(a);
	printf("rra\n"); //ATTENTION !! mettre ft_printf avant de push
	(*steps)++;
}

void	rrb(t_stack **b, int *steps)
{
	reverse_rotate(b);
	printf("rrb\n");
	(*steps)++;
}

void	rrr(t_stack **a, t_stack **b, int *steps)
{
	reverse_rotate(a);
	reverse_rotate(b);
	printf("rrr\n");
	(*steps)++;
}