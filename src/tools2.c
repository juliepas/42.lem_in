/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 18:31:01 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/06 18:31:03 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_strisdigit(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-')
		i = 1;
	while (str[i] && str[i] > 33)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

int				launch_gnl(char **line, int i)
{
	if (!(get_next_line(0, line) == 1))
	{
		if (i)
			error_manager(i);
		return (0);
	}
	ft_putstr(*line);
	ft_putchar('\n');
	return (1);
}

int				check_start_end(t_room **room)
{
	char			*start;
	char			*end;

	if (!(start = find_start(room)))
	{
		error_manager(4);
		return (0);
	}
	if (!(end = find_end(room)))
	{
		error_manager(5);
		return (0);
	}
	return (1);
}

int				clean(char **tab, t_room *new)
{
	clean_tab(tab);
	free(new);
	error_manager(3);
	return (0);
}

int				ft_antisdigit(char *str)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57) && str[i] >= 33)
			return (0);
		if (str[i - 1] > 48 && str[i - 1] < 57 && str[i] < 33)
			j = 1;
		if (str[i] > 48 && str[i] < 57 && j == 1)
			return (0);
		i++;
	}
	return (1);
}
