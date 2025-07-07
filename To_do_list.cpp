// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
const int max_num=100;
int count =0;

typedef struct to_do{
    string task;
    bool complete;
}td;
td list[max_num];

void add();
void delete_task();
void mark_task();
void display();
int main() {
    // Write C++ code here
    int choice;
    do{
    cout<<"           _____TO DO LIST_____\n";
    cout<<"1. Add new task.\n";
    cout<<"2. Remove task.\n";
    cout<<"3. Mark task completed.\n";
    cout<<"4. View all tasks.\n";
    cout<<"5. Exit.\n"<<endl;
    cout<<"Enter your choice:";
    cin>>choice;
    
    switch(choice){
        case 1: add();
                break;
        case 2: delete_task();
                break;
        case 3: mark_task();
               break;
        case 4: display();
                break;
       case 5: cout<<"You have exited successfully.\n\n";
                break;
        default:
              cout<<"\nWrong input.\n";
              cout<<"Please try again.\n"<<endl;
    }
    } while(choice!=5);
    return 0;
}

void add(){
    if(count>=max_num){
        cout<<"To do list is full.\nSpace not available."<<endl;
        return;
    }
    cin.ignore();
    cout<<"Enter your task:\n";
    getline(cin,list[count].task);
    list[count].complete=false;
    count++;
    cout<<"Task added successfully.\n"<<endl;
}

void delete_task(){
    if(count==0){
        cout<<"To do list is empty.\n"<<endl;
        return;
    }
    int option, index;
    cout<<"1. Enter task no. directly.\n";
    cout<<"2. View all tasks first.\n"<<endl;
    cout<<"Enter your option:";
    cin>>option;
    if(option==1){
       cout<<"Enter task number:";
       cin>>index;
      
       if(index<1||index>count){
           cout<<"Invalid task number.\n"<<endl;
           return;
       }
       for(int i=index-1;i<count-1;i++){
           list[i]=list[i+1];
       }
       count--;
       cout<<"Task removed successfully.\n"<<endl;
    }
    else if(option==2){
       display();
       cout<<"Enter task number:";
       cin>>index;
       if(index<1||index>count){
           cout<<"Invalid task number.\n"<<endl;
           return;
       }
       for(int i=index-1;i<count-1;i++){
           list[i]=list[i+1];
       }
       count--;
       cout<<"Task removed successfully.\n"<<endl;
    }else{
        cout<<"Wrong option!!\n";
        cout<<"Please try again.\n"<<endl;
    }
    
}

void mark_task(){
    if(count==0){
        cout<<"To do list is empty.\n"<<endl;
        return;
    }
    int option, index;
    cout<<"1. Enter task no. directly.\n";
    cout<<"2. View all tasks first.\n"<<endl;
    cout<<"Enter your option:";
    cin>>option;
    if(option==1){
       cout<<"Enter task number:";
       cin>>index;
       if(index<1||index>count){
           cout<<"Invalid task number.\n"<<endl;
           return;
       }
       list[index-1].complete=true;
       cout<<"Task marked as completed successfully.\n"<<endl;
       
  } else if (option==2){
      display();
      cout<<"Enter task no. = ";
      cin>>index;
      if(index<1||index>count){
           cout<<"Invalid task number.\n"<<endl;
          return;
       }
      list[index-1].complete=true;
      cout<<"Task marked as completed successfully.\n"<<endl;
      
  } else {
      cout<<"Invalid option entered.\n"<<endl;
  }
}

void display(){
    if(count==0){
        cout<<"To do list is empty.\n"<<endl;
        return;
    }
    int i;
    for(i=0;i<count;i++){
        cout<<i+1<<"."<<list[i].task;
        if(list[i].complete){
            cout<<" [Completed]"<<endl;
        }
        else{
            cout<<" [Pending]"<<endl;
        }
    }
    cout<<endl;
}