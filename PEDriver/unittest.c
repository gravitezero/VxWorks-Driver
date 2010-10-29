/**
 * Auteurs : Paul ADENOT & Étienne Brodu.
 * Ce fichier fournit la suite de test pour le pilote
 * implémenté dans le fichier driver.c
 */

/**
 * Test 1 – Installation d’un driver
 * Description
 * Installer le driver alors qu’il n’est pas installé
 * Resultat attendu
 * La valeur de retour doit être positive, et correspond au numéro du driver. Il doit être possible
 * de le retrouver en utilisant la fonction iosDrvShow.
 **/
int test_1()
{

}

 /**
 * Test 2 – Installation d’un driver déjà installé
 * Description
 * Installer le driver alors qu’il est déjà installé : appeler deux fois iosDrvInstall.
 * Resultat attendu
 * La première installation doit bien se passer (valeur de retour positive). Le second appel de
 * iosDrvInstall doit renvoyer ERROR.
 **/
int test_2()
{

}
 /**
 * Test 3 – Retrait d’un driver
 * Description
 * Utilisation de la fonction iosDrvRemove, alors que le pilote est installé sur le système, et qu’il
 * n’est pas utilisé.
 * Resultat attendu
 * La valeur de retour doit être égale à OK.
 **/
int test_3()
{
	
}
 /**
 * Test 4 – Retrait du driver alors qu’il n’est pas installé
 * Description
 * Utilisation de la fonction iosDrvRemove, alors que le pilote n’est pas installé sur le système.
 * Resultat attendu
 * La valeur de retour doit être ERROR.
 **/
int test_4()
{
	
}
/**
 * Test 5 – Retrait du driver alors qu’un périphérique est ouvert
 * Description
 * Alors qu’un capteur a été ouvert en lecture, retirer le driver, à l’aide de la fonction iosDrvRemove.
 * Resultat attendu
 * La fonction doit retourner OK, et le périphérique doit être fermé.
 **/
int test_5()
{
	
}
/**
 * Test 6 – Ajout d’un périphérique
 * Description
 * Utilisation de la fonction iosDevAdd, une seule fois, avec des paramètre valides.
 * Resultat attendu
 * La valeur de retour doit être OK, le périphérique doit être trouvable en utilisant iosDevFind, qui
 * ne doit pas renvoyer NULL.
 **/
int test_6()
{
	
}
/**
 * Test 7 – Retrait d’un périphérique
 * Description
 * Utilisation de la fonction iosDevDelete, avec des paramètres valides.
 * Resultat attendu
 * Il ne doit plus être possible d’ouvrir le périphérique : un appel à open sur ce périphérique doit
 * échouer (il doit retourner ERROR), et errno doit être positionné à ENEXIST.
 **/
int test_7()
{
	
}
/**
 * Test 8 – Ajout d’un périphérique alors que 15 périphériques ont été ajoutés.
 * Description
 * Utilisation de la fonction iosDevAdd, 16 fois, avec des paramètres valides.
 * Resultat attendu
 * Le 16e appel à iosDevAdd doit provoquer une erreur, et renvoyer ERROR.
 **/
int test_8()
{
	
}
/**
 * Test 9 – Ouverture d’un capteur
 * Description
 * Appeler open sur un capteur valide (le fichier existe et est accessible en écriture), avec des options
 * valide (O_RDONLY), une seule fois.
 * Resultat attendu
 * La valeur de retour doit être un entier positif.
 **/
int test_9()
{
	
}
/**
 * Test 10 – Ouverture d’un capteur déjà ouvert
 * Description
 * Appeler open sur un capteur valide (le fichier existe, et est accessible en lecture), alors qu’il vient
 * d’être ouvert avec succès.
 * Resultat attendu
 * open doit renvoyer ERROR, et errno doit être positionné à EALREADYOPENED.
 **/
int test_10()
{
	
}
/**
 * Test 11 – Ouverture d’un capteur avec des paramètres invalides
 * Description
 * Appeler open sur un capteur valide (le fichier existe, et est accessible en lecture/écriture, en
 * passant un mode différent de O_RDONLY.
 * Resultat attendu
 * .
 * L’appel doit échouer, et donc renvoyer ERROR. De plus, errno doit être positionné à EARG.
 **/
int test_11()
{
	
}
/**
 * Test 12 – Fermeture d’un capteur
 * Description
 * Appeler close sur un descripteur de fichier valide (qui a été ouvert avec succès précédemment),
 * et qui n’a pas été fermé depuis.
 * Resultat attendu
 * La valeur de retour doit être égale à OK
 **/
int test_12()
{
	
}
/**
 * Test 13 – Lecture d’une valeur dans un capteur
 * Description
 * Utiliser read sur un capteur ouvert avec succès
 * Resultat attendu
 * La valeur de retour doit être un nombre positif, et doit être cohérente par rapport aux paramètre
 * d’appel de read.
 **/
int test_13()
{
	
}
/**
 * Test 14 – Utilisation de read avec une taille de lecture invalide
 * Description
 * Utilisation de l’appel système read avec une descripteur de fichier valide, mais avec une taille
 * de lecture négative.
 * Resultat attendu
 * L’appel doit échouer en renvoyant -1, et errno doit être positionné à EARG.
 **/
int test_14()
{
	
}
/**
 * Test 15 – Utilisation de ioctl avec des paramètres corrects
 * Description
 * Utilisation de ioctl avec des paramètres corrects : un descripteur de fichier valide, une valeur
 * pour request égale à la constante CHANGEMENT_CAPTEUR, et une valeur pour value inférieur ou
 * égale à 255, correspondant bien à un capteur valide.
 * Resultat attendu
 * La valeur de retour doit être égale à OK, ou alors elle doit être égale à ERROR, mais alors errno
 * doit être positionné à EBUSY, et le même appel effectué ultérieurement doit renvoyer OK.
 **/
int test_15()
{
	
}
/**
 * Test 16 – Utilisation de ioctl avec de mauvais arguments
 * Description
 * Utilisation de la fonction ioctl avec un second paramètre correspondant à une fonction nonimplémenté.
 * Le descripteur de fichier passé en tant que premier paramètre doit être valide, et
 * correspondre à un périphérique géré par le driver.
 * Resultat attendu
 * L’appel doit échouer (la valeur de retour doit être égale à ERROR), et errno doit être positionné
 * à EARG.
 **/
int test_16()
{
	
}
/**
 * Test 17 – Utilisation de ioctl pour associer le même capteur à deux descripteur
 * de fichiers
 * Description
 * On utilise la fonction ioctl deux fois, avec des descripteurs de fichier différents, mais avec le
 * même numéro de capteur.
 * Resultat attendu
 * L’appel doit échouer, et renvoyer ERROR. errno doit alors être positionné à EARG.
 **/
int test_17()
{
	
}
/**
 * Test 18 – Utilisation de write
 * Description
 * Appel de write sur un capteur ouvert avec succès.
 * Resultat attendu
 * L’appel doit échouer, et errno doit être positionné à ENOTSUP.
 **/
int test_18()
{
	
}
