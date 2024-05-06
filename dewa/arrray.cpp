#include <iostream>
using namespace std;
class Array
{
private:
    int size;
    int *data;
    int last; // size => 6 ,last=>4 [5,6,4,7,8, ]
public:
    Array()
    {
        data = new int[100];
        size = 100;
        last = -1;
    }
    Array(int n)
    {
        size = n;
        data = new int[size];
        last = -1;
    }
    void Insert(int x, int pos)
    {
        for (int i = last; i >= pos; i--)
        {
            data[i + 1] = data[i];
            cout << i << "\n";
        }
        last++;
        data[pos] = x;
    }
    void PrintList()
    {
        for (int i = 0; i <= last; i++)
        {
            if (i == last)
            {
                cout << data[i];
            }
            else
            {
                cout << data[i] << "-";
            }
        }
        cout << endl;
    }
};

int main()
{
    Array a2 = Array(2);
    a2.Insert(5, 0);
    a2.Insert(6, 1);
    a2.Insert(4, 2);
    a2.Insert(7, 3);
    a2.Insert(8, 4);
    a2.Insert(3, 1);
    a2.Insert(9, 1);
    a2.Insert(19, 1);

    a2.PrintList();
}