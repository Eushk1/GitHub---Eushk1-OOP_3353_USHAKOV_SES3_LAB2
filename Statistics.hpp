//
//  Statistics.hpp
//  ООП_3353_УшаковЕВ_Лр2
//
//  Created by Егор on 16.11.2024.
//

#ifndef Statistics_hpp
#define Statistics_hpp

#include <iostream>
#include <unordered_map>
#include <map>
#include <array>


class Statistics {
private:
    std::unordered_map<std::string, int> duplicates;
    std::map<std::string, std::array<int, 5>> cityBuildings;

public:
    bool addDuplicate(const std::string& record); // 1 - если добавлен новый ключ, 0 - если нет
    void addBuilding(const std::string& city, int floors);
    void displayDuplicates() const;
    void displayBuildingStatistics() const;
    void removeDuplicatesWithCountOne();
};

#endif /* Statistics_hpp */
