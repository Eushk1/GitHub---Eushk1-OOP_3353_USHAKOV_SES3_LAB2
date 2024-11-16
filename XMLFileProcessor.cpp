//
//  XMLFileProcessor.cpp
//  ООП_3353_УшаковЕВ_Лр2
//
//  Created by Егор on 16.11.2024.
//

#include "XMLFileProcessor.hpp"

void XMLFileProcessor::parseFile(const std::string& filePath) {
    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(filePath.c_str()) != tinyxml2::XML_SUCCESS) {
        std::cerr << "Не удалось открыть файл: " << filePath << std::endl;
        return;
    }

    tinyxml2::XMLElement* root = doc.FirstChildElement("root");
    if (root == nullptr) {
        std::cerr << "Не удалось найти корневой элемент 'root' в XML." << std::endl;
        return;
    }

    std::string city, street, house;
    std::ostringstream fullline;

    for (tinyxml2::XMLElement* item = root->FirstChildElement("item"); item != nullptr; item = item->NextSiblingElement("item")) {
        const char* cityAttr = item->Attribute("city");
        const char* streetAttr = item->Attribute("street");
        const char* houseAttr = item->Attribute("house");
        int floors = item->IntAttribute("floor");


        city = cityAttr ? cityAttr : "";
        street = streetAttr ? streetAttr : "";
        house = houseAttr ? houseAttr : "";
        
        
        city.erase(remove_if(city.begin(), city.end(), isspace), city.end());
        street.erase(remove_if(street.begin(), street.end(), isspace), street.end());
        house.erase(remove_if(house.begin(), house.end(), isspace), house.end());

        fullline.str("");
        fullline << city << "," << street << "," << house << "," << floors;

        if (statistics.addDuplicate(fullline.str())) {
            statistics.addBuilding(city, floors);
        }
    }

    statistics.removeDuplicatesWithCountOne();
}

void XMLFileProcessor::displayStatistics() const {
    std::cout << "Дублирующиеся записи:\n";
    statistics.displayDuplicates();
    std::cout << "\nСтатистика по этажности зданий:\n";
    statistics.displayBuildingStatistics();
}
