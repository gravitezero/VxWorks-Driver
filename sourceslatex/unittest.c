/**
 * Auteurs : Paul ADENOT & Étienne Brodu.
 * Ce fichier fournit la suite de test pour le pilote
 * implémenté dans le fichier driver.c
 */

#include "driver.h"
#include <vxWorks.h>
#include <errnoLib.h>
#include <stdio.h>
#include <string.h>

/* Écrit un message d'erreur sur la sortie d'erreur */
#define ERR_MSG(x) printf("Test %d failed. errno : %d\n",(x), errnoGet());

/**
 * Test 1 - Installation d'un driver
 * Description
 * Installer le driver alors qu'il n'est pas installé
 * Resultat attendu
 * La valeur de retour doit être positive, et correspond au numéro du driver. Il doit être possible
 * de le retrouver en utilisant la fonction iosDrvShow.
 **/
int test_1()
{
	int success = 0;
	if(pe_driverInstall(10) >= 0)
	{
		success++;
		iosDrvShow();
		getchar();
		// Call this to clean the system.
	}
	else
	{
		ERR_MSG(1);
	}
	pe_driverUninstall();
	return success;
}

 /**
 * Test 2 - Installation d'un driver déjà installé
 * Description
 * Installer le driver alors qu'il est déjà installé : appeler deux fois iosDrvInstall.
 * Resultat attendu
 * La première installation doit bien se passer (valeur de retour positive). Le second appel de
 * iosDrvInstall doit renvoyer ERROR.
 **/
int test_2()
{
	int success = 0;
	if(pe_driverInstall(10))
	{
		if( pe_driverInstall(10) == -1)
		{
			success++;
		}
		else
		{
			ERR_MSG(2)
		}
	}
	else
	{
		ERR_MSG(2)
	}
		
	// Call this to clean the system.
	pe_driverUninstall();
	return success;
}
 /**
 * Test 3 - Retrait d'un driver
 * Description
 * Utilisation de la fonction iosDrvRemove, alors que le pilote est installé sur le système, et qu'il
 * n'est pas utilisé.
 * Resultat attendu
 * La valeur de retour doit être égale à OK.
 **/
int test_3()
{
	int success = 0;
	pe_driverInstall(10);
	if(pe_driverUninstall() == OK)
	{
		success++;
	}
	else
	{
		ERR_MSG(3);
	}
	return success;
}
 /**
 * Test 4 - Retrait du driver alors qu'il n'est pas installé
 * Description
 * Utilisation de la fonction iosDrvRemove, alors que le pilote n'est pas installé sur le système.
 * Resultat attendu
 * La valeur de retour doit être ERROR.
 **/
int test_4()
{
	int success = 0;
	if(pe_driverUninstall() == ERROR)
	{
		success++;
	}
	else
	{
		ERR_MSG(4)
	}
	
	return success;
}

/**
 * Test 5 - Retrait du driver alors qu'un périphérique est ouvert
 * Description
 * Alors qu'un capteur a été ouvert en lecture, retirer le driver, à l'aide de la fonction iosDrvRemove.
 * Resultat attendu
 * La fonction doit retourner ERROR, et errno doit être positionné à ECPTBUSY. Le driver ne doit
 * pas être retiré.
 */
int test_5()
{
	int success = 0;
	int fd = 0;
	Message buffer;

	pe_driverInstall(10);
	
	// Ouvertude d'un capteur.
	fd = open("/dev/capteur5", O_RDONLY, 0);	
	ioctl(fd, SET_CPT_ADDRESS, 42);
	hardware_mockup(42, "test 5\0");


	// l'attente est obligatoire sinon le message n'est pas encore traité.
	sleep(1);
	read(fd,(char*)&(buffer), sizeof(buffer));
	
	if(strncmp(buffer.msg, "test 5\0", 7) != 0)
	{
		printf("Erreur a la lecture du message\n");
	}
	
	if( fd != ERROR )
	{
		// Tentative de retrait du driver : cela doit être un échec.
		if(pe_driverUninstall() == ERROR)
		{
			if(errnoGet() == ECPTBUSY)
				success++;
			else
				printf("Pas le bon code errno : test_5\n");
		}
		else
		{
			printf("driver enleve avec succes : Echec\n");
		}
		
		close(fd);
	}
	else
	{
		printf("Erreur a l'ouverture du capteur\n");
	}	
	pe_driverUninstall();
		
	return success;
}

