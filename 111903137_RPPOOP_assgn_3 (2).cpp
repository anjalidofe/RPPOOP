/*
ANJALI DOFE
MIS : 111903137
Develop an object oriented program in C++ to create a database of covid-19 patient information
system containing the following information: Name, appointment number, symptoms, hospital name,
Date of Birth, Blood group, contact address, mobile number, adhar card no. etc. Construct the
database with suitable member functions for initializing and destroying the data viz constructor,
default constructor, Copy constructor, destructor, static member functions, friend class, this
pointer, inline code and dynamic memory allocation operators-new and delete.
*/
#include <iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class covid_patient_db //Covid Database
{
    char app[50];//
    char name[50];
    char symp[100];
    char hos[50];
    char dob[30];
    char bg[30];
    char contact[30];
    int phone;
    char aadhar[30];

    public:
    static int stdno;
    static void count()
   {
      cout<<"\nNo. of objects created: "<<stdno;
   }
    void fin(){cout<<"\nThis is my Inline Function!";}

   covid_patient_db()
   {
        strcpy(name,"Anjali");
        strcpy(app, " 123 ");
        strcpy(symp," Cough,cold ");
        strcpy(hos," Sancheti ");
        strcpy(dob,"22/07/2001");
        strcpy(bg," O+ ");
        strcpy(contact," Pune ");
        phone = 98761;
        strcpy(aadhar," A0101010 ");
        ++stdno;
   }
   covid_patient_db(covid_patient_db *obj)
   {
        strcpy(name,obj->name);
        strcpy(app, obj->app);
        strcpy(symp,obj->symp);
        strcpy(hos,obj->hos);
        strcpy(dob,obj->dob);
        strcpy(bg,obj->bg);
        strcpy(contact,obj->contact);
        phone = obj->phone;
        strcpy(aadhar,obj->aadhar);
        ++stdno;
   }
    void getdata()
   {
       cout<<"\nEnter name: ";
       cin>>name;
       cout<<"Appointment Number : ";
       cin>>app;
       cout<<"Symptoms : ";
       cin>>symp;
       cout<<"Hospital name: ";
       cin>>hos;
       cout<<"DOB : ";
       cin>>dob;
       cout<<"Bloodgroup : ";
       cin>>bg;
       cout<<"City : ";
       cin>>contact;
       cout<<"Phone number : ";
       cin>>phone;
       cout<<"Aadhar number: ";
       cin>>aadhar;
       cout<<"\n";
   }
   friend void display(covid_patient_db d);
   ~covid_patient_db()
   {
      cout<<"\n"<<name<<"(Object) is destroyed!";
   }
};

void display(covid_patient_db d)
{
    cout<<"\n"<<setw(9)<<d.name<<setw(8)<<d.app<<setw(15)<<d.dob<<setw(12)<<d.hos<<setw(15)<<d.symp<<setw(7)<<d.bg<<setw(12)<<d.phone<<" "<<setw(12)<<d.contact<<setw(12)<<d.aadhar;
//    cout<<"\n"<<d.name;
//    cout<<"  "<<d.app;
//    cout<<"  "<<d.symp;
//    cout<<"  "<<d.hos;
//    cout<<"  "<<d.dob;
//    cout<<"  "<<d.bg;
//    cout<<"  "<<d.contact;
//    cout<<"  "<<d.phone;
//    cout<<"  "<<d.aadhar<<"\n";
}
int covid_patient_db::stdno;

int main()
{
    int n,i;
    covid_patient_db d1, *ptr[100];
    cout<<"\nDefault values:";
    display(d1);

    d1.getdata();
    display(d1);

    covid_patient_db d2(&d1);
    cout<<"\n\nUse of copy constructor :\n";
    display(d2);


    cout<<"\nHow many objects u want to create?:";
    cin>>n;
    for(i = 0; i < n; i++)
    {
        ptr[i] = new covid_patient_db();
        ptr[i]->getdata();
    }
     cout<<"\n"<<setw(7)<<"Name, "<<setw(8)<<"Appointment Number, "<<setw(12)<<"Date of birth, "<<setw(12)<<"Hospital name, "<<setw(12)<<"Symptoms, "<<setw(7)<<"Blood group, "<<setw(12)<<"Contact Number, "<<setw(12)<<"City, "<<setw(12)<<"Aadhar";
    //cout<<"\nEnter name  ,Application Number,  Symptoms,  Hospital name,  DOB,  Bloodgroup,  City,  Phone number,  Aadhar number: \n";
   for(i = 0; i < n; i++)
     display(*ptr[i]);
   covid_patient_db::count();
   for(i = 0; i < n; i++)
   {
     delete(ptr[i]);
   }
   cout<<"\nObjects deleted!" ;
   return 0;
}
