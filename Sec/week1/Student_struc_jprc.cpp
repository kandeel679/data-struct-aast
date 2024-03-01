#include <iostream>
#include <string>
using namespace std;

struct Student 
{
    string name;
    int id;
    double GPA;
    void print(){
        cout << name << "\n"<< id<< "\n" << GPA<< "\n";
    }
};
void PrintArrRec(int *arr,int size);
int main(){
   Student *s = new Student;
    cout << "Enter name: ";
    cin >> s->name; 
    cout << "Enter ID: ";
    cin >> s->id; 
    cout << "Enter GPA: ";
    cin >> s->GPA;
    s->print(); 

    //rec

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size =10;
    PrintArrRec(arr,size);

    return 0;
}
void PrintArrRec(int *arr,int size){
    if (size>=0)
    {
        PrintArrRec(arr,size-1);
        cout << arr[size-1] << "  ";
        // if you switch the order of the lines you wil get the output on revirce 
    }
    
}