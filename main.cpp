#include <iostream>
#include "Machine.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
    Machine machine;
    fstream myfile;
    myfile.open("New Text Document.txt", ios::in);
    if (myfile.is_open()) {
        string line;
        vector<string> instructions; // Declare the vector to store instructions

        while (getline(myfile, line)) {
            instructions.push_back(line); // Add each line to the vector
        }

        myfile.close();

        machine.loadInstructions(instructions);
        machine.execute();
        machine.displayRegisters();
        machine.displayMemory();
        
        

        return 0;
    }
}