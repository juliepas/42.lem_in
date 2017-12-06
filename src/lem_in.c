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
			return(parse_ant(myants, line));
		}
		if (!(ants->nb_ant = ft_longatoi(*line)) || ft_longatoi(*line) > 2147483647
		|| ft_longatoi(*line) < 0)
		{
			error_manager(2);
			return (0);
		}
		*myants = ants;
		ants->i = 1;
		ants->j = 0;
		ants->l = 0;
	}
	else
	{
		error_manager(1);
		return (0);
	}
	ft_strdel(line);
	return (1);
}

int				parse_rooms(t_room **rooms, char **line)
{
	char		**tab;

	if (*line == NULL)
	{
		if (!(get_next_line(0, line) == 1))
		{
			error_manager(1);
			return (0);
		}
		ft_putstr(*line);
		ft_putchar('\n');
	}
	tab = ft_strsplit(*line, ' ');
	if (tab[0] && ((tab[1] != NULL && tab[2] != NULL && tab[3] == NULL) || tab[0][0] == '#'))
	{
		ft_strdel(line);
		if (tab[0][0] == 'L' || ft_strchr(tab[0], '-'))
		{
			clean_tab(tab);
			error_manager(3);
			return (0);
		}
		if (tab[0][0] == '#' && tab[0][1] != '#')
			return(parse_rooms(rooms, line));
		if (!(check_rooms(tab, rooms, line)))
			return (0);
		return(parse_rooms(rooms, line));
	}
	else if (tab[0] != NULL)
	{
		clean_tab(tab);
	}
	return (1);
}

void			parse_tubes(t_tube **tubes, t_room **rooms, char **line)
{
	char		**tab;

	if (*line == NULL)
	{
		if (!(get_next_line(0, line) == 1))
			return ;
		ft_putstr(*line);
		ft_putchar('\n');
	}
	if (!line[0])
		return ;
	tab = ft_strsplit(*line, '-');
	if (tab[0] != NULL)
	{
		ft_strdel(line);
		if (tab[0][0] == '#')
			parse_tubes(tubes, rooms, line);
		else if (tab[1] != NULL && tab[2] == NULL)
		{
			if (!(add_end_tubestruct(tubes, rooms, tab[0], tab[1])))
				return ;
			parse_tubes(tubes, rooms, line);
		}
	}
	ft_strdel(line);
	clean_tab(tab);
}

int				main(void)
{
	t_room		*rooms;
	t_tube		*tubes;
	t_ant		*myants;
	char		*line;

	rooms = NULL;
	tubes = NULL;
	line = NULL;
	myants = NULL;
	if (!(parse_ant(&myants, &line)) || !(parse_rooms(&rooms, &line)))
	{
		cleaner(&rooms, &tubes, &myants);
		return (1);
	} 
	if (rooms == NULL)
	{
		error_manager(3);
		return (1);
	}
	parse_tubes(&tubes, &rooms, &line);
	if (!(find_way(&rooms, &tubes, &myants)))
	{
		cleaner(&rooms, &tubes, &myants);
		return (1);
	}
	return (0);
}
