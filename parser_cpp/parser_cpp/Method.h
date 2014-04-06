/**
 * @file Method.h
 * @brief D�claration de la classe Method
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */
#ifndef METHOD_H
#define METHOD_H

#include <string>

/**
 * @brief Classe charg�e de d�finir le format d'une m�thode stock�e dans un objet de type MethodsDatabase
 */
class Method
{
private:
	std::string m_ReturnType;
	std::string m_MethodName;

public:
	Method(const std::string & returnType, const std::string & methodName);
	Method(void);
	~Method(void);

	void setReturnType(const std::string & returnType);
	const std::string & getReturnType(void) const;

	void setMethodName(const std::string & methodName);
	const std::string & getMethodName(void) const;
};

#endif
