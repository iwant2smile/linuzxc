#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Использование: ./read-file <путь_к_файлу>" << std::endl;
        return 1;
    }

    const char* file_path = argv[1];

    std::ifstream file(file_path);
    if (!file) {
        std::cerr << "Ошибка: не удалось открыть файл " << file_path << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
    return 0;
}
