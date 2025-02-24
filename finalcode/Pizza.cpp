#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
#include<malloc.h>

using namespace std;
string name,address;
int phno;
class Node
{
public:
int data;
Node *next;
};
 Node *start = NULL;
void create_ll(Node **,int num);
void delete_list(Node **);

void create_ll(Node **start,int num)
{
Node *new_node=new Node();
Node *last= *start;
new_node -> data=num;
new_node -> next = NULL;
   if(*start==NULL){
    *start = new_node;
    return;
  }
 while (last->next != NULL)
        last = last->next;

last->next = new_node;
return;
}

void delete_list(Node **start)
{
Node* current = *start;
    Node* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *start = NULL;
}
 void details()
{
cout << "\nEnter your name :";
getline(cin,name);
cout<<"\nEnter phone number:";
cin>>phno;
cout<<"\nEnter address:";
cin.ignore();
getline(cin,address);
}

void menu(){
ofstream fout;
int topping,slice,sides,crust,extras;
char c;
fout.open("order.txt");
do{
cout<<"\nMenu\nChoose your desired topping:\n1.Paneer\tRs.10\n2.Capsicum\tRs.3\n3.Mushroom\tRs.5\n4.Jalapeno\tRs.8\n5.Olives\tRs.8";
cout<<"\n6.Corn\tRs.4\n7.Onion\tRs.7\n8.Tomato\tRs.3\n9.Sausage\tRs.10\n10.Pepperoni\tRs.10\n";
cin>>topping;

switch(topping){
case 1:
    fout<<"Paneer-Rs.10\n";
    create_ll(&start,10);
    break;

case 2:
    fout<<"Capsicum-Rs.3\n";
    create_ll(&start,3);
    break;
case 3:
    fout<<"Mushroom-Rs.5\n";
    create_ll(&start,5);
    break;

case 4:
    fout<<"Jalapeno-Rs.8\n";
    create_ll(&start,8);
    break;
case 5:
    fout<<"Olives-Rs.8\n";
    create_ll(&start,8);
    break;

case 6:
    fout<<"Corn-Rs.4\n";
    create_ll(&start,4);
    break;

case 7:
    fout<<"Onion-Rs.7\n";
    create_ll(&start,7);
    break;

case 8:
    fout<<"Tomato-Rs.3\n";
    create_ll(&start,3);
    break;

case 9:
    fout<<"Sausage-Rs.10\n";
    create_ll(&start,10);
    break;

case 10:
    fout<<"Pepperoni-Rs.10\n";
    create_ll(&start,10);
    break;

default: cout<<"\nWrong choice!";
         break;
}
cout<<"\nDo you want to add more toppings?\nType y to continue or if you have finished type n:";
cin>>c;
}while(c=='y'||c=='Y');

cout<<"\nChoose the size of your pizza:\n1.Small(4 slices)\tRs.100\n2.Medium(6 slices)\tRs.200\n3.Large(8 slices)\tRs.400\n";
cin>>slice;
switch(slice){
case 1:
      fout<<"Small-Rs.100\n";
      create_ll(&start,100);
      break;

case 2:
    fout<<"Medium-Rs.200\n";
    create_ll(&start,200);
    break;

case 3:
    fout<<"Large-Rs.400\n";
    create_ll(&start,400);
    break;

default:cout<<"\nWrong choice!";
         break;
}

cout<<"\nChoose the crust type:\n1.Handtossed\tRs.0\n2.Thin Crust\tRs.20\n3.Cheese burst\tRs.50\n";
cin>>crust;
switch(crust){
case 1:
    fout<<"Handtossed-Rs.0\n";
    create_ll(&start,0);
    break;
case 2:
    fout<<"Thin Crust-Rs.20\n";
    create_ll(&start,20);
    break;
case 3:
    fout<<"Cheese burst-Rs.50\n";
    create_ll(&start,50);
    break;
default:cout<<"\nWrong choice!";
         break;
}
do{
cout<<"\nChoose your side dish:\n1.Pasta\tRs.80\n2.Choco Lava Cake\tRs.70\n3.Garlic bread\tRs.100\n4.Pepsi\tRs.60\n5.None\n";
cin>>sides;

switch(sides){
case 1:
    fout<<"Pasta-Rs.80\n";
    create_ll(&start,80);
    break;

case 2:
    fout<<"Choco Lava Cake-Rs.70\n";
    create_ll(&start,70);
    break;
case 3:
    fout<<"Garlic bread-Rs.100\n";
    create_ll(&start,100);
    break;
case 4:
    fout<<"Pepsi-Rs.60\n";
    create_ll(&start,60);
    break;
case 5: break;
}
cout<<"\nDo you want to add more side dishes?\nType y to continue or if you have finished type n:";
cin>>c;
}while(c=='y'||c=='Y');

do{
cout<<"Menu\nExtras:\n1.Cheese\tRs.20\n2.Oregano\tRs.10\n3.Chilli Flakes\tRs.10\n4.Ketchup\tRs.10\n5.None\n";
cin>>extras;

switch(extras){
case 1:
    fout<<"Cheese-Rs.20\n";
    create_ll(&start,20);
    break;

case 2:
    fout<<"Oregano-Rs.10\n";
    create_ll(&start,10);
    break;
case 3:
    fout<<"Chilli Flakes-Rs.10\n";
    create_ll(&start,10);
    break;

case 4:
    fout<<"Ketchup-Rs.10\n";
    create_ll(&start,10);
    break;
case 5:
    break;
}
cout<<"\nDo you want to add more condiments?\nType y to continue or if you have finished type n:";
cin>>c;
}while(c=='y'||c=='Y');

}

int calc(Node **start)
{
Node *ptr= *start;
int sum=0;
while(ptr != NULL)
{
sum+= ptr -> data;
ptr = ptr -> next;
}
return sum;
}

void fbill(){
system("cls");
const int n=100;
char line[n];
ifstream fin;
cout<<"\nBILL\nName:"<<name<<"\nContact number:"<<phno<<"\nAddress:"<<address<<"\nYour Order:";
fin.open("order.txt");
while(fin){

 fin.getline(line,n);
 cout<<"\n"<<line;
}
}

int main() {

     cout<<"Welcome to Pizzeria!";
     cout<<"\nPress Enter to continue";
     getch();
    system("cls");
    details();
    menu();
    fbill();
    int sum=calc(&start);
    cout<<"Total amount to be paid:"<<sum;
	return 0;
  }

