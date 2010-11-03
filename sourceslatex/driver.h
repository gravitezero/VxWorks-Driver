/**
 * Auteur : Paul ADENOT & Etienne Brodu
 * Ce fichier fournit les en-têtes pour le pilote implémenté dans le fichier
 * driver.c
 */

#include <iosLib.h>
#include <time.h>


/* La taille maximale des données d'un message (\0 compris)*/
#define MAX_DATA_SIZE 64
/* La taille maximale d'un nom de capteur (chemin complet, et \0 compris) */
#define NAME_SIZE 32

/**
 * L'état d'un capteur : il peut être fermé, ouvert, ou pas encore
 * crée.
 */
typedef enum
{
	closed,   //!< closed Le capteur est fermé.
	opened,   //!< opened Le capteur est ouvert.
	notcreated//!< notcreated L'indice n'a pas de capteur associé.
} EtatCapteur;


/**
 * Les données spécifiques d'une structure PEDEV.
 */
typedef struct
{
	char name[NAME_SIZE]; ///< name Le nom du capteur.
	EtatCapteur state; ///< state L'état du capteur.
	int address; ///< address L'adresse CAN du capteur.
} specific_t;

/**
 * Membre d'une liste chainée gérée par l'ios. Contient des
 * des informations de gestion dans le membre specific.
 */
typedef struct  
{
	DEV_HDR header;
	specific_t specific;
} PEDEV;

/**
 * Structure représentant un message.
 */
typedef struct
{
	unsigned id; ///< id identifiant du message
	struct timespec date; ///< date date de reception
	char msg[MAX_DATA_SIZE]; ///< msg contenu
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
	ECPTALREADYUSED, /** Le capteur est deja associe a un autre peripherique */
	ENOAVAIL, /** Aucun message n'est disponible */
	EINSTALLED, /** Le pilote est déjà installé */
	ENINSTALLED, /** Le pilote n'est pas installé */
	ETOOMUCHDEV, /** Nombre de périphériques demandé superieur à ceux disponible */
	EUNKNOW, /** Erreur inconnue */
	ECANNOTADD /** Impossible d'ajouter un capteur */
};

/**
 * Valeurs possibles de request pour ioctl.
 */
typedef enum {
	SET_CPT_ADDRESS /** Changer l'adresse d'un capteur */
};

int pe_driverInstall(int dev_count);
int pe_driverUninstall();
int pe_deviceAdd(int i);
int pe_deviceRemove(int i);

void hardware_mockup(int address, char* data);
