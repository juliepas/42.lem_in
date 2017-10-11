/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:45:58 by jpascal           #+#    #+#             */
/*   Updated: 2017/09/25 16:46:01 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct			s_ant
{
	int					nb_ant;
	int					i;
	int					j;
	int					l;
}						t_ant;

typedef struct			s_room
{
	char				*room_name;
	int					start;
	int					end;
	struct s_room		*next;
}						t_room;

typedef	struct			s_tube
{
	int					weight;
	struct s_room		*roomprev;
	struct s_room		*roomnext;
	struct s_tube		*next;
}						t_tube;

void					check_rooms(char **myroom, t_room **rooms);
void					add_end_tubestruct(t_tube **tubes, t_room **rooms,
	char *salle1, char *salle2);
int						find_way(t_room **room, t_tube **tubes, t_ant **myants);
char					*find_start(t_room **rooms);
char					*find_end(t_room **rooms);
t_tube					*find_smallest_weight(t_tube **tubes, char *end);
void					afficher_rooms(t_room **rooms);
void					afficher_tubes(t_tube **tubes);
t_room					*find_room(t_room **rooms, char *salle);
void					clean_tab(char **tab);
void					cleaner(t_room **rooms, t_tube **tubes, t_ant **ants);

#endif
