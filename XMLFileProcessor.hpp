//
//  XMLFileProcessor.hpp
//  ООП_3353_УшаковЕВ_Лр2
//
//  Created by Егор on 16.11.2024.
//

#ifndef XMLFileProcessor_hpp
#define XMLFileProcessor_hpp

#include <stdio.h>
#include <iostream>
#include <tinyxml2.h>
#include <sstream> 
#include <unordered_map>
#include "FileProcessor.hpp"
#include "Statistics.hpp"

// Класс для обработки XML файлов
class XMLFileProcessor : public FileProcessor {
public:
    void parseFile(const std::string& filePath) override;

    void displayStatistics() const override;

private:
    Statistics statistics; 
};

#endif /* XMLFileProcessor_hpp */
