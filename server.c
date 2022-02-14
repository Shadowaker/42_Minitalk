/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:39:12 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/14 22:12:44 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_handler(int sig)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		write(1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

static void	ft_display(pid_t pid)
{
	write(1, "PID: ", 5);
	write(1, &pid, 1);
	write(1, "\n", 1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_display(pid);
	signal(SIGUSR2, ft_handler);
	signal(SIGUSR1, ft_handler);
	while (1)
		;
	return (0);
}
