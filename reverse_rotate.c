/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeamerico <chloeamerico@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:43:44 by chloeameric       #+#    #+#             */
/*   Updated: 2025/01/29 20:43:42 by chloeameric      ###   ########.fr       */
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
