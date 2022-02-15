/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:39:12 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/15 19:33:50 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

void	ft_handler(int sig, siginfo_t *siginfo, void *cont)
{
	static unsigned char	c = 0;
	static int				i = 0;
	pid_t					cpid;

	c |= (sig == SIGUSR1);
	if (cont)
		;
	cpid = siginfo->si_pid;
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(cpid, SIGUSR2);
			write(1, "\n", 1);
			return ;
		}
		write(1, &c, 1);
		c = 0;
		kill(cpid, SIGUSR1);
	}
	else
		c <<= 1;
}

static void	ft_display(pid_t pid)
{
	write(1, "PID: ", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

int	main(void)
{
	struct sigaction	s_sigaction;
	pid_t				pid;

	pid = getpid();
	ft_display(pid);
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
