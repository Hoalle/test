/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tally_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:35:11 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/12 16:36:52 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		ft_tally_print(void *mem, int size)
{
	char	*str;
	int		i;

	str = mem;
	i = 0;
	while (i < size)
		write(1, str + i++, 1);
	return (1);
}
