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

	if (!launch_gnl(line, 1))
		return (0);
	while (*line[0] == '#')
	{
		ft_strdel(line);
		if (!launch_gnl(line, 1))
			return (0);
	}
	if (!(ants = (t_ant*)malloc(sizeof(t_ant))))
		return (0);
	ft_bzero(ants, sizeof(t_ant));
	if (!(ants->nb_ant = ft_longatoi(*line))
		|| ft_longatoi(*line) > 2147483647 || ft_longatoi(*line) < 0)
	{
		free(ants);
		ft_strdel(line);
		error_manager(2);
		return (0);
	}
	*myants = ants;
	ants->i = 1;
	ft_strdel(line);
	return (1);
}

int				parsing(t_ant **myants, t_room **rooms, t_tube **tubes,
	char **line)
{
	if (!(parse_rooms(rooms, line)))
	{
		cleaner(rooms, tubes, myants);
		return (1);
	}
	if (!check_start_end(rooms))
	{
		ft_strdel(line);
		cleaner(rooms, tubes, myants);
		return (1);
	}
	return (0);
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
	if (!(parse_ant(&myants, &line)))
	{
		cleaner(&rooms, &tubes, &myants);
		return (1);
	}
	if (parsing(&myants, &rooms, &tubes, &line))
		return (1);
	parse_tubes(&tubes, &rooms, &line);
	if (!(find_way(&rooms, &tubes, &myants)))
	{
		cleaner(&rooms, &tubes, &myants);
		return (1);
	}
	cleaner(&rooms, &tubes, &myants);
	return (0);
}
