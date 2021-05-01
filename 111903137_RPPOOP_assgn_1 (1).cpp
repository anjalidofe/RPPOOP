/*
Anjali Dofe
MIS 111903137

Assignment No 1: Design and implement a class representing a rectangle and operations
like area, perimeter, change dimensions, report dimensions, on it. Write code to test your classes.
*/
#include<iostream>
#include<stdlib.h>

using namespace std;

class Rectange{
    int length, breadth;
    public :
        Rectange(){
            length = 0;
            breadth = 0;
        }
        void get_dimensions(){
            cout<<"Enter length of rectangle : ";
            cin>>length;
            cout<<"\nEnter breadth of rectangle : ";
            cin>>breadth;
        }
        void area(){
            cout<<"\nArea of rectangle = "<<(length * breadth);
        }
        void perimeter(){
            cout<<"\nPerimeter of rectangle = "<<((2)*(length + breadth));
        }
}R;

int main(){
    int i;
    char answer;
    do{
        system("cls");//to clear screen as to avoid overcrowding and for more presentable look
        cout<<"1. Enter dimensions of rectangle";
        cout<<"\n2. Get Area of rectangle";
        cout<<"\n3. Get Perimeter of rectangle";
        cout<<"\n4. Exit";
        cout<<"\nEnter your choice [1-4] : ";
        cin>>i;
        switch(i){
            case 1 :
                R.get_dimensions();
                break;
            case 2 :
                R.area();
                break;
            case 3 :
                R.perimeter();
                break;
            case 4 :
                exit(0);
            default :
                cout<<"\nInvalid choice!";
        }
        cout<<"\nDo you want to continue ? [y-n] ";
        cin>>answer;
    }while(answer == 'y' || answer == 'Y');
}
