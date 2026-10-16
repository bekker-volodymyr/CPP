#include <cstdio>
#include <iostream>
#include <cstring>

class FileHandler {
protected:
    FILE* file;
public:
    virtual void Write(const char* data) = 0;
    virtual void Read() = 0;

    virtual ~FileHandler() {
        std::cout << "[Base] деструктор\n";
    }
};

class TextFileHandler : public FileHandler {
public:
    TextFileHandler(const char* path) {
        file = fopen(path, "w+");
    }

    void Write(const char* data) override {
        if (file) fputs(data, file);
    }

    void Read() override {
        if (!file) return;
        rewind(file);
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), file)) {
            std::cout << buffer;
        }
    }

    ~TextFileHandler() override {
        std::cout << "[Text] Закриття текстового файлу\n";
        if (file) fclose(file);
    }
};

class BinaryFileHandler : public FileHandler {
public:
    BinaryFileHandler(const char* path) {
        file = fopen(path, "wb+");
    }

    void Write(const char* data) override {
        if (file) fwrite(data, sizeof(char), strlen(data), file);
    }

    void Read() override {
        if (!file) return;
        rewind(file);
        char ch;
        while (fread(&ch, sizeof(char), 1, file)) {
            std::cout << ch;
        }
    }

    ~BinaryFileHandler() override {
        std::cout << "[Binary] Закриття бінарного файлу\n";
        if (file) fclose(file);
    }
};
