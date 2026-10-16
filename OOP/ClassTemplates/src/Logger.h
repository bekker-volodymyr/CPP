#pragma once

template<typename T>
class Logger {
public:
    // Логування повідомлення
    static void log(const T& message) {
        std::cout << "Log: " << message << std::endl;
    }

    // Логування помилки
    static void logError(const T& error) {
        std::cerr << "Error: " << error << std::endl;
    }

    // Логування попередження
    static void logWarning(const T& warning) {
        std::cout << "Warning: " << warning << std::endl;
    }
};