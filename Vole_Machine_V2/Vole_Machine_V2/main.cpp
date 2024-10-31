#include <iostream>
#include "Machine.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
    Machine machine;
    fstream myfile;
    myfile.open("Machine_language.txt", ios::in);
    if (myfile.is_open()) {
        string line;
        vector<string> instructions; 

        while (getline(myfile, line)) {
            instructions.push_back(line); 
        }

        myfile.close();

        machine.loadInstructions(instructions);
        machine.execute();
        machine.displayRegisters();
        machine.displayMemory();

        return 0;
    }
}