
class Registers
{
private:
    vector<int> registers;

public:
    Registers()
    {
        registers.resize(16, 0); // Resize the vector to hold 16 elements, initialized to 0
    }

    void load(int index, int value)
    {
        if (index >= 0 && index < registers.size())
        {
            registers[index] = value;
        }
        else
        {
            cout << "Invalid register index" << endl;
            return;
        }
    }

    int getValue(int index) const
    {
        if (index >= 0 && index < registers.size())
        {
            return registers[index];
        }
        else
        {
            cout << "Out of range" << endl;
            return 0; // Return 0 or handle it in a different way
        }
    }

    void display() const
    {
        cout << "Registers:\n";
        for (size_t i = 0; i < registers.size(); ++i)
        {
            cout << "R" << i << ": " << hex << registers[i] << "\n"; // Formatted output
        }
    }
};
