/**
 * \file centrale.h
 * \brief Fichier de déclaration du programme principal exécuté par la centrale.
 *
 */
 
#ifndef _CENTRALE_H
#define _CENTRALE_H

#include <pthread.h>
#include "com.h"

#define PORT_NAME 			"/dev/ttyAMA0"		/*!< Chemin d'accès du fichier utilisé pour lire sur le port série de la raspberry pi*/

#define F_STOP				"stop.dat"			/*!< Nom du fichier de configuration permettant de contrôler l'extinction du capteur*/
#define F_TEMPERATURE		"temperature.dat"	/*!< Nom du fichier dans lequel les températures reçues depuis le capteur sont stockées*/
#define F_FREQUENCY			"frequency.dat"		/*!< Nom du fichier de configuration permettant de contrôler la fréquence d'acquisition du capteur*/

#define WAIT_LATENCY		100 				/*!< Temps d'attente entre chaque tentative de réception d'un acquittement du capteur en millisecondes*/

void saveToFile(FILE * file, char * data);
void creationOfConfigAndDataFiles();
void checkStop(transmitter_t* t);
void checkFrequency(transmitter_t* t, int* freq);

#endif /* _CENTRALE_H */
