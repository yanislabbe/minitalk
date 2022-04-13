/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylabbe <ylabbe@student.42quebec.c>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 22:37:07 by ylabbe            #+#    #+#             */
/*   Updated: 2022/04/11 19:06:51 by ylabbe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* Fonction pour gérer les signals.
 * On envoie le SIGUSR1++
 * On ferme le SIGUSR2, (client) */
void	gestionnaire_signal(int sig)
{
	static int	caractere_recu = 0;

	if (sig == SIGUSR1)
		++caractere_recu;
	else
		exit(0);
}

/*	while (*chaine_caractere) : permet de lire les caractères, exemple : 0
 *	else 0, else 0, if 1, if 1, else 0, else 0, else 0, else 0
 *	while (binary > 0) : permet de '\n' sur le serveur */
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
		return (1);
	signal(SIGUSR1, gestionnaire_signal);
	signal(SIGUSR2, gestionnaire_signal);
	envoyer_signal(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
