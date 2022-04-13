/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:25:21 by ylabbe            #+#    #+#             */
/*   Updated: 2022/04/11 16:25:44 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

typedef struct s_server
{
	unsigned char	caractere;
	int				binary;
}	t_server;

t_server	g_server;

static void	ft_sigaction(int sig, siginfo_t *info, void *context)
{
	static pid_t			client_pid = 0;

	(void)context;
	if (!client_pid)
	{
		ft_printf("-> ");
		client_pid = info->si_pid;
	}
	g_server.caractere |= (sig == SIGUSR2);
	if (++g_server.binary == 8)
	{
		g_server.binary = 0;
		if (!g_server.caractere)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			ft_printf("\n");
			return ;
		}
		ft_printf("%c", g_server.caractere);
		g_server.caractere = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		g_server.caractere = g_server.caractere << 1;
}

int	main(void)
{
	struct sigaction	s_sigaction;

	ft_printf("Voici le serveur bonus! Le PID est: %d\n", getpid());
	ft_memset(&s_sigaction, '\0', sizeof(s_sigaction));
	s_sigaction.sa_sigaction = ft_sigaction;
	sigaction(SIGUSR1, &s_sigaction, NULL);
	sigaction(SIGUSR2, &s_sigaction, NULL);
	while (1)
		pause();
	return (0);
}
