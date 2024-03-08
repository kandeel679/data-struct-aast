#include <iostream>
using namespace std;

typedef int ElmenetType;
struct node
{
    ElmenetType element;
    node *next;
};
typedef node *Position;
// Very important note, position p always points to the previous node to the current node to be processed
class List
{
private:
    node *head; // points to the first dummy node
    node *tail; // points to the last node
    int counter;

public:
    // create dummy node for efficiently insertion and deleteion
    List()
    {
        MakeNull();
    }
    void MakeNull()
    {
        head = new node;
        head->next = NULL;
        tail = head->next;
        counter = 0;
    }
    // returns a pointer to the last node of L
    Position END()
    {
        if (head->next == NULL)
            return head;
        return tail;
    }
    //	INSERT(x, p, L). Insert x at position p in list L,  If list L has no position p, the result is undefined.
    void Insert(ElmenetType x, Position p = NULL)
    {

        if (p == NULL)
            p = END();
        Position newNode = new node;
        newNode->element = x;
        newNode->next = p->next;
        p->next = newNode;
        if (newNode->next == NULL)
            tail = newNode;
        counter++;
    }
    //	Delete the element at position p of list L. If L is a0, a1, a2, . . . ,an-1, then L becomes a0, a1, a2, . . . ,ap- 1, ap+1, . . . ,an-1. The result is undefined if L has no position p or if p = END(L).
    void Delete(Position p)
    {
        if (p == END() || p == NULL)
        {
            cout << "No Element to be deleted";
        }
        if (p->next == tail)
            tail = p;
        Position temp = p->next;
        p->next = p->next->next;
        temp->next = NULL;
        delete temp;
        counter--;
    }
    // returns the position of x on list L. If x appears more than once, then the position of the first occurrence is returned. If x does not appear at all, then END(L) is returned.
    Position Locate(ElmenetType x)
    {
        Position p = head;
        while (p->next != NULL)
        {
            if (p->next->element == x)
                return p;
            p = p->next;
        }
        return p; // equivalent to return END();
    }
    // locate x in the range pos to endPos
    Position LocateInRange(ElmenetType x, Position pos, Position endPos)
    {
        Position p = pos;
        while (p->next != endPos && p->next != NULL)
        {
            if (p->next->element == x)
                return p;
            p = p->next;
        }
        return p; // equivalent to return END();
    }

    // This function returns the element at position p on list L. The result is undefined if p = END(L) or if L has no position p. Note that the elements must be of a type that can be returned by a function if RETRIEVE is used. In practice, however, we can always modify RETRIEVE to return a pointer to an object of type elementtype.
    ElmenetType Retrieve(Position pos)
    {
        if (pos == NULL)
        {
            cout << "ERROR in reterive";
            return -1;
        }
        return pos->next->element;
    }

    void PrintList()
    {
        cout << "List is:";
        Position p = head->next;
        while (p != NULL)
        {
            cout << p->element << " ";
            p = p->next;
        }
        cout << endl;
    }
    // This function returns the first position on list L. If L is empty, the position returned is END(L
    Position First()
    {
        return head;
    }
    // return the positions following and preceding position p on list L. If p is the last position on L, then NEXT(p, L) = END(L). NEXT is undefined if p is END(L). PREVIOUS is undefined if p is 0. Both functions are undefined if L has no position p.
    Position Next(Position pos)
    { // you must write constrains here
        if (pos == tail)
            return NULL;
        return pos->next;
    }
    Position Previous(Position pos)
    { // you must write constrains here
        if (pos == head)
            return NULL;
        Position q = head;
        while (q != NULL && q->next != pos)
        {
            q = q->next;
        }
        return q;
    }

    int Size()
    {
        return counter;
    }
};

void splitOddEven(List l, List &odd, List &even)
{
    node *temp = l.First()->next;
    while (temp != NULL)
    {
        if (temp->element % 2 == 0)
        {
            even.Insert(temp->element);
        }
        else
        {
            odd.Insert(temp->element);
        }
    }
}

void Rev(List &l)
{
    node *prev = NULL;
    node *curr = l.First()->next;
    node *next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    l.First()->next = prev;
}

int main()
{
    List l = List();
    l.Insert(1);
    l.Insert(2);
    l.Insert(3);
    l.Insert(4);
    l.PrintList();
    Rev(l);
    l.PrintList();
}