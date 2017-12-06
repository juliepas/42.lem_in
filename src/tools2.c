
#include "lem_in.h"

int				ft_strisdigit(char *str)
{
	int i;

	i = 0;
	while(str[i] && str[i] > 33)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

void			error_manager(int error)
{
	ft_putchar('\n');
	if (error == 1)
		ft_putstr("Error 1 : Not enough elements to resolve your lem_in\n");
	if (error == 2)
		ft_putstr("Error 2 : No ant or too many. Sorry !\n");
	if (error == 3)
		ft_putstr("Error 3 : This room can't exists\n");
	if (error == 4)
		ft_putstr("Error 4 : There is no start room\n");
	if (error == 5)
		ft_putstr("Error 5 : There is no end room\n");
}
