#include "MethodsDatabase.h"


MethodsDatabase::MethodsDatabase(void)
{
}


MethodsDatabase::~MethodsDatabase(void)
{
}

void MethodsDatabase::addMethod(Method *method)
{
    this->m_Methods.push_back(method);
}

void MethodsDatabase::addMethod(const std::string &returnType, const std::string &methodName)
{
    this->m_Methods.push_back(new Method(returnType, methodName));
}
