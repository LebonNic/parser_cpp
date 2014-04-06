/**
 * @file HeaderParser.cpp
 * @brief Implémentation de la classe HeaderParser
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */
#include "HeaderParser.h"

/**
 * @brief HeaderParser::HeaderParser Constructeur paramétré
 * @param fileName Chemin du fichier à parser
 */
HeaderParser::HeaderParser(const std::string &fileName)
{
    load(fileName);
}

/**
 * @brief HeaderParser::load Charge la database de méthodes depuis un fichier
 * @param fileName Fichier à charger
 */
void HeaderParser::load(const std::string &fileName)
{
	std::ifstream filestream(fileName.c_str());
	std::string line,
				word;

	/*
     LE SAINT GRALL !
    (\s*)(const|virtual|static|inline)?(\s*)(\w|\<\w+\>|::)+((\s(&|\*))|((&|\*)\s)|\s)(\w)+\((\w|\s|,|&|\*|\<\w+\>|::)*\)(\s*)(const)?
    */

	std::string pattern = "(\\s*)(const|virtual|static|inline)?(\\s*)(\\w|\\<\\w+\\>|::)+((\\s(&|\\*))|((&|\\*)\\s)|\\s)(\\w)+\\((\\w|\\s|,|&|\\*|\\<\\w+\\>|::)*\\)(\\s*)(const)?",
				returnType,
				prototype,
				temp;
	std::regex exp (pattern);
	std::smatch match;

    if (filestream.is_open())
    {
		while(std::getline(filestream, line))
		{
			 if(std::regex_search (line,match,exp)) 
			 {
				 std::stringstream ss(line);
				 ss >> returnType;
				 ss >> temp;
				 if(temp == "*" || temp == "&")
				 {
					 returnType += temp;
					 ss >> prototype;
				 }
				 else
					 prototype = temp;

				 while(ss >> temp)
					 prototype += temp;

				 m_Database.addMethod(returnType, prototype);
			 }
		}
    }
	filestream.close();
}

/**
 * @brief HeaderParser::toString Transforme la base de données en chaine de caractères affichable
 */
std::string HeaderParser::toString() const
{
	std::stringstream ss;
	ss	<< "Database content : " << m_Database.getSize() << " methods registered." << std::endl << std::endl
		<< "Methods list : " << std::endl << std::endl;
	ss << m_Database.toString();

	return ss.str();
}
