/**
 * @file MethodsDatabase.cpp
 * @brief Implémentation de la classe MethodsDatabase
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */
#include "MethodsDatabase.h"

/**
 * @brief MethodsDatabase::MethodsDatabase Constructeur par défaut de database
 */
MethodsDatabase::MethodsDatabase(void)
{
}

/**
 * @brief MethodsDatabase::~MethodsDatabase Destructeur de database
 */
MethodsDatabase::~MethodsDatabase(void)
{
}

/**
 * @brief MethodsDatabase::addMethod Ajout d'une méthode à la database
 * @param method Un pointeur sur la méthode à ajouter
 */
void MethodsDatabase::addMethod(Method *method)
{
    this->m_Methods.push_back(method);
}

/**
 * @brief MethodsDatabase::addMethod Ajout d'une méthode à la database
 * @param returnType Type de retour de la méthode à ajouter
 * @param methodName Nom de la méthode à ajouter
 */
void MethodsDatabase::addMethod(const std::string &returnType, const std::string &methodName)
{
    this->m_Methods.push_back(new Method(returnType, methodName));
}

/**
 * @brief MethodsDatabase::getSize Retourne le nombre de méthodes stockées dans la database
 */
unsigned int MethodsDatabase::getSize() const
{
	return m_Methods.size();
}

/**
 * @brief MethodsDatabase::toString Transforme l'ensemble des méthodes contenues dans la database
 *									en une chaine de caractères affichable
 */
std::string MethodsDatabase::toString() const
{
	std::stringstream ss;
	for(std::list<Method *>::const_iterator ite = m_Methods.begin(); ite != m_Methods.end(); ++ite)
	{
		ss	<< "Return type : " << (*ite)->getReturnType() << std::endl
			<< "Prototype : " << (*ite)->getMethodName() << std::endl << std::endl;
	}
	return ss.str();
}