/**
 * Test 6 - Ajout d'un périphérique
 * Description
 * Utilisation de la fonction iosDevAdd, une seule fois, avec des paramètre valides.
 * Resultat attendu
 * La valeur de retour doit être OK, le périphérique doit être trouvable en utilisant iosDevFind, qui
 * ne doit pas renvoyer NULL.
 **/
int test_6()
{
	int success = 0;
	int fd = 0;

	// on n'installe pas de device par défaut.
	pe_driverInstall(0);
	
	// On utilise la procédure qui encapsule iosDevAdd.
	if(pe_deviceAdd(0) == OK)
	{
		if(iosDevFind("/dev/capteur0",NULL) != NULL)
		{
			success++;
		}
		else
		{
			ERR_MSG(6);
		}
	}
	else
	{
		ERR_MSG(6);
	}
	
	pe_driverUninstall();
	
	return success;
}
/**
 * Test 7 - Retrait d'un périphérique
 * Description
 * Utilisation de la fonction iosDevDelete, avec des paramètres valides.
 * Resultat attendu
 * Il ne doit plus être possible d'ouvrir le périphérique : un appel à open sur ce périphérique doit
 * échouer (il doit un nombre négatif), et errno doit être positionné à ENOENT.
 **/
int test_7()
{
	int success = 0;
	int fd = 0;

	// on n'installe pas de device par défaut.
	
	pe_driverInstall(0);
	
	// On utilise la procédure qui encapsule iosDevAdd.
	if(pe_deviceAdd(0) == OK)
	{
		if(pe_deviceRemove(0) == OK)
		{
			if(open("/dev/capteur0", O_RDONLY, 0) == ERROR)
			{
				if(errnoGet() == ENOENT)
				{
					success++;
				}
				else
				{
					ERR_MSG(7);
				}
			}
			else
			{
				printf("Il est possible d'ouvrir le device alors qu'il a été retiré : 7\n");
			}
		}
		else
		{
			printf("L'ajout a échoué : 7\n");
		}
	}
	else
	{
		printf("Erreur a l'ajout du peripherique\n");
	}

	pe_driverUninstall();
	
	return success;
}
/**
 * Test 8 - Ajout d'un périphérique alors que 15 périphériques ont été ajoutés.
 * Description
 * Utilisation de la fonction iosDevAdd sur un périphérique déjà ajouté.
 * L'appel à iosDevAdd doit provoquer une erreur, et renvoyer ERROR.
 **/
int test_8()
{
	int success = 0;
	
	if(pe_driverInstall(15) == ERROR)
	{
		return success;
	}
		
	if(pe_deviceAdd(0) == ERROR)
	{
		success++;
	}
	
	pe_driverUninstall();
	
	return success;
}
/**
 * Test 9 - Ouverture d'un capteur
 * Description
 * Appeler open sur un capteur valide (le fichier existe et est accessible en écriture), avec des options
 * valide (O_RDONLY), une seule fois.
 * Resultat attendu
 * La valeur de retour doit être un entier positif.
 **/
