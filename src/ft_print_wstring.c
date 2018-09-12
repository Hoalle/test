/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wstring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:15:09 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/12 16:33:58 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int		ft_count_wchars(wchar_t *wstr, int *size)
{
	int	i;
	int	add;
	int	total;

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

static void		ft_print_wchars(wchar_t *wstr, int size)
{
	int	i;
	int	total;

	total = ft_count_wchars(wstr, &size);
	i = 0;
	while (i < size)
		ft_print_wint(wstr[i++]);
}

static size_t	ft_wstrlen(wchar_t *wstr)
{
	wchar_t *tmp;

	tmp = wstr;
	while (*tmp != L'\0')
		tmp++;
	return (tmp - wstr);
}

int				ft_print_wstr(wchar_t *wstr)
{
	int	count;

	count = ft_wstrlen(wstr);
	ft_print_wchars(wstr, ft_wstrlen(wstr));
	return (count);
}
