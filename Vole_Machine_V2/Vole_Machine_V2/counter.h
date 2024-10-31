#pragma once
class ProgramCounter {
private:
    int _counter;
public:
    ProgramCounter() { _counter = 0; };
    void increment() { ++_counter; }
    int get_Counter() const { return _counter; }
    void set_Counter(int value) { _counter = value; }
    void reset() { _counter = 0; } 
};
