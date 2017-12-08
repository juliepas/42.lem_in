/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:05:15 by jpascal           #+#    #+#             */
/*   Updated: 2017/09/25 15:05:17 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		clean_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void		clean_rooms(t_room **rooms)
{
	t_room	*toclean;
	t_room	*tmp;

	tmp = *rooms;
	toclean = *rooms;
	while (toclean)
	{
		tmp = toclean;
		free(toclean->room_name);
		toclean->room_name = NULL;
		free(toclean);
		toclean = tmp->next;
	}
}

void		clean_tubes(t_tube **tubes)
{
	t_tube	*toclean;
	t_tube	*tmp;

	tmp = *tubes;
	toclean = *tubes;
	while (toclean != NULL)
	{
		tmp = toclean;
		free(toclean);
		toclean = tmp->next;
	}
}

void		kill_ants(t_ant **ants)
{
	t_ant	*toclean;

	toclean = *ants;
	free(toclean);
	*ants = NULL;
	toclean = NULL;
}

void		cleaner(t_room **rooms, t_tube **tubes, t_ant **myants)
{
	clean_rooms(rooms);
	clean_tubes(tubes);
	kill_ants(myants);
}
