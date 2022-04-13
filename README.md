# 42 Québec Cursus - Minitalk

<br />
<div align="center">
	<a href="https://github.com/yanislabbe">
	<img src="images/success.png" alt="success" width="100" height="100">
	</a>
</div>


### À propos

- Vous devez réaliser un programme de communication sous la forme d'un client et d'un serveur utilisant les signaux UNIX.

### Consignes spécifiques au projet

- Les fichiers exécutables doivent être nommés "client" et "server".
- Vous devez rendre un "Makefile" qui compilera vos fichiers sources. Il ne doit pas "relink".
- Vous devez gérer les erreurs avec du bon sens. En aucun cas votre programme ne doit quitter de manière inattendue (faute de segmentation, erreur de bus, double free, etc.).
- Votre programme ne doit pas avoir de fuites de mémoire.
- Vous pouvez utiliser une variable globale par programme (une pour le client et une pour le serveur) mais leur usage doit être justifié.
- Afin de faire la partie obligatoire, vous avez le droit d'utiliser les fonctions suivantes :

- [`write`](http://manpagesfr.free.fr/man/man2/write.2.html)
- [`ft_printf] et tout équivalent que VOUS avez codé
- [`signal`](http://manpagesfr.free.fr/man/man2/signal.2.html)
- [`sigemptyset`](http://manpagesfr.free.fr/man/man3/sigsetops.3.html)
- [`sigaddset`](http://manpagesfr.free.fr/man/man3/sigsetops.3.html)
- [`sigaction`](http://manpagesfr.free.fr/man/man2/sigaction.2.html)
- [`kill`](http://manpagesfr.free.fr/man/man2/kill.2.html)
- [`getpid`](http://manpagesfr.free.fr/man/man2/getpid.2.html)
- [`malloc`](http://manpagesfr.free.fr/man/man3/malloc.3.html)
- [`free`](http://manpagesfr.free.fr/man/man3/malloc.3.html)
- [`pause`](http://manpagesfr.free.fr/man/man2/pause.2.html)
- [`sleep`](http://manpagesfr.free.fr/man/man3/sleep.3.html)
- [`usleep`](http://manpagesfr.free.fr/man/man3/usleep.3.html)
- [`exit`](http://manpagesfr.free.fr/man/man3/exit.3.html)

### Partie obligatoire

- Le serveur doit être lancé en premier et doit, après le lancement, afficher son PID.
- Le client prend deux paramètres :
	- Le PID du serveur.
	- Une chaîne de caractères à transmettre.
- Le client doit communiquer au serveur la chaîne passée en paramêtre. Une fois la chaîne entièrement reçue, le serveur doit l'afficher.
- Le serveur doit être capable d'afficher la chaîne rapidement. Par rapidement, on entend que si vous pensez que c'est trop long, alors c'est sûrement trop long.
- Votre serveur doit pouvoir recevoir des chaînes de plusieurs clients à la suite sans nécessiter d'être relancé.
- La communication entre vos programmes doit se faire uniquement à l'aide de signaux UNIX.
- Vous ne pouvez utiliser que les deux signaux suivants : SIGUSR1 et SIGUSR2.

### Partie bonus

- Le serveur confirme la réception de chaque message en envoyant un signal au client.
- Le support des caractères Unicode!

## Auteur

- Yanis Labbé
