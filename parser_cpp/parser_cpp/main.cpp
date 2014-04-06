/**
 * @file main.cpp
 * @brief Point d'entr�e du programme
 * @author Antoine Colmard
 * @author Nicolas Prugne
 */
#include "HeaderParser.h"
#include <iostream>

int main (int argc, char **argv)
{
	double duration;
    std::clock_t start;

    // Chargement du fichier si sp�cifi�
    if (argc > 1)
    {
		start = std::clock();
		std::cout << "Parsing file : " << argv[1] << std::endl;
		HeaderParser parser (argv[1]);
		duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
		std::cout << "End of parsing (" << duration << "s)." << std::endl << std::endl;
		std::cout << parser.toString();
	}
	return 0;
}
