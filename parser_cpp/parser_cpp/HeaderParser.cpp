#include "HeaderParser.h"

HeaderParser::HeaderParser(const std::string &filename)
{
    load(filename);
}

void HeaderParser::load(const std::string &filename)
{
    std::fstream filestream(filename);

    /*
     LE SAINT GRALL !
    (\s*)(const|virtual|static|inline)?(\s*)(\w|\<\w+\>|::)+((\s(&|\*))|((&|\*)\s)|\s)(\w)+\((\w|\s|,|&|\*|\<\w+\>|::)*\)(\s*)(const)?
    */
    if (filestream.good())
    {
    }
}
