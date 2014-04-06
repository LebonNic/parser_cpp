/**
 * @file Method.cpp
 * @brief Implémentation de la classe Method
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */

#include "Method.h"

/**
 * @brief Method::Method Constructeur par défaut 
 */
Method::Method(void)
{
}

/**
 * @brief Method::Method Constructeur paramétré
 * @param returnType Type de retour de la méthode à construire
 * @param methodName Nom de la méthode à construire
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
 * @brief Method::setReturnType Met à jour le type de retour de la méthode stockée
 * @param returnType Type de retour de la méthode 
 */
void Method::setReturnType(const std::string & returnType)
{
	m_ReturnType = returnType;
}
/**
 * @brief Method::getReturnType Retourne le type de retour de la méthode stockée
 * @return Type de retour de la méthode stockée
 */
const std::string & Method::getReturnType(void) const
{
	return m_ReturnType;
}

/**
 * @brief Method::setMethodName Met à jour le nom de la méthode stockée
 * @param methodName Nom de la méthode 
 */
void Method::setMethodName(const std::string & methodName)
{
	m_MethodName = methodName;
}
/**
 * @brief Method::getMethodName Retourne le nom de la méthode stockée
 * @return Nom de la méthode stockée
 */
const std::string & Method::getMethodName(void) const
{
	return m_MethodName;
}

