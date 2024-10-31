#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Memory {
private:
    vector<string> mem;
    static const int MEMORY_SIZE = 256;

public:
    Memory() : mem(MEMORY_SIZE, "00") {}

    void store(int address, const string& value) {
        if (isValidAddress(address)) {
            mem[address] = value;
        }
        else {
            cerr << "Memory address out of bounds!" << endl;
        }
    }

    string load(int address) const {
        if (isValidAddress(address)) {
            return mem[address];
        }
        else {
            cerr << "Memory address out of bounds!" << endl;
            return "00";
        }
    }

    void Print_value() const {
        cout << "Memory Contents:\n";
        for (int i = 0; i < MEMORY_SIZE; ++i) {
            cout << "Address " << hex << i << ": " << mem[i] << endl;
        }
    }

private:
    bool isValidAddress(int address) const {
        return address >= 0 && address < MEMORY_SIZE;
    }
};