int test_9()
{
	int success = 0;
	int fd = 0;

	pe_driverInstall(10);
	
	// Ouvertude d'un capteur.
	fd = open("/dev/capteur0", O_RDONLY, 0);
	if( fd == ERROR )
	{
		printf("Erreur d'ouverture du peripherique\n");
	}
	else
	{
		success++;
		if(close(fd))
		{
			printf("Erreur pendant la fermeture du capteur\n");
		}
	}
	
	if(pe_driverUninstall())
	{
		printf("Erreur de désinstallation du driver\n");
	}
	
	return success;
}
/**
 * Test 10 - Ouverture d'un capteur déjà ouvert
 * Description
 * Appeler open sur un capteur valide (le fichier existe, et est accessible en lecture), alors qu'il vient
 * d'être ouvert avec succès.
 * Resultat attendu
 * open doit renvoyer ERROR, et errno doit être positionné à EALREADYOPENED.
 **/
int test_10()
{
	int success = 0;
	int fd1 = 0;
	int fd2 = 0;
	
	pe_driverInstall(10);
	
	// Ouvertude d'un capteur.
	fd1 = open("/dev/capteur0", O_RDONLY, 0);
	if( fd1 == ERROR )
	{
		printf("Erreur d'ouverture du peripherique\n");
		if( pe_driverUninstall() == ERROR )
		{
			printf("Erreur de désinstallation du driver\n");
		}
		return success;
	}
	
	fd2 = open("/dev/capteur0", O_RDONLY, 0);
	if( fd2 == ERROR )
	{
		success++;
	}
	
	close(fd2);
	
	if(close(fd1))
	{
		printf("Erreur pendant la fermeture du capteur\n");
	}
	
	if(pe_driverUninstall())
	{
		printf("Erreur a l'enlevement du driver\n");
	}
	
	return success;	
}
/**
 * Test 11 - Ouverture d'un capteur avec des paramètres invalides
 * Description
 * Appeler open sur un capteur valide (le fichier existe, et est accessible en lecture/écriture, en
 * passant un mode différent de O_RDONLY.
 * Resultat attendu
 * .
 * L'appel doit échouer, et donc renvoyer ERROR. De plus, errno doit être positionné à EARG.
 **/
int test_11()
{
	int success = 0;
	int fd = 0;
	
	pe_driverInstall(1);
	
	// Ouvertude d'un capteur.
	fd = open("/dev/capteur0", O_RDWR, 0);
	if( fd == ERROR )
	{
		if(errnoGet() == EARG)
		{
			success++;
		}
		else
		{
			printf("Mauvais errno");
		}
	}
	
	close(fd);
	
	if(pe_driverUninstall())
	{
		printf("Erreur a l'enlevement du driver\n");
	}
	
	return success;
}
/**
 * Test 12 - Fermeture d'un capteur
 * Description
 * Appeler close sur un descripteur de fichier valide (qui a été ouvert avec succès précédemment),
 * et qui n'a pas été fermé depuis.
 * Resultat attendu
 * La valeur de retour doit être égale à OK
 **/
int test_12()
{
	int success = 0;
	int fd = 0;
	
	pe_driverInstall(10);
	
	// Ouvertude d'un capteur.
	fd = open("/dev/capteur0", O_RDONLY, 0);
	if( fd != ERROR )
	{
		if(close(fd) == ERROR)
		{
			printf("Erreur a la fermeture du capteur\n");
		}
		else
		{
			success++;
		}
	}
	else
	{
		printf("Erreur a l'ouverture du capteur\n");
	}

	if(pe_driverUninstall())
	{
		printf("Erreur a l'enlevement du driver\n");
	}

	return success;
}
/**
 * Test 13 - Lecture d'une valeur dans un capteur
 * Description
 * Utiliser read sur un capteur ouvert avec succès avant puis après avoir
 * envoyé un message
 * Resultat attendu
 * La valeur de retour doit être : 
 * - ERROR avec errno sur ENOAVAIL
 * - un nombre positif, et doit être cohérente par rapport aux paramètre
 * d'appel de read.
 **/
