/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:51:42 by jpascal           #+#    #+#             */
/*   Updated: 2017/09/25 14:51:44 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_end_roomstruct(t_room **rooms, t_room **new, char *roomname)
{
	t_room		*tmp1;
	t_room		*tmp2;

	tmp1 = *new;
	tmp2 = *rooms;
	tmp1->room_name = ft_strdup(roomname);
	tmp1->next = NULL;
	if (*rooms != NULL)
	{
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp1;
	}
	else
		*rooms = tmp1;
}

void			add_start_end(char **tab, t_room **rooms, t_room **new)
{
	t_room		*tmp;
	t_room		*tmpn;

	tmp = *rooms;
	tmpn = *new;
	if (ft_strcmp(tab[0], "##start") == 0)
	{
		while (tmp)
		{
			tmp->start = 0;
			tmp = tmp->next;
		}
		tmp = *rooms;
		tmpn->start = 1;
	}
	else if (ft_strcmp(tab[0], "##end") == 0)
	{
		while (tmp)
		{
			tmp->end = 0;
			tmp = tmp->next;
		}
		tmpn->end = 1;
	}
}

int			check_rooms(char **tab, t_room **rooms, char **line)
{
	t_room		*new;
	char		*str;

	new = (t_room*)malloc(sizeof(t_room));
	ft_bzero(new, sizeof(t_room));
	while (tab[0][0] == '#')
	{
		if (tab[0][0] == '#' && tab[0][1] == '#')
			add_start_end(tab, rooms, &new);
		clean_tab(tab);
		if (get_next_line(0, line) == 1)
		{
			ft_putstr(*line);
			ft_putchar('\n');
			tab = ft_strsplit(*line, ' ');
			ft_strdel(line);
		}
	}
	if (tab[0] != NULL && tab[1] && tab[2] && !(find_room(rooms, tab[0])) && ft_strisdigit(tab[1]) && ft_strisdigit(tab[2]))
	{
		str = ft_strtrim(tab[0]);
		add_end_roomstruct(rooms, &new, str);
		ft_strdel(&str);
	}
	else 
	{
		error_manager(3);
		return (0);
	}
	clean_tab(tab);
	return (1);
}
