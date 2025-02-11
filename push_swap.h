/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:30:18 by camerico          #+#    #+#             */
/*   Updated: 2025/02/11 17:58:05 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
/* INCLUDES                                                                   */
/* ************************************************************************** */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "./ft_printf/ft_printf.h"

/* ************************************************************************** */
/* DEFINES                                                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/* STRUCTURES                                                                 */
/* ************************************************************************** */

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/* ************************************************************************** */
/* PROTO                                                                      */
/* ************************************************************************** */

int	ft_atoi(const char *nptr);
int	valid_number(char *str);
int	limits(char *str);
int	check_args(int argc, char **argv);
int	check_double(t_stack *stack);
t_stack	*create_node_first(t_stack **stack, int value);
bool	is_sorted(t_stack *stack);
void	which_algo(t_stack **a, t_stack **b);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int	*dupplicate_in_array(t_stack *stack);
void	search_index(t_stack *stack);
int	nb_of_bits(t_stack *stack);
int	check_bit(int index, int bit);
void	radix_sort(t_stack **a, t_stack **b);
int	stack_size(t_stack *stack);
void	sort_3(t_stack **a);
void	sort_5(t_stack **a, t_stack **b);
int	find_index_min(t_stack *a);
long	ft_atol(const char *nptr);
void	free_stack(t_stack **stack);
void	print_stack(t_stack *stack);
void	free_split(char **array);
char	**ft_split(char const *s, char c);
void	print_stack(t_stack *stack);
void	main2(int argc, char **argv, t_stack **a);

/* ************************************************************************** */
/* DEBUG                                                                      */
/* ************************************************************************** */

#endif