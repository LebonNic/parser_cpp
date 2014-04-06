/**
 * \file node.h
 * \brief 	Fichier de déclaration d'une structure de données utilisée pour stocker
 *			les trames échangées entre le capteur et la centrale.
 */
#ifndef _NODE_H
#define _NODE_H

#include <stdlib.h>
#include <string.h>

#define NODE_SIZE_MAX 256	/*!< Nombre maximum de caractères que peut stocker chaque noeud.*/

/**
 * \struct node_t
 * \brief 	Structure de données permettant de stocker des trames. 
 *
 *	Chaque noeud représente un élément d'une liste chainée de node_t. Ainsi chaque noeud contient
 *	un tableau de caractères destiné à stocker les informations des trames reçues et émises, mais 
 *	aussi un pointeur sur le noeud suivant.
 */
typedef struct node 
{
	char value[NODE_SIZE_MAX];	/*!< Tableau de caractères permettant de stocker les informations d'une trame.*/
	struct node* next;			/*!< Pointeur sur le noeud suivant.*/
} node_t;

node_t* node_create(const char* value);
void node_destroy(node_t* n);

#endif
