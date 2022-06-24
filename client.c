/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 19:34:50 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/23 20:19:44 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils/ft_utils.h"

void	signal_receiver(int sig)
{
	static int	i;

	i++;
	if (sig == SIGUSR2)
	{
		if (i == 1)
			ft_printf("Nom nom this char was delicious!\n", i);
		else if (i == 2)
			ft_printf("Wow another one, im gonna vomit xd\n", i);
		else if (i == 3)
			ft_printf("Fuck i vomited all, so sorry now im...hungry\n", i);
		else
			ft_printf("Gimme another char!\n", i);
	}
}

void	to_binary(int pid, char *argv)
{
	int				j;
	unsigned long	i;
	unsigned int	bit_max;

	j = 0;
	bit_max = 1 << (sizeof(char) * 8 - 1);
	while (argv[j])
	{
		i = 0;
		while (i < (sizeof(char) * 8))
		{
			if (argv[j] & bit_max)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			argv[j] = argv[j] << 1;
			i++;
			usleep(420);
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, signal_receiver);
	signal(SIGUSR2, signal_receiver);
	if (argc != 3)
	{
		ft_printf("Insert 3 parameters please^^\n", 1);
		return (1);
	}
	to_binary(ft_atoi(argv[1]), argv[2]);
	return (0);
}
