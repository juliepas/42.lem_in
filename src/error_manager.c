/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpascal <jpascal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:47:51 by jpascal           #+#    #+#             */
/*   Updated: 2017/12/09 17:47:59 by jpascal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			error_manager(int error)
{
	ft_putchar('\n');
	if (error == 1)
	{
		ft_putstr_fd("Error 1 : Not enough elements to ", 2);
		ft_putstr_fd("resolve your lem_in\n", 2);
	}
	if (error == 2)
		ft_putstr_fd("Error 2 : No ant or too many. Sorry !\n", 2);
	if (error == 3)
		ft_putstr_fd("Error 3 : This room can't exists\n", 2);
	if (error == 4)
		ft_putstr_fd("Error 4 : There is no start room\n", 2);
	if (error == 5)
		ft_putstr_fd("Error 5 : There is no end room\n", 2);
}
