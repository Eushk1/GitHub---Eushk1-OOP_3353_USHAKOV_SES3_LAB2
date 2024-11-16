//
//  Application.cpp
//  ООП_3353_УшаковЕВ_Лр2
//
//  Created by Егор on 16.11.2024.
//


#include "Application.hpp"

void Application::run() {
    while (handleUserInput()) {
    }
}


bool Application::handleUserInput() {
    std::string input;
    std::cout << "Введите путь до файла или 'exit' для выхода: ";
    std::getline(std::cin, input);

    if (input == "exit") {
        std::cout << "Завершение работы приложения.\n";
        return 0;
    }

    processFile(input);
    return 1;
}


void Application::processFile(const std::string& filePath) {
    if (filePath.ends_with(".csv")) {
        std::cout << "Работаем с файлом расширения .csv" << std::endl;
        fileProcessor = std::make_unique<CSVFileProcessor>();
    } else if (filePath.ends_with(".xml")) {
        std::cout << "Работаем с файлом расширения .xml" << std::endl;
        fileProcessor = std::make_unique<XMLFileProcessor>();
    } else {
        std::cout << "Неподдерживаемый формат файла.\n";
        return;
    }

    auto start = std::chrono::high_resolution_clock::now();
    fileProcessor->parseFile(filePath);
    auto end = std::chrono::high_resolution_clock::now();

    auto processingTime = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

    std::cout << "Время обработки файла: " << processingTime.count() << " секунд" << std::endl;

    fileProcessor->displayStatistics();
}
