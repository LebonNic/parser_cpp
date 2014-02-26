#pragma once
#include <list>
#include "Method.h"

class MethodsDatabase
{
private:
    std::list<Method *> m_Methods;
public:
    MethodsDatabase(void);
    ~MethodsDatabase(void);

    void addMethod(Method *method);
    void addMethod(const std::string &returnType, const std::string &methodName);
};

