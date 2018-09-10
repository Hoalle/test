/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tally_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 18:13:54 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/14 19:24:56 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		tally_print(void *mem, int size)
{
	char	*str;
	int		i;

	str = mem;
	i = 0;
	while (i < size)
	{
		write(1, str + i, 1);
		i++;
	}
	return (1);
}
