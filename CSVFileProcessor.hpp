//
//  CSVFileProcessor.hpp
//  ООП_3353_УшаковЕВ_Лр2
//
//  Created by Егор on 16.11.2024.
//

#ifndef CSVFileProcessor_hpp
#define CSVFileProcessor_hpp

#include <stdio.h>
#include <iostream>
#include "FileProcessor.hpp"
#include "Statistics.hpp"

class CSVFileProcessor : public FileProcessor {
public:
    void parseFile(const std::string& filePath) override;
    void displayStatistics() const override;

private:
    Statistics statistics; 
};

#endif /* CSVFileProcessor_hpp */
