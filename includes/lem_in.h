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
# include "../libft/libft.h"

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

int						parse_rooms(t_room **rooms, char **line);
void					parse_tubes(t_tube **tubes, t_room **rooms,
	char **line);
int						check_rooms(char **myroom, t_room **rooms, char **line);
int						add_end_tubestruct(t_tube **tubes, t_room **rooms,
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
long int				ft_longatoi(const char *str);
void					error_manager(int error);
int						ft_strisdigit(char *str);
int						launch_gnl(char **line, int i);
int						check_start_end(t_room **room);
void					kill_ants(t_ant **ants);
int						clean(char **tab, t_room *room);

#endif
