#include <fstream>
#include <sstream>
#include <iostream>

#include "command/CommandFactory.h"

int main(int argc, char *argv[]) {
     if (argc < 2){
         std::cout << "No path found for input file" << std::endl;
         return 1;
     }
     std::string input_file = argv[1];
     std::ifstream input(input_file);
     if (!input.is_open()) {
         std::cout << "Error opening file" << std::endl;
         return 1;
     }

     std::string line;
     while(std::getline(input, line)) {
        std::stringstream streamLine(line);
        ICommand* command = CommandFactory::createCommand(streamLine);
        if (command) {
            command->execute();
            delete command;
        } else {
            std::cout << "Invalid ICommand" << std::endl;
        }
     }

     input.close();
     return 0;
}
