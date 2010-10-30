/**
 * Auteur : Paul ADENOT & Etienne Brodu
 * Ce fichier fournit les en-têtes pour le pilote implémenté dans le fichier
 * driver.c
 */

#include <iosLib.h>
#include <time.h>



#define MAX_MSG_SIZE 64

typedef enum
{
	closed,
	opened,
	notcreated
} EtatCapteur;


typedef struct
{
	EtatCapteur state; // identifiant logique du capteur.
	int address; // l'adresse CAN du capteur
} specific_t;

typedef struct  
{
	DEV_HDR header;
	specific_t specific;
} PEDEV;

typedef struct
{
	unsigned ID; // identifiant du message
	struct timespec date; // date de reception
	char msg[MAX_MSG_SIZE]; // contenu
} Message;


/**
 * Valeurs possibles de errno pour ce pilote.
 */
typedef enum {
	EARG, /** Problème d'arguments */
	ENEXIST, /** Le capteur n'existe pas */
	EALREADYOPENED, /** Le capteur est déjà ouvert */
	ENOTOPENED, /** Le capteur n'est pas ouvert */
	ECPTBUSY, /** Le capteur est en cours d'utilisation */
	ENOAVAIL, /** Aucun message n'est disponible */
	EINSTALLED, /** Le pilote est déjà installé */
	ENINSTALLED, /** Le pilote n'est pas installé */
	ETOOMUCHDEV, /** Nombre maximal de périphériques installés atteint */
	EUNKNOW, /** Erreur inconnue */
	ECANNOTADD /** Impossible d'ajouter un capteur */
};

int pe_driverInstall(int dev_count);
int pe_driverUninstall();
int pe_deviceAdd(int i);
int pe_deviceRemove(int i);
