//
//  Application.hpp
//  ООП_3353_УшаковЕВ_Лр2
//
//  Created by Егор on 16.11.2024.
//

#ifndef Application_hpp
#define Application_hpp

#include <iostream>
#include <memory>
#include <string>
#include <chrono>
#include "CSVFileProcessor.hpp"
#include "XMLFileProcessor.hpp"
#include "Statistics.hpp"


class Application {
public:
    void run();

private:
    std::unique_ptr<FileProcessor> fileProcessor;
    bool handleUserInput();
    void processFile(const std::string& filePath);
};

#endif /* Application_hpp */
