#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

int total=0;


class Contact
{
private:
    struct
    {
        string name,email,relational_status,address,phone_number;
        int id;
    } property [1000];
public:
    void option();
    void addNumber();
    void editNumber();
    void searchNumber();
    void viewNumber();
    void deleteNumber();
    void openFile();
    void saveFile();


    Contact()
    {
        option();
    }
};


int main()
{
    Contact c;
    return 0;
}

void Contact::option()
{
    Contact::openFile();
    while(true)
    {
        HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
        int select;
        SetConsoleTextAttribute(h,12);
        cout<<"\t\t\tMain Menu"<<endl;
        SetConsoleTextAttribute(h,2);
        cout<<"\t\t\t1. Add a number"<<endl;
        cout<<"\t\t\t2. Edit a number"<<endl;
        cout<<"\t\t\t3. Search a number"<<endl;
        cout<<"\t\t\t4. View all numbers"<<endl;
        cout<<"\t\t\t5. Delete a number"<<endl;
        cout<<"\t\t\t6. Exit"<<endl;
        cout<<"\t\t\t";
        cin>>select;
        system("cls");
        switch(select)
        {
        case 1:
            Contact::addNumber();
            break;
        case 2:
            Contact::editNumber();
            break;
        case 3:
            Contact::searchNumber();
            break;
        case 4:
            Contact::viewNumber();
            break;
        case 5:
            Contact::deleteNumber();
            break;
        case 6:
            exit(true);
            break;
        default:
            cout<<"Invalid Input"<<endl;
        }
    }
}


void Contact::addNumber()
{
    cout<<"\t\t\tAdd a Number"<<endl;
    cout<<"Enter Name: ";
    cin>>property[total].name;
    cout<<"Enter Id: ";
    cin>>property[total].id;
    cout<<"Enter Phone Number: ";
    cin>>property[total].phone_number;
    cout<<"Enter Email:";
    cin>>property[total].email;
    cout<<"Status: ";
    cin>>property[total].relational_status;
    cout<<"Address: ";
    cin>>property[total].address;
    total++;
    system("cls");
    Contact::saveFile();
    cout<<"Number Added Successfully"<<endl;
    Sleep(1500);
    system("cls");
}

void Contact::viewNumber(){
    if(total==0){  //total==0 means we don't have any contact number
        system("cls");
        cout<<"add a new contact"<<endl;
        Sleep(1500);
        system("cls");
    }
    cout<<"\t\t\tAll Numbers"<<endl;
    for(int i=0;i<total;i++){
    cout<<"Name: "<<property[i].name;
    cout<<"\tID:"<<property[i].id;
    cout<<"\tPhone number: "<<property[i].phone_number<<endl;
    }
    system("pause");
    cout<<"\n\n";
    system("cls");
}

void Contact::searchNumber(){
    if(total==0){  //total==0 means we don't have any contact number
        system("cls");
        cout<<"add a new contact"<<endl;
        Sleep(1500);
        system("cls");
    }

    int id;
    cout<<"Enter ID: ";
    cin>>id;
    for(int i=0;i<total;i++){

        if(id==property[i].id){
            cout<<"Name: "<<property[i].name<<endl;
            cout<<"Id: "<<property[i].id<<endl;
            cout<<"Phone number: "<<property[i].phone_number<<endl;
            cout<<"Email"<<property[i].email<<endl;
            cout<<"Status: "<<property[i].relational_status<<endl;
            cout<<"Address: "<<property[i].address<<endl;

            system("pause");
            system("cls");
            break;
        }
    }
}


void Contact::editNumber(){
    if(total==0){  //total==0 means we don't have any contact number
        system("cls");
        cout<<"add a new contact"<<endl;
        Sleep(1500);
        system("cls");
    }
    int id;
    cout<<"Enter Id:"<<endl;
    cin>>id;
    for(int i=0;i<total;i++){
         if(id==property[i].id){
            cout<<"Previous Info"<<endl;
            cout<<"Name: "<<property[i].name<<endl;
            cout<<"Id: "<<property[i].id<<endl;
            cout<<"Phone number: "<<property[i].phone_number<<endl;
            cout<<"Email: "<<property[i].email<<endl;
            cout<<"Status: "<<property[i].relational_status<<endl;
            cout<<"Address: "<<property[i].address<<endl;

            cout<<"Enter new Info"<<endl;
            cout<<"Enter Name: ";
            cin>>property[i].name;
            cout<<"Enter Phone Number: ";
            cin>>property[i].phone_number;
            cout<<"Enter Email:";
            cin>>property[i].email;
            cout<<"Status: ";
            cin>>property[i].relational_status;
            cout<<"Address: ";
            cin>>property[i].address;
            system("cls");
            Contact::saveFile();
            cout<<"Info Updated successfully"<<endl;
            Sleep(1500);
            system("cls");
            break;
        }

    }

}

void Contact::deleteNumber(){
    if(total==0){  //total==0 means we don't have any contact number
        system("cls");
        cout<<"add a new contact"<<endl;
        Sleep(1500);
        system("cls");
    }
    int id;
    cout<<"Enter id: ";
    cin>>id;
    for(int i=0;i<total;i++){
        if(id==property[i].id){
                for(int j=i;j<total;j++){
                    property[j].name=property[j+1].name;
                    property[j].id=property[j+1].id;
                    property[j].phone_number=property[j+1].phone_number;
                    property[j].email=property[j+1].email;
                    property[j].relational_status=property[j+1].relational_status;
                    property[j].address=property[j+1].address;
                }
                system("cls");
                Contact::saveFile();
                cout<<"Contact Number is Deleted"<<endl;
                Sleep(1500);
                system("cls");
                total--;
                break;
        }

    }

}

void Contact::saveFile(){
    ofstream file;
    file.open("storage.txt"); //file create and open
    for(int i=0;i<total;i++){
        file<<endl;
        file<<property[i].name;
        file<<'\t';
        file<<property[i].id;
        file<<'\t';
        file<<property[i].phone_number;
        file<<'\t';
        file<<property[i].email;
        file<<'\t';
        file<<property[i].relational_status;
        file<<'\t';
        file<<property[i].address;
    }
    file.close();
}

void Contact::openFile(){
    int index=0;
    ifstream file;
    file.open("storage.txt");
    while(file>>property[index].name>>property[index].id>>property[index].phone_number>>property[index].email>>property[index].relational_status>>property[index].address){
        index++;
        total++;
    }
    file.close();
}
