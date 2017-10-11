/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:06:33 by jpascal           #+#    #+#             */
/*   Updated: 2017/09/25 15:06:35 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			error_manager(int error)
{
	if (error == 1)
		ft_putstr("Error 1 : Not enough elements to resolve your lem_in");
	if (error == 2)
		ft_putstr("Error 2 : No ant. Sorry !");
	if (error == 3)
		ft_putstr("Error 3 : This room can't exists");
	if (error == 4)
		ft_putstr("Error 4 : There is no start room");
	if (error == 5)
		ft_putstr("Error 5 : There is no end room");
}

int				parse_ant(t_ant **myants, char **line)
{
	t_ant		*ants;

	ants = (t_ant*)malloc(sizeof(t_ant));
	if (get_next_line(0, line) == 1)
	{
		ft_putstr(*line);
		ft_putchar('\n');
		if (*line[0] == '#')
		{
			ft_strdel(line);
			parse_ant(myants, line);
		}
		if (!(ants->nb_ant = ft_atoi(*line)))
			return (2);
		else
		{
			*myants = ants;
			ants->i = 1;
			ants->j = 0;
			ants->l = 0;
		}
	}
	else
		return (1);
	ft_strdel(line);
	return (0);
}

int				parse_rooms(t_room **rooms, char **line)
{
	char		**tab;

	if (*line == NULL)
	{
		if (!(get_next_line(0, line) == 1))
			return (1);
		ft_putstr(*line);
		ft_putchar('\n');
	}
	tab = ft_strsplit(*line, ' ');
	if ((tab[0] != NULL && tab[1] != NULL && tab[2] != NULL) ||
		tab[0][0] == '#')
	{
		ft_strdel(line);
		if (tab[0][0] == 'L')
		{
			clean_tab(tab);
			return (3);
		}
		else
		{
			(tab[0][0] == '#' && tab[0][1] != '#') ?
				clean_tab(tab) : check_rooms(tab, rooms);
			parse_rooms(rooms, line);
		}
	}
	else if (tab[0] != NULL)
		clean_tab(tab);
	return (0);
}

int				parse_tubes(t_tube **tubes, t_room **rooms, char **line)
{
	char		**tab;

	if (*line == NULL)
	{
		if (!(get_next_line(0, line) == 1))
			return (1);
		ft_putstr(*line);
		ft_putchar('\n');
	}
	tab = ft_strsplit(*line, '-');
	if (tab[0] != NULL && tab[1] != NULL && tab[2] == NULL)
	{
		ft_strdel(line);
		if (tab[0][0] == '#' || tab[1][0] == '#')
			parse_tubes(tubes, rooms, line);
		else
		{
			add_end_tubestruct(tubes, rooms, tab[0], tab[1]);
			parse_tubes(tubes, rooms, line);
		}
	}
	ft_strdel(line);
	clean_tab(tab);
	return (0);
}

int				main(void)
{
	t_room		*rooms;
	t_tube		*tubes;
	t_ant		*myants;
	int			i;
	char		*line;

	rooms = NULL;
	tubes = NULL;
	line = NULL;
	myants = NULL;
	i = 0;
	while (i == 0 )
	{
		if (myants == NULL)
			i = parse_ant(&myants, &line);
		else if (myants != NULL && rooms == NULL)
			i = parse_rooms(&rooms, &line);
		else if (myants != NULL && rooms != NULL && tubes == NULL)
			i = parse_tubes(&tubes, &rooms, &line);
		else
		{
			ft_putchar('\n');
			i = find_way(&rooms, &tubes, &myants);
		}
	}
	error_manager(i);
	cleaner(&rooms, &tubes, &myants);
	return (0);
}
