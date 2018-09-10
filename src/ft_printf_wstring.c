/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 13:48:44 by tgauvrit          #+#    #+#             */
/*   Updated: 2015/01/14 19:36:31 by tgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		count_wchars(wchar_t *wstr, int *size)
{
	int		i;
	int		add;
	int		total;

	i = 0;
	add = 0;
	total = 0;
	while (i < *size)
	{
		if (wstr[i] <= 0x7F)
			add = 1;
		else if (wstr[i] <= 0x7FF)
			add = 2;
		else if (wstr[i] <= 0xFFFF)
			add = 3;
		else if (wstr[i] <= 0x10FFFF)
			add = 4;
		total += add;
		i++;
	}
	*size = i;
	return (total);
}

static void		print_wchars(wchar_t *wstr, int size)
{
	int		i;
	int		total;

	total = count_wchars(wstr, &size);
	i = 0;
	while (i < size)
	{
		print_wint(wstr[i]);
		i++;
	}
}

static size_t	ft_wstrlen(wchar_t *wstr)
{
	wchar_t	*temp;

	temp = wstr;
	while (*temp != L'\0')
		temp++;
	return (temp - wstr);
}

int			print_wstr(wchar_t *wstr)
{
	int count;

	count = ft_wstrlen(wstr);
	print_wchars(wstr, ft_wstrlen(wstr));
	return (count);
}
