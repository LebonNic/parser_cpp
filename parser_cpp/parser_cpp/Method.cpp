#include "Method.h"


Method::Method(void)
{
}

Method::Method(const std::string & returnType, const std::string & methodName)
	:m_ReturnType(returnType),
	m_MethodName(methodName)
{
}


Method::~Method(void)
{
}

void Method::setReturnType(const std::string & returnType)
{
	m_ReturnType = returnType;
}
const std::string & Method::getReturnType(void) const
{
	return m_ReturnType;
}

void Method::setMethodName(const std::string & methodName)
{
	m_MethodName = methodName;
}
const std::string & Method::getMethodName(void) const
{
	return m_MethodName;
}

