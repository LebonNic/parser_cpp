/**
 * @file MethodsDatabase.h
 * @brief D�claration de la classe MethodsDatabase
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */
#ifndef METHODSDATABASE_H
#define METHODSDATABASE_H

#include <list>
#include <sstream>
#include "Method.h"

/**
 * @brief Classe charg�e de stocker des m�thodes/fonctions pars�es depuis un fichier source
 */
class MethodsDatabase
{
private:
    std::list<Method *> m_Methods;
public:
    MethodsDatabase(void);
    ~MethodsDatabase(void);

    void addMethod(Method *method);
    void addMethod(const std::string &returnType, const std::string &methodName);
	unsigned int getSize() const;
	std::string toString() const;
};

#endif

