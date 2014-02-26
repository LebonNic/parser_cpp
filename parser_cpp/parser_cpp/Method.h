#pragma once
#include <string>

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

