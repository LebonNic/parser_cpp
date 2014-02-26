#pragma once
#include <string>

class HeaderParser
{
private:
    void load(const std::string & filename);
public:
    HeaderParser(const std::string & filename);
};

