/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:52:57 by camerico          #+#    #+#             */
/*   Updated: 2025/02/06 15:46:44 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/* ************************************************************************** */
/* INCLUDES                                                                   */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
#include <limits.h>
#include <stdbool.h>

/* ************************************************************************** */
/* DEFINES                                                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/* STRUCTURES                                                                 */
/* ************************************************************************** */

typedef struct 		s_stack
{
	int				value; //valeur stockee dans le noeud
	int				index; // index de l'element dans la pile
	struct s_stack 	*next; //pointe vers le prochain element
} t_stack;

// typedef struct s_stack_info
// {
// 	t_stack			*head; //pointe vers le sommet de la pile
// 	int				size; //taille actuelle de la pile
// } t_stack_info;


/* ************************************************************************** */
/* PROTO                                                                      */
/* ************************************************************************** */

int	ft_atoi(const char *nptr);
int valid_number(char *str);
int limits(char *str);
int check_args(int argc, char **argv);
int check_double(t_stack *stack);
t_stack	*create_node_first(t_stack **stack, int	value);
bool	is_sorted(t_stack *stack);
void	which_algo(t_stack **a, t_stack **b, int *steps);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b, int *steps);
void	pb(t_stack **a, t_stack **b, int *steps);
void	rotate(t_stack **stack);
void	ra(t_stack **a, int *steps);
void	rb(t_stack **b, int *steps);
void	rr(t_stack **a, t_stack **b, int *steps);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, int *steps);
void	rrb(t_stack **b, int *steps);
void	rrr(t_stack **a, t_stack **b, int *steps);
void	swap(t_stack **stack);
void	sa(t_stack **a, int *steps);
void	sb(t_stack **b, int *steps);
void	ss(t_stack **a, t_stack **b, int *steps);
int	*dupplicate_in_array(t_stack *stack);
void	search_index(t_stack *stack);
int	nb_of_bits(t_stack *stack);
int check_bit(int index, int bit);
void radix_sort(t_stack **a, t_stack **b, int *steps);
int	stack_size(t_stack *stack);
void	sort_3(t_stack **a, int *steps);
void	sort_5(t_stack **a, t_stack **b, int *steps);
int	find_index_min(t_stack *a);
long	ft_atol(const char *nptr);
void	free_stack(t_stack **stack);
void	print_stack(t_stack	*stack);



/* ************************************************************************** */
/* DEBUG                                                                      */
/* ************************************************************************** */

#endif