int test_13()
{
	int success = 0;
	int fd = 0;
	
	Message buffer;
	char* data = "fake DATA :)\0";
	static int id = -1;
	struct timespec date;
	pe_driverInstall(10);
	
	// Ouvertude d'un capteur.
	fd = open("/dev/capteur2", O_RDONLY, 0);
	if(fd != ERROR)
	{
		ioctl(fd, SET_CPT_ADDRESS, 42);
		
		if(read(fd,(char*)&(buffer), sizeof(buffer)) < 0)
		{
			if(errnoGet() == ENOAVAIL)
			{
				success++;
			}
			else
			{
				printf("Erreur : mauvais message d'erreur\n");
			}
		}
		else
		{
			printf("Erreur : lecture avec succés sur un capteur vide\n");
		}
		
		hardware_mockup(42, data);
		id++;
		clock_gettime(CLOCK_REALTIME, &(date));
		// l'attente est obligatoire sinon le message n'est pas encore traité.
		sleep(1);
		if(read(fd,(char*)&(buffer), sizeof(buffer)) < 0)
		{
			printf("Erreur a la lecture %d\n", errnoGet());
		}
		else
		{
			if(date.tv_sec != buffer.date.tv_sec)
			{
				printf("Erreur : mauvaise date \n");
			}
			else
			{			
				if(strncmp(buffer.msg, data, MAX_DATA_SIZE) == 0)
				{
					success++;
				}
				else
				{
					//printf("Message:\n- id : %d\n- date : %ld:%ld\n- Message : %s\n", buffer.id, buffer.date.tv_sec, buffer.date.tv_nsec, buffer.msg);
		
					printf("Erreur : le message recus n'est pas le message envoye\n");
					//printf("envoye : %s\n", data);
					//printf("recus : %s\n", buffer.msg);
					
				}
			}
		}
		
		if(close(fd) == ERROR)
		{
			printf("Erreur a la fermeture du capteur\n");
		}
	}
	else
	{
		printf("Erreur a l'ouverture du capteur\n");
	}


	if(pe_driverUninstall() == ERROR)
	{
		printf("Erreur a l'enlevement du driver\n");
	}

	return (success == 2) ? 1 : 0;
}
/**
 * Test 14 - Utilisation de read avec une taille de lecture invalide
 * Description
 * Utilisation de l'appel système read avec un descripteur de fichier valide, mais avec une taille
 * de lecture négative.
 * Resultat attendu
 * L'appel doit échouer en renvoyant ERROR, et errno doit être positionné à EARG.
 **/
int test_14()
{
	int success = 0;
	int fd = 0;
	Message buffer;
	
	pe_driverInstall(1);
	
	// Ouvertude d'un capteur.
	fd = open("/dev/capteur0", O_RDONLY, 0);
	if(fd != ERROR)
	{
		hardware_mockup(0, "fake DATA :)\0");

		if(read(fd, (char*)&(buffer), -42) == ERROR)
		{
			success++;
		}
		
		if(close(fd) == ERROR)
		{
			printf("Erreur a la fermeture du capteur\n");
		}
	}
	else
	{
		printf("Erreur a l'ouverture du capteur\n");
	}
		

	if(pe_driverUninstall() == ERROR)
	{
		printf("Erreur a l'enlevement du driver\n");
	}
	
	return success;		
}
/**
 * Test 15 - Utilisation de ioctl avec des paramètres corrects
 * Description
 * Utilisation de ioctl avec des paramètres corrects : un descripteur de fichier valide, une valeur
 * pour request égale à la constante SET_CPT_ADDRESS, et une valeur pour value inférieur ou
 * égale à 255, correspondant bien à un capteur valide.
 * Resultat attendu
 * La valeur de retour doit être égale à OK, ou alors elle doit être égale à ERROR, mais alors errno
 * doit être positionné à ECPTBUSY, et le même appel effectué ultérieurement doit renvoyer OK.
 **/
