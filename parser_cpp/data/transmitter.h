/**
 * \file transmitter.h
 * \brief 	Fichier de déclaration d'une structure de données permettant de gérer la transmission
 *			multithreadée de trames entre la centrale et le capteur.
 *
 */
#ifndef _TRANSMITTER_H
#define _TRANSMITTER_H

#include <fcntl.h>
#include <stdio.h>
#include <termios.h>

#include "buffer.h"

/* ATTENTION : ces valeur doivent TOUJOURS être plus petites que NODE_SIZE_MAX (node.h). */
#define BUFFER_SIZE 128		/*!< Taille du buffer temporaire dans lequel sont stockées les trames*/

/* Liste des états possibles du transmetteur. */
#define TRS_STOP_STATE 0	/*!< Constante qui indique que le transmetteur est en état d'arrêt et que la transmission de trame doit cesser*/
#define TRS_RUN_STATE 1		/*!< Constante qui indique que le transmetteur est en état de marche, c'est-à-dire qu'il doit transmettre des trames */

/**
 * \struct transmitter_t 
 *
 * \brief 	Structure de données utilisées pour l'échange de trame entre le capteur
 *			et la centrale.
 *
 *	La structure contient un buffer d'émission et un buffer de reception dans lesquels sont stockées
 *	les trames avant d'être envoyées ou reçues. L'envoi et la reception des trames s'effectue dans une
 *	fonction exécutée à travers un thread de manière continue. Ainsi la reception et l'emission des trames
 *	stockées dans les buffers s'effectue de manière permanente tant que l'état du transmetteur est à 
 *	TRS_RUN_STATE.
 *	
 */
typedef struct transmitter 
{
	buffer_t* inbox;	/*!< Buffer de reception dans lequel les trames reçues sont stockées. */
	buffer_t* outbox;	/*!< Buffer d'émission dans lequel les trames stockées avant d'être émises. */
	char* port_name;	/*!< Nom du fichier de périphérique sur lequel le transmetteur doit écrire. */
	char delimiter;		/*!< Caractère permettant de délimiter deux trames au moment de la lecture. */
	int state;			/*!< Etat du transmetteur. */
} transmitter_t;


	int trs_openPort(char* name);
transmitter_t* trs_create(const char* port_name, char delimiter);
void trs_destroy(transmitter_t* t);
void* trs_process(void* ptr);
void trs_stop(transmitter_t* t);
void trs_fetch(transmitter_t* t, char* oInstr);
void trs_post(transmitter_t* t, const char* iInstr);

#endif /* _TRANSMITTER_H */
