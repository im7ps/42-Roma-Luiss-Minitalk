/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:32:55 by sgerace           #+#    #+#             */
/*   Updated: 2022/06/23 17:20:21 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils/ft_utils.h"

void	my_handler(int my_signal, siginfo_t *info, void *ucontext)
{
	int			children_pid;
	static char	c = 0;
	static int	chars_bit = 0;

	(void)ucontext;
	if (info -> si_pid)
		children_pid = info -> si_pid;
	c = c | (my_signal == SIGUSR1);
	if (++chars_bit == 8)
	{
		ft_printf("%c", c);
		chars_bit = 0;
		c = 0;
		kill(children_pid, SIGUSR2);
	}
		c <<= 1;
}

int	main(void)
{
	struct sigaction	my_sa;

	ft_printf("il PID del server é: %d\n", getpid());
	my_sa.sa_flags = SA_SIGINFO;
	my_sa.sa_sigaction = my_handler;
	sigaction(SIGUSR1, &my_sa, NULL);
	sigaction(SIGUSR2, &my_sa, NULL);
	while (1)
		pause();
	return (0);
}
