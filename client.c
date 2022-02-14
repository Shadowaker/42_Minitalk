/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dridolfo <dridolfo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:39:14 by dridolfo          #+#    #+#             */
/*   Updated: 2022/02/14 22:16:51 by dridolfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static void	ft_talker(pid_t pid, char c)
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

static void	ft_Head(pid_t pid, char *s)
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

static void	ft_handler(int sig)
{
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		write(1, "\33[91mError: Not enough arguments.\033[0m\n",
		ft_strlen("\33[91mError: Not enough arguments.\033[0m\n"));
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_Head(pid, argv[2]);
	signal(SIGUSR2, ft_handler);
	signal(SIGUSR1, ft_handler);
	return (0);
}
