#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <iomanip>
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
    static const int REGISTER_SIZE = 16;

    bool isValidInstruction(const string& instruction) {
        return !instruction.empty() && instruction.size() == 4;
    }

    void displayOutput(int value) {
        cout << "Output: " << value << endl;
    }

public:
    Machine() {}

    void loadInstructions(const vector<string>& instructions) {
        instructionsList = instructions;
        PC.reset();
    }

    void execute() {
        while (PC.get_Counter() < instructionsList.size()) {
            string instruction = instructionsList[PC.get_Counter()];
            PC.increment();

            if (!isValidInstruction(instruction)) {
                cout << "Invalid instruction: " << instruction << endl;
                continue;
            }

            char opCode = instruction[0];
            int r = (instruction[1] != '0') ? stoi(string(1, instruction[1]), nullptr, 16) : 0;
            string xy = instruction.substr(2, 2);

            switch (opCode) {
            case '1':
                R.set_Value(r, stoi(M.load(stoi(xy, nullptr, 16)), nullptr, 16));
                break;
            case '2':
                R.set_Value(r, stoi(xy, nullptr, 16));
                break;
            case '3':
                if (xy == "00") {
                    displayOutput(R.get_Value(r));
                } else {
                    M.store(stoi(xy, nullptr, 16), to_string(R.get_Value(r)));
                }
                break;
            case '4': {
                int s = stoi(string(1, instruction[2]), nullptr, 16);
                R.set_Value(r, R.get_Value(s));
                break;
            }
            case '5': {
                int s = stoi(string(1, instruction[2]), nullptr, 16);
                int t = stoi(string(1, instruction[3]), nullptr, 16);
                R.set_Value(r, (R.get_Value(s) + R.get_Value(t)) % 256);
                break;
            }
            case '6': {
                int s = stoi(string(1, instruction[2]), nullptr, 16);
                int t = stoi(string(1, instruction[3]), nullptr, 16);
                R.set_Value(r, R.get_Value(s) + R.get_Value(t));
                break;
            }
            case 'B':
                if (R.get_Value(r) == R.get_Value(0)) {
                    PC.set_Counter(stoi(xy, nullptr, 16));
                }
                break;
            case 'C':
                return;
            default:
                cout << "Unknown opcode: " << opCode << endl;
                break;
            }
        }
    }

    void displayRegisters() {
        R.Print_value();
    }

    void displayMemory() const {
        M.Print_value();
    }
};
