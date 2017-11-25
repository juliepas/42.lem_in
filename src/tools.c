/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:46:47 by jpascal           #+#    #+#             */
/*   Updated: 2017/09/25 16:46:49 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char			*find_start(t_room **rooms)
{
	t_room		*tmp;

	tmp = *rooms;
	while (tmp != NULL && tmp->start == 0)
		tmp = tmp->next;
	if (tmp != NULL)
		return (tmp->room_name);
	else
		return (NULL);
}

char			*find_end(t_room **rooms)
{
	t_room		*tmp;

	tmp = *rooms;
	while (tmp != NULL && tmp->end == 0)
		tmp = tmp->next;
	if (tmp != NULL)
		return (tmp->room_name);
	else
		return (NULL);
}

t_room			*find_room(t_room **rooms, char *salle)
{
	t_room		*tmp;

	tmp = *rooms;
	while (ft_strcmp(tmp->room_name, salle) != 0)
		tmp = tmp->next;
	return (tmp);
}

t_tube			*find_smallest_weight(t_tube **tubes, char *end)
{
	t_tube		*tmp;
	t_tube		*tmpt;
	int			smallestweight;

	tmp = *tubes;
	tmpt = *tubes;
	smallestweight = 0;
	while (tmp)
	{
		if (tmp->weight > smallestweight)
			smallestweight = tmp->weight;
		tmp = tmp->next;
	}
	while (tmpt)
	{
		if ((ft_strcmp(tmpt->roomprev->room_name, end) == 0 ||
		ft_strcmp(tmpt->roomnext->room_name, end) == 0) &&
			tmpt->weight <= smallestweight)
		{
			tmp = tmpt;
			smallestweight = tmpt->weight;
		}
		tmpt = tmpt->next;
	}
	return (tmp);
}
