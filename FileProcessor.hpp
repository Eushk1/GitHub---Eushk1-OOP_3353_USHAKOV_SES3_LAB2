//
//  FileProcessor.hpp
//  ООП_3353_УшаковЕВ_Лр2
//
//  Created by Егор on 16.11.2024.
//

#ifndef FileProcessor_hpp
#define FileProcessor_hpp

#include <stdio.h>
#include <string>

class FileProcessor {
public:
    virtual void parseFile(const std::string& filePath) = 0;
    virtual void displayStatistics() const = 0;
    virtual ~FileProcessor() = default;
};

#endif /* FileProcessor_hpp */
