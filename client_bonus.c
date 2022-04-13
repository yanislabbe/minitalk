/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:25:02 by ylabbe            #+#    #+#             */
/*   Updated: 2022/04/11 19:08:42 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	gestionnaire_signal(int sig)
{
	static int	caractere_recu = 0;

	if (sig == SIGUSR1)
		++caractere_recu;
	else
	{
		ft_printf("Nombre de caractère traité: %d\n", caractere_recu);
		exit(0);
	}
}

void	envoyer_signal(int pid, char *chaine_caractere)
{
	int		binary;

	while (*chaine_caractere)
	{
		binary = 128;
		while (binary > 0)
		{
			if (binary & *chaine_caractere)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			binary /= 2;
			usleep(100);
		}
		chaine_caractere++;
	}
	binary = 8;
	while (binary > 0)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("ERREUR!! Il faut absolument DEUX arguments.\n");
		return (1);
	}
	ft_printf("Nombre de caractère envoyé au serveur: %d\n", ft_strlen(argv[2]));
	signal(SIGUSR1, gestionnaire_signal);
	signal(SIGUSR2, gestionnaire_signal);
	envoyer_signal(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