int test_15()
{
	int success = 0;
	int fd = 0;
	
	pe_driverInstall(10);
	
	// Ouvertude d'un capteur.
	fd = open("/dev/capteur0", O_RDONLY, 0);
	if(fd != ERROR)
	{
		if(ioctl(fd, SET_CPT_ADDRESS, 42) == OK)
		{
			success++;
		}
		else
		{
			printf("Erreur lors de l'appel a ioctl\n");
		}
		
		if(close(fd) == ERROR)
		{
			printf("Erreur a la fermeture du capteur\n");
		}
	}
	else
	{
		printf("Erreur a l'ouverture du capteur\n");
	}


	if(pe_driverUninstall() == ERROR)
	{
		printf("Erreur a l'enlevement du driver\n");
	}
	
	return success;
}
/**
 * Test 16 - Utilisation de ioctl avec de mauvais arguments
 * Description
 * Utilisation de la fonction ioctl avec un second paramètre correspondant à une fonction nonimplémenté.
 * Le descripteur de fichier passé en tant que premier paramètre doit être valide, et
 * correspondre à un périphérique géré par le driver.
 * Resultat attendu
 * L'appel doit échouer (la valeur de retour doit être égale à ERROR), et errno doit être positionné
 * à EARG.
 **/
int test_16()
{
	int success = 0;
	int fd = 0;
	
	pe_driverInstall(10);
	
	// Ouvertude d'un capteur.
	fd = open("/dev/capteur0", O_RDONLY, 0);
	if(fd != ERROR)
	{
		if(ioctl(fd, 42, 42) == ERROR)
		{
			if(errnoGet() == EARG)
			{
				success++;
			}
			else
			{
				printf("Erreur : Mauvais code d'erreur\n");
			}
		}
		else
		{
			printf("Erreur lors de l'appel a ioctl\n");
		}
		
		if(close(fd) == ERROR)
		{
			printf("Erreur a la fermeture du capteur\n");
		}
	}
	else
	{
		printf("Erreur a l'ouverture du capteur\n");
	}


	if(pe_driverUninstall() == ERROR)
	{
		printf("Erreur a l'enlevement du driver\n");
	}
	
	return success;
}
/**
 * Test 17 - Utilisation de ioctl pour associer le même capteur à deux descripteur
 * de fichiers
 * Description
 * On utilise la fonction ioctl deux fois, avec des descripteurs de fichier différents, mais avec le
 * même numéro de capteur.
 * Resultat attendu
 * L'appel doit échouer, et renvoyer ERROR. errno doit alors être positionné à ECPTALREADYUSED.
 **/
int test_17()
{
	int success = 0;
	int fd0 = 0;
	int fd1 = 0;
	
	pe_driverInstall(10);
	
	// Ouvertude d'un capteur.
	fd0 = open("/dev/capteur0", O_RDONLY, 0);
	fd1 = open("/dev/capteur1", O_RDONLY, 0);
	if(fd0 != ERROR && fd1 != ERROR)
	{
		if(ioctl(fd0, SET_CPT_ADDRESS, 42) == OK)
		{
			if(ioctl(fd0, SET_CPT_ADDRESS, 42) == ERROR)
			{
				if(errnoGet() == ECPTALREADYUSED)
				{
					success++;
				}
				else
				{
					printf("Erreur : Mauvais code d'erreur\n");
				}
			}
			else
			{
				printf("Erreur : l'appel a ioctl n'a pas echoue, il existe deux capteur pointant vers la même adresse CAN\n");
			}
		}
		else
		{
			printf("Erreur lors de l'appel a ioctl sur le premier capteur\n");
		}
		
		if(close(fd0) == ERROR || close(fd1) == ERROR)
		{
			printf("Erreur a la fermeture d'un des capteurs\n");
		}
	}
	else
	{
		printf("Erreur a l'ouverture d'un des capteurs\n");
	}


	if(pe_driverUninstall() == ERROR)
	{
		printf("Erreur a l'enlevement du driver\n");
	}
	
	return success;
}
/**
 * Test 18 - Utilisation de write
 * Description
 * Appel de write sur un capteur ouvert avec succès.
 * Resultat attendu
 * L'appel doit échouer, et errno doit être positionné à ENSUP.
 **/
