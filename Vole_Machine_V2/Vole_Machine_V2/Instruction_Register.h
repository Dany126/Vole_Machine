#pragma once
using namespace std;
class InstructionRegister {
private:
    string _Current_Instruction;
public:
    void load(const string& inst) { _Current_Instruction = inst; }
   string get_Instruction()  { return _Current_Instruction; }
};
