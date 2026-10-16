#include "Printer.h"

void Printer::print(const std::string& document) {
	// Припустимо, що кожні 10 символів потребують 1 аркуш паперу
	int paperRequired = document.length() / 10 + 1; 

	if (_availablePaper < paperRequired) {
		throw std::runtime_error("Недостатньо паперу для друку!");
	}
	std::cout << "Друк документа: " << document << " на принтері: " << _name << std::endl;
	_availablePaper -= paperRequired;
}