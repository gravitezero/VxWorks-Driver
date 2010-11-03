typedef struct  
{
	DEV_HDR header;
	specific_t specific;
} PEDEV;

typedef struct
{
	char name[NAME_SIZE]; ///< name Le nom du capteur.
	EtatCapteur state; ///< state L'etat du capteur.
	int address; ///< address L'adresse CAN du capteur.
} specific_t;