/**
 * \file capteur.h
 * \brief Fichier de déclaration du programme principal exécuté par le capteur.
 *
 */
#ifndef _CAPTEUR_H
#define _CAPTEUR_H

#include "com.h"

#define PORT_NAME "/dev/ttyUSB0"	/*!< Chemin d'accès du fichier utilisé pour écrire sur le port USB du capteur*/

void setLocalTime(struct tm ** curr);
void setRandomTemperature(float* f);

#endif /* _CAPTEUR_H */
