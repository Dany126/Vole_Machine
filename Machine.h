#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <iomanip>
#include<cmath>
#include "Memory.h"
#include "Register.h"
#include "Counter.h"
#include "Instruction_Register.h"

using namespace std;

class Machine {
private:
    ProgramCounter PC;
    Registers R;
    InstructionRegister IR;
    vector<string> instructionsList;
    Memory M;
    static constexpr int REGISTER_SIZE = 16;

    bool isValidInstruction(const string& instruction) const {
        return !instruction.empty() && instruction.size() == 4;
    }

    void displayOutput(int value) const {
        char convertedCharacter = static_cast<char>(value);
        cout << "Output: " << convertedCharacter << endl;
    }

public:
    Machine() {}

    void loadInstructions(const vector<string>& instructions) {
        instructionsList = instructions;
        PC.reset();
        cout << "Instructions loaded. Program Counter reset." << endl;
    }

    void execute() {
        while (PC.getCounter() < instructionsList.size()) {
            string instruction = instructionsList[PC.getCounter()];
            PC.increment();
            cout << "Processing instruction: " << instruction << endl;

            if (!isValidInstruction(instruction)) {
                cout << "Invalid instruction: " << instruction << endl;
                continue;
            }

            char opCode = instruction[0];
            int r = (instruction[1] != '0') ? stoi(string(1, instruction[1]), nullptr, 16) : 0;
            string xy = instruction.substr(2, 2);
            cout << "Opcode: " << opCode << ", Register: " << r << ", XY: " << xy << endl;

            switch (opCode) {
            case '1':
                cout << "LOAD from memory address " << xy << " to register R" << r << endl;
                R.setValue(r, stoi(M.load(stoi(xy, nullptr, 16)), nullptr, 16));
                cout << "Register R" << r << " now has value " << R.getValue(r) << endl;
                break;
            case '2':
                cout << "LOAD immediate value " << xy << " to register R" << r << endl;
                R.setValue(r, stoi(xy, nullptr, 16));
                cout << "Register R" << r << " now has value " << R.getValue(r) << endl;
                break;
            case '3':
                if (xy == "00") {
                    cout << "STORE register R" << r << " value to screen" << endl;
                    
                    displayOutput(( R.getValue(r)));
                }
                else {
                    cout << "STORE register R" << r << " value " << R.getValue(r) << " to memory address " << xy << endl;
                    M.store(stoi(xy, nullptr, 16), to_string(R.getValue(r)));
                }
                break;
            case '4':
            {
                int s = stoi(string(1, instruction[2]), nullptr, 16);
                cout << "MOVE value from register R" << s << " to register R" << r << endl;
                R.setValue(r, R.getValue(s));
                break;
            }
            case '5':
            {
                int s = stoi(string(1, instruction[2]), nullptr, 16);
                int t = stoi(string(1, instruction[3]), nullptr, 16);
                cout << "ADD register R" << s << " and register R" << t << " into register R" << r << endl;
                R.setValue(r, (R.getValue(s) + R.getValue(t)) % 256); // Assuming 8-bit registers
                cout << "Register R" << r << " now has value " << R.getValue(r) << endl;
                break;
            }
            case '6':
            {
                int s = stoi(string(1, instruction[2]), nullptr, 16);
                int t = stoi(string(1, instruction[3]), nullptr, 16);
                cout << "ADD (floating-point) register R" << s << " and register R" << t << " into register R" << r << endl;
                R.setValue(r, R.getValue(s) + R.getValue(t));
                cout << "Register R" << r << " now has value " << R.getValue(r) << endl;
                break;
            }
            case 'B':
                cout << "JUMP if register R" << r << " is equal to register R0" << endl;
                if (R.getValue(r) == R.getValue(0)) {
                    PC.setCounter(stoi(xy, nullptr, 16));
                    cout << "Jumped to instruction at address " << xy << endl;
                }
                break;
            case 'C':
                cout << "Program halted." << endl;
                return;
            default:
                cout << "Unknown opcode: " << opCode << endl;
                break;
            }
        }
    }

    void displayRegisters() {
        R.display();
    }

    void displayMemory() const {
        M.display();
    }
};
