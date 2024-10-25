#ifndef VOLATILE_MACHINE_H
#define VOLATILE_MACHINE_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Forward declaration for VolatileMachine
class VolatileMachine;

// Abstract Class: Instruction
class Instruction
{
public:
    virtual void execute(VolatileMachine &machine) = 0; // Pure virtual method
    virtual ~Instruction() = default;                   // Virtual destructor
};

// LoadInstruction Class
class LoadInstruction : public Instruction
{
private:
    int registerIndex;
    int memoryAddress;

public:
    LoadInstruction(int regIndex, int memAddr);
    void execute(VolatileMachine &machine) override;
};

// StoreInstruction Class
class StoreInstruction : public Instruction
{
private:
    int registerIndex;
    int memoryAddress;

public:
    StoreInstruction(int regIndex, int memAddr);
    void execute(VolatileMachine &machine) override;
};

// InstructionRegister Class
class InstructionRegister
{
private:
    Instruction *currentInstruction;

public:
    InstructionRegister();
    void load(Instruction *instruction);
    void execute(VolatileMachine &machine);
};

// VolatileMachine Class
///
/*class VolatileMachine
{
private:
    vector<int> registers;
    unordered_map<int, string> memory;

public:
    VolatileMachine(int numRegisters);
    string loadFromMemory(int address);
    void storeToMemory(int address, const string &data);
    void loadRegister(int index, int value);
    int getRegisterValue(int index) const;
};

///
#endif // VOLATILE_MACHINE_H
