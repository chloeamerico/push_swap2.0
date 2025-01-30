/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:58:54 by camerico          #+#    #+#             */
/*   Updated: 2025/01/21 17:39:44 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void sa(int *a, int size_a);
void sb(int *b, int size_b);
void ss(int *a, int *b, int size_a, int size_b);
void pa(int *a, int *b, int *size_a, int *size_b);
void pb(int *a, int *b, int *size_a, int *size_b);
void ra(int *a, int size_a);
void rb(int *b, int size_b);
void rr(int *a, int *b, int size_a, int size_b);
void rra(int *a, int size_a);
void rrb(int *b, int size_b);
void rrr(int *a, int *b, int size_a, int size_b);

void print_piles(int *a, int size_a, int *b, int size_b)
{
    int i;

    printf("Pile a : ");
    i = 0;
    while (i < size_a)
    {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n");

    printf("Pile b : ");
    i = 0;
    while (i < size_b)
    {
        printf("%d ", b[i]);
        i++;
    }
    printf("\n");
}

int main(void)
{
    int a[5] = {3, 2, 1, 4, 5}; // Pile a
    int b[5] = {0};             // Pile b (vide au départ)
    int size_a = 5;
    int size_b = 0;

    printf("État initial :\n");
    print_piles(a, size_a, b, size_b);

    // Test des combinaisons d'instructions
    printf("\n-- Test des combinaisons d'instructions --\n");

    // Appliquer un swap sur a
    sa(a, size_a);
    print_piles(a, size_a, b, size_b);

    // Pousser un élément de a vers b
    pb(a, b, &size_a, &size_b);
    print_piles(a, size_a, b, size_b);

    // Faire une rotation sur a
    ra(a, size_a);
    print_piles(a, size_a, b, size_b);

    // Faire un reverse rotate sur b
    rrb(b, size_b);
    print_piles(a, size_a, b, size_b);

    // Faire un double rotate
    rr(a, b, size_a, size_b);
    print_piles(a, size_a, b, size_b);

    // Remettre l'élément de b vers a
    pa(a, b, &size_a, &size_b);
    print_piles(a, size_a, b, size_b);

    // Faire un reverse rotate sur les deux piles
    rrr(a, b, size_a, size_b);
    print_piles(a, size_a, b, size_b);

    return (0);
}