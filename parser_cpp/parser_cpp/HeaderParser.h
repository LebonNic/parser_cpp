#pragma once
#include <string>
#include <fstream>

#include "MethodsDatabase.h"

class HeaderParser
{
private:
    void load(const std::string & filename);


    MethodsDatabase m_Database;
public:
    HeaderParser(const std::string & filename);
};

