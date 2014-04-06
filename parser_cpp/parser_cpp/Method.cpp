/**
 * @file Method.cpp
 * @brief Impl�mentation de la classe Method
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#include "Method.h"

/**
 * @brief Method::Method Constructeur par d�faut 
 */
Method::Method(void)
{
}

/**
 * @brief Method::Method Constructeur param�tr�
 * @param returnType Type de retour de la m�thode � construire
 * @param methodName Nom de la m�thode � construire
 */
Method::Method(const std::string & returnType, const std::string & methodName)
	:m_ReturnType(returnType),
	m_MethodName(methodName)
{
}

/**
 * @brief Method::~Method Destructeur 
 */
Method::~Method(void)
{
}

/**
 * @brief Method::setReturnType Met � jour le type de retour de la m�thode stock�e
 * @param returnType Type de retour de la m�thode 
 */
void Method::setReturnType(const std::string & returnType)
{
	m_ReturnType = returnType;
}
/**
 * @brief Method::getReturnType Retourne le type de retour de la m�thode stock�e
 * @return Type de retour de la m�thode stock�e
 */
const std::string & Method::getReturnType(void) const
{
	return m_ReturnType;
}

/**
 * @brief Method::setMethodName Met � jour le nom de la m�thode stock�e
 * @param methodName Nom de la m�thode 
 */
void Method::setMethodName(const std::string & methodName)
{
	m_MethodName = methodName;
}
/**
 * @brief Method::getMethodName Retourne le nom de la m�thode stock�e
 * @return Nom de la m�thode stock�e
 */
const std::string & Method::getMethodName(void) const
{
	return m_MethodName;
}

