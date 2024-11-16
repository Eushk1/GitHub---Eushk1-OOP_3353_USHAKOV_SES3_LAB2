//
//  CSVFileProcessor.cpp
//  ООП_3353_УшаковЕВ_Лр2
//
//  Created by Егор on 16.11.2024.
//

#include "CSVFileProcessor.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>

void CSVFileProcessor::parseFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << filePath << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Пропустить заголовок
    std::getline(file, line); // Пропустить вторую строку (если есть)

    std::unordered_map<std::string, int> recordCount;

    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        size_t pos = 0;
        size_t nextPos;
        std::string city, street, house;
        int floors = 0;

        nextPos = line.find(';', pos);
        city = line.substr(pos, nextPos - pos);
        pos = nextPos + 1;

        nextPos = line.find(';', pos);
        street = line.substr(pos, nextPos - pos);
        pos = nextPos + 1;

        nextPos = line.find(';', pos);
        house = line.substr(pos, nextPos - pos);
        pos = nextPos + 1;

        floors = std::stoi(line.substr(pos));

    
        city.erase(remove_if(city.begin(), city.end(), isspace), city.end());
        street.erase(remove_if(street.begin(), street.end(), isspace), street.end());
        house.erase(remove_if(house.begin(), house.end(), isspace), house.end());
        
        std::string fullline = city + "," + street + "," + house + "," + std::to_string(floors);
         
        if (statistics.addDuplicate(fullline)) {
            statistics.addBuilding(city, floors);
        }
    }

    statistics.removeDuplicatesWithCountOne();

    file.close();
}

void CSVFileProcessor::displayStatistics() const {
    std::cout << "Дублирующиеся записи:\n";
    statistics.displayDuplicates();
    std::cout << "\nСтатистика по этажности зданий:\n";
    statistics.displayBuildingStatistics();
}

