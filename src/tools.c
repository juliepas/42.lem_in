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

long int					ft_longatoi(const char *str)
{
	int				i;
	int				s;
	long int		nb;

	s = 1;
	nb = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == 45)
	{
		s = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * s);
}


char			*find_start(t_room **rooms)
{
	t_room		*tmp;

	tmp = *rooms;
	while (tmp != NULL)
	{
		if (tmp->start == 1)
			return (tmp->room_name);
		tmp = tmp->next;
	}
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
	while (tmp && ft_strcmp(tmp->room_name, salle) != 0)
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
