#include <iostream>
using namespace std;

typedef int ElmenetType;
typedef int Position;
class List
{
private:
	ElmenetType *elements;
	int capacity;
	Position last;

public:
	List()
	{
		elements = new ElmenetType[100];
		capacity = 100;
		last = -1;
	}
	List(int n)
	{
		elements = new ElmenetType[n];
		capacity = n;
		last = -1;
	}
	void MakeNull()
	{
		last = -1;
	}
	Position END()
	{
		return last + 1;
	}
	void Insert(ElmenetType x, Position pos)
	{
		if (last == capacity - 1)
			cout << "list is full";
		else if (pos > last + 1 || pos < 0)
			cout << pos << ":pos is out of range" << last;
		else
		{
			for (int i = last; i >= pos; i--)
			{
				elements[i + 1] = elements[i];
			}
			last++;
			elements[pos] = x;
		}
	}
	void Delete(Position pos)
	{
		if (pos > last || pos < 0)
			cout << "pos is out of range";

		for (int i = pos + 1; i <= last; i++)
			elements[i - 1] = elements[i];
		last--;
	}
	Position Locate(ElmenetType x)
	{
		for (int i = 0; i <= last; i++)
		{
			if ((x == elements[i]))
				return i;
		}
		return END();
	}

	ElmenetType Retrieve(Position pos)
	{
		if (pos > last || pos < 0)
		{
			cout << "pos is out of range";
			return -1;
		}
		return elements[pos];
	}
	void PrintList()
	{
		for (int i = 0; i <= last; i++)
		{
			if (i == last)
			{
				cout << elements[i];
			}
			else
			{
				cout << elements[i] << "-";
			}
		}
		cout << endl;
	}
	Position First()
	{
		return 0;
	}
	Position Next(Position pos)
	{ // you must write constrains here
		return pos + 1;
	}
	Position Previous(Position pos)
	{ // you must write constrains here
		return pos - 1;
	}
	int Size()
	{
		return END();
	}
};
ElmenetType maxValue(List l)
{
	int max;
	max = l.Retrieve(l.First());
	for (int i = 0; i < l.Size(); i++)
	{
		ElmenetType elmenet = l.Retrieve(i);
		if (elmenet > max)
		{
			max = elmenet;
		}
	}
	return max;
}
List con(List l1, List l2)
{
	int NewListSize = l1.Size() + l2.Size();
	List NewList = List(NewListSize);
	for (int i = 0; i < l1.Size(); i++)
	{
		NewList.Insert(l1.Retrieve(i), i);
	}

	for (int j = 0, i = l1.Size(); i < NewListSize; i++, j++)
	{
		NewList.Insert(l2.Retrieve(j), i);
	}
	return NewList;
}
int main()
{
	List l = List();
	l.Insert(11, 0);
	l.Insert(12, 1);
	l.Insert(16, 2);
	l.Insert(17, 3);
	l.Insert(37, 4);
	l.Insert(172, 5);
	List L = List();
	L.Insert(11, 0);
	L.Insert(12, 1);
	L.Insert(16, 2);
	L.Insert(17, 3);
	L.Insert(37, 4);
	L.Insert(172, 5);
	// cout << maxValue(l);
	List l2 = con(l, L);
	l2.PrintList();
}