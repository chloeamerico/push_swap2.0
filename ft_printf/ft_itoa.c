/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:02:46 by camerico          #+#    #+#             */
/*   Updated: 2024/12/03 13:13:02 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen2(int nb)
{
	int		len;
	long	n;

	len = 0;
	n = nb;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

// converti les int en char
// utilisation de malloc
char	*ft_itoa(int nb)
{
	char	*final;
	int		i;
	long	n;

	n = nb;
	i = ft_strlen2(n);
	final = malloc(sizeof(char) * (ft_strlen2(n) + 1));
	if (!final)
		return (NULL);
	final[i] = '\0';
	i--;
	if (n < 0)
	{
		final[0] = '-';
		n = -n;
	}
	if (n == 0)
		final[0] = '0';
	while (n > 0)
	{
		final[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (final);
}

// int	main(void)
// {
// 	char *tmp;

// 	tmp = ft_itoa(123456);
// 	printf("%s", tmp);
// 	free(tmp);
// 	return (0);
// }