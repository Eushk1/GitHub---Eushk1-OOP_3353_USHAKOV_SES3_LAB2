//
//  Statistics.cpp
//  ООП_3353_УшаковЕВ_Лр2
//
//  Created by Егор on 16.11.2024.
//

#include "Statistics.hpp"

bool Statistics::addDuplicate(const std::string& record) { // 1 - если добавлен новый ключ, 0 - если нет
    duplicates[record]++;
    if (duplicates[record] > 1) {
        return 0;
    }
    return 1;
}

void Statistics::addBuilding(const std::string& city, int floors) {
    if (floors >= 1 && floors <= 5) {
        cityBuildings[city][floors - 1] = cityBuildings[city][floors - 1] + 1;
    }
}

void Statistics::displayDuplicates() const {
    for (const auto& entry : duplicates) {
        std::cout << entry.first << ": " << entry.second << " раз(а)\n";
    }
}

void Statistics::displayBuildingStatistics() const {
    for (const auto& cityEntry : cityBuildings) {
        std::cout << "Город: " << cityEntry.first << "\n";
        for (size_t i = 0; i < cityEntry.second.size(); ++i) {
            std::cout << (i + 1) << "-этажные: " << cityEntry.second[i] << "\n";
        }
    }
}

void Statistics::removeDuplicatesWithCountOne() {
    for (auto it = duplicates.begin(); it != duplicates.end(); ) {
        if (it->second <= 1) {
            it = duplicates.erase(it);
        } else {
            ++it;
        }
    }
}
