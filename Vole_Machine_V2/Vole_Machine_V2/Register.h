#pragma once
#include <iostream>
#include <unordered_map>
#include <iomanip>

using namespace std;

class Registers {
private:
    unordered_map<int, int> registers;
    static const int REGISTER_SIZE = 16;

public:
    Registers() {
        for (int i = 0; i < REGISTER_SIZE; ++i) {
            registers[i] = 0; 
        }
    }


    int get_Value(int index) const {
        return registers.at(index);
    }


    void set_Value(int index, int value) {
        registers[index] = value;
    }

    
    void Print_value() const {
        cout << "Registers:\n";
        for (size_t i = 0; i < REGISTER_SIZE; ++i) {
            cout << "R" << i << ": " << hex  << registers.at(i) << endl;
        }
    }
};
