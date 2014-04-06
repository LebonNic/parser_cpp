/**
 * @file HeaderParser.h
 * @brief Déclaration de la classe HeaderParser
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */
#ifndef HEADERPARSER_H
#define HEADERPARSER_H

#include <string>
#include <sstream>
#include <fstream>
#include <regex>
#include <iostream>

#include "MethodsDatabase.h"

/**
 * @brief Classe chargée de parser les headers des fichiers de code source
 */
class HeaderParser
{
private:
	MethodsDatabase m_Database;
    void load(const std::string & fileName);

public:
    HeaderParser(const std::string & fileName);
	std::string toString() const;
};

#endif

