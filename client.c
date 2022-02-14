/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:39:14 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/14 17:49:05 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_talker(pid_t pid, char c)
{
	int	i;

	i = 8;
	while(i--)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

void	ft_Head(pid_t pid, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_talker(pid, s[i]);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = ft_atoi(argv[1]);
	ft_Head(pid, argv[2]);
	return (0);
}
