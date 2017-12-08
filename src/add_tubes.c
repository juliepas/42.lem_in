/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tubes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:03:34 by jpascal           #+#    #+#             */
/*   Updated: 2017/09/25 15:03:36 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				add_end_tubestruct(t_tube **tubes, t_room **rooms,
	char *salle1, char *salle2)
{
	t_tube		*new;
	t_room		*tmp1;
	t_room		*tmp2;
	t_tube		*tmpt;

	if (!(new = (t_tube*)malloc(sizeof(t_tube))))
		return (0);
	tmpt = *tubes;
	tmp1 = find_room(rooms, salle1);
	tmp2 = find_room(rooms, salle2);
	new->weight = 0;
	if (!tmp1 || !tmp2)
	{
		free(new);
		return (0);
	}
	new->roomprev = tmp1;
	new->roomnext = tmp2;
	if (tmpt != NULL)
		new->next = tmpt;
	else
		new->next = NULL;
	*tubes = new;
	return (1);
}

void			parse_tubes(t_tube **tubes, t_room **rooms, char **line)
{
	char		**tab;

	if (*line == NULL)
		if (!(launch_gnl(line, 0)))
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
			{
				clean_tab(tab);
				return ;
			}
			parse_tubes(tubes, rooms, line);
		}
		else
			error_manager(3);
	}
	ft_strdel(line);
	clean_tab(tab);
}
