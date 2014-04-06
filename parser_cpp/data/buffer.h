/**
 * \file buffer.h
 * \brief Fichier de déclaration d'une structure de données buffer.
 *
 * 	La structure de données buffer est utilisée pour stocker sous forme
 *	de liste chainée les trames échangées entre le capteur et la centrale.
 *
 */
#ifndef _BUFFER_H
#define _BUFFER_H

#include <pthread.h>
#include "node.h"

#define LOCK(b) pthread_mutex_lock(&((b)->access)); 	/*!< Macro permettant de verrouiller une section critique accessible depuis plusieurs threads. */
#define UNLOCK(b) pthread_mutex_unlock(&((b)->access)); /*!< Macro permettant de déverrouiller une section critique accessible depuis plusieurs threads. */

/**
 * \struct buffer_t 
 * \brief 	Structure de données permettant de stocker une liste chainée de
 * 			node_t.
 *
 *	Les node_t du buffer sont stockées sous forme de liste chainée. Chaque modification
 * 	de la liste est sécurisée grace à des mutex. En effet, cette structure peut être 
 *	lue et modifiée par plusieurs threads simultanément, il est donc nécessaire de gérer
 *	ces accès concurents. Ce problème a donc été résolu en utilisant des mutex.
 */
typedef struct buffer {
	node_t* head;			/*!< Pointeur de tête de la liste chainée. */
	int size;				/*!< Taille de la liste chainée. */
	pthread_mutex_t access;	/*!< Mutex permettant de protéger les parties du code qui modifient la structure. */
} buffer_t;

buffer_t* buf_create();
int buf_empty(buffer_t* b);
void buf_destroy(buffer_t* b);
void buf_push(buffer_t* b, const char* iStr);
void buf_pop(buffer_t* b, char* oStr);

#endif /* _BUFFER_H */
