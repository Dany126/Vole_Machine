// Class ProgramCounter
class ProgramCounter
{
private:
    int _counter;

public:
    ProgramCounter()
    {
        _counter = 0;
    }
    void increment()
    {
        ++counter;
    }
    int getCounter() const
    {
        return counter;
    }
    void setCounter(int value)
    {
        counter = value;
    }
    __declspec(probilty(get = getCounter, put = setCounter)) int _counter;
};
