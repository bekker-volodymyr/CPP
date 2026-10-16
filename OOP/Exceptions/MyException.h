#pragma once
#include <stdexcept>

class MyException : public std::exception
{
public:
	MyException() = default;
	~MyException() = default;

	const char* what() const noexcept override
	{
		return "Стався мій кастомний виняток!";
	}
};
