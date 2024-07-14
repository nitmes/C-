#include <iostream>
#include <vector>

template <class T>
class table
{
public:
    table(int rows, int cols)
        : numRows(rows), numCols(cols), elements(new T* [rows])
    {
        for (int i = 0; i < rows; ++i)
        {
            elements[i] = new T[cols];
        }
    }

    T getElement(int rowIndex, int colIndex) const
    {
        if (rowIndex >= 0 && rowIndex < numRows && colIndex >= 0 && colIndex < numCols)
        {
            return elements[rowIndex][colIndex];
        }
        throw std::out_of_range("Index out of range");
    }

    void setElement(int rowIndex, int colIndex, T inValue)
    {
        if (rowIndex >= 0 && rowIndex < numRows && colIndex >= 0 && colIndex < numCols)
        {
            elements[rowIndex][colIndex] = inValue;
        }
        else
        {
            throw std::out_of_range("Index out of range");
        }
    }

    ~table()
    {
        for (int i = 0; i < numRows; ++i)
        {
            delete[] elements[i];
        }
        delete[] elements;
    }

private:
    T** elements = nullptr;
    int numRows = 0;
    int numCols = 0;
};

int main()
{
    table<int> test(2, 3);
    test.setElement(0, 0, 4);
    std::cout << test.getElement(0, 0) << std::endl;

    return 0;
}
