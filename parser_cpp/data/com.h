/**
 * \file com.h
 * \brief 	Fichier de déclaration de fonctions permettant l'envoi de trames entre le
 *			capteur et la centrale.
 */
#ifndef _COM_H
#define _COM_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>                            
#include <termios.h>
#include <time.h>   

#include "transmitter.h"

#ifndef __DEBUG__						/*!< Compilation en mode DEBUG*/
#define __DEBUG__
#endif

#define GENERATE_DELAY 1000000/freq		/*!< Délai généré entre l'envoi de plusieurs trames de température, correspond à la fréquence d'acquisition du capteur*/

#ifdef __DEBUG__
	#define TIMEOUT_VALUE 3				/*!< Temps d'attente avant de réitérer l'envoi d'une trame non acquitée par la centrale*/
	#define ACK_CHECK_DELAY 1000000		/*!< Temps d'attente entre chaque tentative de reception d'acquittement*/
#else
	#define TIMEOUT_VALUE 1000			/*!< Temps d'attente avant de réitérer l'envoi d'une trame non acquitée par la centrale*/
	#define ACK_CHECK_DELAY 1000		/*!< Temps d'attente entre chaque tentative de reception d'acquittement*/
#endif

#define BASE_FREQ 1						/*!< Fréquence initiale du capteur*/

#define MSG_DELIMITER		'/'			/*!< Caractère délimitant la fin d'une trame*/

#define MSG_HEADER_LENGTH  	3			/*!< Taille du header des trames*/

#define MSG_STOP_HEADER		"*03"		/*!< En-tête de la trame d'arrêt*/
#define MSG_STOP_LENGTH 	7			/*!< Longueur de la trame d'arrêt*/
#define MSG_STOP			"*03STOP/"	/*!< Trame d'arrêt*/

#define MSG_FREQ_HEADER		"*02"		/*!< En-tête d'une trame de modification de fréquence*/
#define MSG_FREQ_TPL		"*02%d06/"	/*!< Template peremttant de générer une trame de modification de fréquence à l'aide d'un sprintf*/
#define MSG_FREQ_LENGTH		10			/*!< Longueur d'une trame de modification de fréquence*/

#define MSG_FRAME_HEADER	"*01"								/*!< En-tête d'une trame de température*/
#define MSG_FRAME_TPL		"*01%0+6.2f%02d%02d%02d%02d%02d/"	/*!< Template peremttant de générer une trame de température à l'aide d'un sprintf*/
#define MSG_FRAME_LENGTH	20									/*!< Longueur de la trame de température*/

#define MSG_ACK_HEADER  	"*00"		/*!< En-tête de la trame d'acquittement*/
#define MSG_ACK_LENGTH  	6			/*!< Longueur de la trame d'acquittement*/
#define MSG_ACK				"*00ACK/"	/*!< Trame d'acquittement*/

#define MSG_IS_FRAME(msg) (strncmp(msg, MSG_FRAME_HEADER, MSG_HEADER_LENGTH) == 0)	/*!<Macro permettant de tester si une trame reçue contient une température*/
#define MSG_IS_STOP(msg) (strncmp(msg, MSG_STOP_HEADER, MSG_HEADER_LENGTH) == 0)	/*!<Macro permettant de tester si une trame reçue contient un message d'arrêt*/
#define MSG_IS_ACK(msg) (strncmp(msg, MSG_ACK_HEADER, MSG_HEADER_LENGTH) == 0)		/*!<Macro permettant de tester si une trame reçue contient un message d'acquittement*/
#define MSG_IS_FREQ(msg) (strncmp(msg, MSG_FREQ_HEADER, MSG_HEADER_LENGTH) == 0)	/*!<Macro permettant de tester si une trame reçue contient un message de modification de fréquence*/
#define MSG_IS_EMPTY(msg) (strcmp(msg, "") == 0)									/*!<Macro permettant de tester si une trame reçue contient est vide*/


void com_sendACK(transmitter_t* t);
void com_sendTemp(transmitter_t* t, float temp, const struct tm* frametime);
void com_sendFreq(transmitter_t* t, int freq);
void com_sendStop(transmitter_t* t);

#endif /* _COM_H */