int test_18()
{
	int success = 0;
	int fd = 0;
	Message buffer;
	
	pe_driverInstall(1);
	
	// Ouvertude d'un capteur.
	fd = open("/dev/capteur0", O_RDONLY, 0);
	if(fd != ERROR)
	{
		if(write(fd,(char*)&(buffer), sizeof(Message)))
		{
			if(errnoGet() == ENOTSUP)
			{
				success++;
			}
			else
			{
				printf("Mauvais numero d'erreur\n");
			}
		}
		else
		{
			printf("Erreur : lecture avec succes");
		}
		
		if(close(fd) == ERROR)
		{
			printf("Erreur a la fermeture du capteur\n");
		}
	}
	else
	{
		printf("Erreur a l'ouverture du capteur\n");
	}


	if(pe_driverUninstall() == ERROR)
	{
		printf("Erreur a l'enlevement du driver\n");
	}
	
	return success;		
}

/**
 * Test 19 - Retrait d'un périphérique ouvert
 * Description
 * Tentative de retrait d'un périphérique sur lequel un appel de open a été 
 * effectué avec succès précédemment, et sur lequel on n'a pas fait d'appel
 * à close ou remove.
 * Resultat attendu
 * L'appel doit réussir : la valeur de retour doit être égale à OK.
 **/
int test_19()
{
	int success = 0;
	int fd = 0;
	pe_driverInstall(15);
	fd = creat("/dev/capteur0", O_RDONLY);
	
	if(pe_deviceRemove(0) == OK)
	{
		success++;
	}
	else
	{
		ERR_MSG(19);
	}
	pe_driverUninstall();
	return success;
}
/**
 * Test 20 - Retrait d'un périphérique qui n'existe pas
 * Description
 * Tentative de retrait d'un périphérique qui n'existe pas.
 * Resultat attendu
 * L'appel doit échouer, et retourner ERROR. errno doit être positionné à 
 * ENEXIST.
 **/
int test_20()
{
	int success = 0;
	int fd = 0;
	pe_driverInstall(15);
	// Le capteur 67 n'existe pas.
	if(pe_deviceRemove(67) == ERROR && errnoGet() == ENEXIST)
	{
		success++;
	}
	else
	{
		ERR_MSG(20);
	}
	pe_driverUninstall();
	return success;
}
void run_suite()
{
	int count = 0;
	test_1() ? count++ : printf("test_1 : ERROR\n");
	test_2() ? count++ : printf("test_2 : ERROR\n");
	test_3() ? count++ : printf("test_3 : ERROR\n");
	test_4() ? count++ : printf("test_4 : ERROR\n");
	test_5() ? count++ : printf("test_5 : ERROR\n");
	test_6() ? count++ : printf("test_6 : ERROR\n");
	test_7() ? count++ : printf("test_7 : ERROR\n");
	test_8() ? count++ : printf("test_8 : ERROR\n");
	test_9() ? count++ : printf("test_9 : ERROR\n");
	test_10() ? count++ : printf("test_10 : ERROR\n");
	test_11() ? count++ : printf("test_11 : ERROR\n");
	test_12() ? count++ : printf("test_12 : ERROR\n");
	test_13() ? count++ : printf("test_13 : ERROR\n");
	test_14() ? count++ : printf("test_14 : ERROR\n");
	test_15() ? count++ : printf("test_15 : ERROR\n");
	test_16() ? count++ : printf("test_16 : ERROR\n");
	test_17() ? count++ : printf("test_17 : ERROR\n");
	test_18() ? count++ : printf("test_18 : ERROR\n");
	test_19() ? count++ : printf("test_19 : ERROR\n");
	test_20() ? count++ : printf("test_20 : ERROR\n");
	

	if(count == 20)
	{
		printf("All tests passed successfully.\n");
	}
	else
	{
		printf("%d/20 tests passed.\n", count);
	}
}

