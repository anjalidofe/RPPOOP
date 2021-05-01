/*
Anjali Dofe
MIS 111903137

Design and implement classes representing a polygon shape, and derived classes
like rectangle, and square with the same operations as mentioned in assignment
above. Write code to test your classes.

*/
#include <iostream>
using namespace std;

//Base class
class Shape{
    protected:
        int width;
        int height;
    public:
        void setWidth(int w){
            width = w;
        }
        void setHeight(int h){
            height = h;
        }
};

//Derived Class
class Rectangle: public Shape{
    public:
        void getArea(){
            cout<<"\nTotal area of the rectangle is = "<<(width*height)<<" sq.units"<<endl;
        }
        void perimeter(){
            cout<<"\nPerimeter of rectangle = "<<((2)*(width + height))<<" units"<<endl;
        }
}r1;

//Derived Class
class Square: public Shape{
    public:
        void getArea(){
            cout<<"\nTotal area of the square is = "<<(width*width)<<" sq.units"<<endl;
        }
        void perimeter(){
            cout<<"\nPerimeter of square = "<<((4)*(width))<<" units"<<endl;
        }
}s1;

int main(){
    int i, l, b;
    char answer, polygon;
    do{
        //system("cls");//to clear screen as to avoid overcrowding and for more presentable look
        cout<<"1. Enter dimensions of polygon";
        cout<<"\n2. Get Area ";
        cout<<"\n3. Get Perimeter ";
        cout<<"\n4. Exit";
        cout<<"\nEnter your choice [1-4] : ";
        cin>>i;
        switch(i){
            case 1 :
            {
                cout<<"For Square : s, For rectangle : r"<<endl;
                cin>>polygon;
                if(polygon == 'r'|| polygon == 'R'){
                    cout<<"\nEnter length and breadth"<<endl;
                    cin>>l;
                    cin>>b;
                    r1.setWidth(l);
                    r1.setHeight(b);
                }
                if(polygon == 's'|| polygon == 'S'){
                    cout<<"\nEnter side"<<endl;
                    cin>>l;
                    s1.setWidth(l);
                    cout<<"\n";
                }
                break;
            }
            case 2 :
            {
                if(polygon == 'r'|| polygon == 'R')
                    r1.getArea();
                if(polygon == 's'|| polygon == 'S')
                    s1.getArea();
                break;
            }
            case 3 :
            {
                if(polygon == 'r'|| polygon == 'R')
                    r1.perimeter();
                if(polygon == 's'|| polygon == 'S')
                    s1.perimeter();
                break;
            }
            case 4 :
                exit(0);
            default :
                cout<<"\nInvalid choice!";
        }
        cout<<"\nDo you want to continue ? [y-n] ";
        cin>>answer;
    }while(answer == 'y' || answer == 'Y');
    return 0;
}

