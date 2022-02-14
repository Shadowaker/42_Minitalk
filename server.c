/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:39:12 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/14 17:49:14 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_handler(int sig)
{
	static unsigned char	c = 0;
	static int				i = 0;
	int						j;

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

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR2, ft_handler);
	signal(SIGUSR1, ft_handler);
	while (1)
		;
	return (0);
}
