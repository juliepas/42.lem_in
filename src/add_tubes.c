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

void			add_end_tubestruct(t_tube **tubes, t_room **rooms,
	char *salle1, char *salle2)
{
	t_tube	*new;
	t_room	*tmp1;
	t_room	*tmp2;
	t_tube	*tmpt;

	new = (t_tube*)malloc(sizeof(t_tube));
	tmpt = *tubes;
	tmp1 = find_room(rooms, salle1);
	tmp2 = find_room(rooms, salle2);
	new->weight = 0;
	new->roomprev = tmp1;
	new->roomnext = tmp2;
	new->next = NULL;
	if (*tubes != NULL)
	{
		while (tmpt->next != NULL)
			tmpt = tmpt->next;
		tmpt->next = new;
	}
	else
		*tubes = new;
}
