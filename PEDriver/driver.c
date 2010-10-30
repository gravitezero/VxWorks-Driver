/**
 * Auteurs : Paul ADENOT & Etienne BRODU
 * Ce fichier fournit l'implémentation d'un pilote de périphérique VxWorks, capable
 * de fournir un moyen d'interroger des capteurs sur un bus CAN.
 */


#include "driver.h"
#include <string.h>
#include <stdlib.h>
#include <errnoLib.h>
#include <stdio.h>

/**
 * Constantes internes.
 */
/* Nom d'un périphérique. Doit être utilisé avec sprintf pour
 * indiquer son numéro */
#define DEVICE_BASENAME "/dev/capteur%d"

/* Nombre maximal de périphérique installables */
#define DEVICE_MAX_COUNT (15)



/**
 * Globaux
 */
/** driver_id vaut -1 si le driver n'est pas installé.
 * Il est égal au numéro du driver sinon.
 */
static int driver_id = -1;
static Message table_buffer[DEVICE_MAX_COUNT];
static PEDEV table_capt[DEVICE_MAX_COUNT];
/***
 * Fonctions du driver : implémentation des appels systèmes.
 ***/

/**
 * 
 * @param desc
 * @param name
 * @param flag
 * @return
 */
static int pe_open(PEDEV* desc, char* name, int flag) 
{
	return ERROR;
}

static int pe_close(PEDEV* desc, char* name)
{
	return ERROR;
}

/**
 * 
 * @param desc
 * @param buff
 * @param nBytes
 * @return
 */
static int pe_read (PEDEV* desc, char* buff, int nBytes) 
{
	return ERROR;
}

/**
 * 
 * @param desc
 * @param buff
 * @param nBytes
 * @return
 */
static int pe_write (PEDEV* desc, char* buff, int nBytes) 
{
	return ERROR;
}

/**
 * 
 * @param desc
 * @param request
 * @param value
 * @return OK en cas de succès, ERROR sinon.
 */
static int pe_ioctl (PEDEV* desc, int request, int value) 
{
	return ERROR;
}

/***
 * Fonction d'administration du driver : interface
 ***/

/**
 * @brief Installation du périphérique.
 * 
 * Cette fonction peut aussi créer aussi un nombre parametrable de périphériques.
 * 
 * @param dev_count Le nombre de périphériques à créer.
 * 
 * @return OK si la fonction s'est executé normalement, ERROR sinon.
 */
int pe_driverInstall(int dev_count)
{
	/* iteration pour la création des périphériques */
	int i;
	
	
	if(dev_count > DEVICE_MAX_COUNT)
	{
		errnoSet(ETOOMUCHDEV);
		return ERROR;
	}
	
	if(driver_id != -1)
	{
		printf("already installed.");
		// errnoSet(EINSTALLED);
		return ERROR;
	}
	
	/* Driver installation */
	driver_id = iosDrvInstall(pe_open,pe_close, pe_open, pe_close, pe_read, 0, pe_ioctl);
	if(driver_id < 0)
	{
		errnoSet(EUNKNOW);
		return ERROR;
	}
	
	for(i=0; i < DEVICE_MAX_COUNT; i++)
	{
		table_capt[i].specific.address = -1;
		table_capt[i].specific.state = notcreated;
	}
	
	for(i=0; i < dev_count; ++i)
	{
		pe_deviceAdd(i);
	}
	return driver_id;
}

/**
 * @brief Retirer le driver.
 * @return OK en cas de succès, ERROR sinon.
 */
int pe_driverUninstall()
{
	if(driver_id != -1)
	{
		int ret = 0;
		ret = iosDrvRemove(driver_id, FALSE);
		// The driver has open files.
		if(ret == ERROR)
		{
			errnoSet(ECPTBUSY);
			return ERROR;
		}
	}
	else
	{
		errnoSet(ENINSTALLED);
		return ERROR;
	}
	// TODO : delete the data structure eventually allocated
	// at the installation.
	driver_id = -1;
	return OK;
}

/**
 * @brief Ajouter un périphérique.
 * @param i
 * @return OK en cas de succès, ERROR sinon.
 */
int pe_deviceAdd(int i)
{
	// Buffer pour le nom de périphérique.
	char dev_name[32];

	sprintf(dev_name, DEVICE_BASENAME, i);
	if(iosDevAdd((DEV_HDR*)&(table_capt[i]),dev_name,driver_id) == ERROR)
	{
		errnoSet(ECANNOTADD);
		return ERROR;
	}
	
	// Le capteur est fermé
	table_capt[i].specific.state = closed;
	// Il n'a pas encore de capteur associé, au niveau CAN.
	// utiliser ioctl pour lui en founir une.
	table_capt[i].specific.address = -1;
	return OK;
}

/**
 * @brief Enlever un périphérique.
 * @param i L'index du device à enlever
 * @return OK pour un succès, ERROR sinon. 
 */
int pe_deviceRemove(int i)
{
	if(i < DEVICE_MAX_COUNT && table_capt[i].specific.state != notcreated)
	{	
		iosDevDelete((DEV_HDR*)&(table_capt[i]));
		return OK;
	}
	else
	{
		// Le capteur n'a pas été crée :
		// " If the device was never added to the device list, 
		//   unpredictable results may occur."
		errnoSet(ENEXIST);
		return ERROR;
	}
}
