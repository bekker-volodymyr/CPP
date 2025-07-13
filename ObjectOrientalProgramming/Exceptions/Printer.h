#pragma once
#include <string>
#include <iostream>
#include <stdexcept>

class Printer
{
private:
	std::string _name;
	int _availablePaper;
public:
	Printer(const std::string& name, int availablePaper)
		: _name(name), _availablePaper(availablePaper) { }

	void print(const std::string& document);
};

class PrinterException : public std::runtime_error {
private:
	std::string _message;
public:
	PrinterException(int availablePaper, int requiredPaper) 
		: std::runtime_error("Не достатньо паперу для печаті!") {
		_message = "Не достатньо паперу для печаті!\Потрібно: " 
			+ std::to_string(requiredPaper) + " -- Доступно: " 
			+ std::to_string(availablePaper);
	}

	const char* what() const noexcept override {
		return _message.c_str();
	}
};