/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 14:46:53 by jpascal           #+#    #+#             */
/*   Updated: 2017/09/25 14:46:57 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				add_weight(t_tube **tubes, char *name, int i)
{
	t_tube			*tmp;

	tmp = *tubes;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->roomprev->room_name, name) == 0
			&& (tmp->weight == 0 || tmp->weight > i))
		{
			tmp->weight = i;
			add_weight(tubes, tmp->roomnext->room_name, i + 1);
		}
		else if (ft_strcmp(tmp->roomnext->room_name, name) == 0
			&& (tmp->weight == 0 || tmp->weight > i))
		{
			tmp->weight = i;
			add_weight(tubes, tmp->roomprev->room_name, i + 1);
		}
		tmp = tmp->next;
	}
}

void				build_way(t_tube **tubes, char **tab, int i, char *end)
{
	t_tube			*tmpt;
	t_tube			*tmp;

	tmpt = *tubes;
	if (i >= 0)
	{
		tmp = find_smallest_weight(tubes, end);
		if (ft_strcmp(tmp->roomprev->room_name, end) == 0)
		{
			tab[i] = ft_strdup(tmp->roomnext->room_name);
			build_way(tubes, tab, i - 1, tmp->roomnext->room_name);
		}
		else if (ft_strcmp(tmp->roomnext->room_name, end) == 0)
		{
			tab[i] = ft_strdup(tmp->roomprev->room_name);
			build_way(tubes, tab, i - 1, tmp->roomprev->room_name);
		}
	}
}

void				launch_ant(char **tab, t_ant **myants)
{
	int		k;
	int		c;
	t_ant	*ants;

	ants = *myants;
	ft_putchar('\n');
	while ((ants->nb_ant - (ants->i - 1)) > 0)
	{
		k = ants->j;
		c = ants->i;
		while (k >= ants->l)
		{
			ants->i = (tab[k + 2] == NULL) ? ants->i + 1 : ants->i;
			ft_putchar('L');
			ft_putnbr(c);
			ft_putchar('-');
			ft_putstr(tab[k + 1]);
			ft_putchar(' ');
			k--;
			c++;
		}
		if (tab[2] != NULL)
			ft_putchar('\n');
		ants->j += (tab[ants->j + 2] != NULL) ? 1 : 0;
		if ((ants->nb_ant - (ants->i - 1)) <= ants->j && tab[ants->j + 2] == NULL)
			ants->l++;
	}
}

int					find_way(t_room **room, t_tube **tubes, t_ant **myants)
{
	char			*start;
	char			*end;
	char			**tab;
	t_tube			*tmp;

	if (!(start = find_start(room)))
	{
		error_manager(4);
		return (0);
	}
	add_weight(tubes, start, 1);
	if (!(end = find_end(room)))
	{
		error_manager(5);
		return (0);
	}
	tmp = find_smallest_weight(tubes, end);
	if (tmp == NULL || tmp->weight == 0)
	{
		error_manager(1);
		return (0);
	}
	tab = (char**)malloc(sizeof(char*) * (tmp->weight + 2));
	tab[tmp->weight + 1] = NULL;
	tab[tmp->weight] = ft_strdup(end);
	build_way(tubes, tab, tmp->weight - 1, end);
	launch_ant(tab, myants);
	if (tab[2] == NULL)
		ft_putchar('\n');
	clean_tab(tab);
	return (1);
}
