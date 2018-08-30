/* 
 * File:   main.cpp
 * Author: Khalid
 *
 * Created on 1 November, 2014, 7:35 PM
 */

//#include <cstdlib>
//
//using namespace std;
//
///*
// * 
// */
//int main(int argc, char** argv) {
//
//    return 0;
//}

//#include<iostream.h>
//#include<conio.h>
#include <stdio.h>
#include<iostream>
#include <sstream>
//#include <cstdlib>
#include<stdlib.h>
using namespace std;

//#include<iostream>
//#include<conio.h>
//#include<stdlib.h>

const std::string& ToString(int num){
    return static_cast<ostringstream*>( &(ostringstream() << num) )->str();
}

void printToCoordinates(int x, int y, const std::string& text)
{
    printf("\033[%d;%dH%s", x, y, text.c_str());
}
void statusUpdate(const std::string& text)
{
    printToCoordinates(24,9,"                                                                       ");
    printToCoordinates(24,9,text.c_str());
}
void clrscr() 
{ 
    for (int i=0;i<27;i++)
        for (int j=0;j<80;j++)
        printToCoordinates(i,j," ");
} 

class array
{
	int row,col,b[500],r,c;
public:
	array();
	void create();
	void assign();
	void cancel();
	void display();
};

array::array()
{
	row=1;
	col=1;
	r=1;
	c=1;
}

void array::create()
{
    printToCoordinates(21,50,"Number of vehicles:"); cin>>col;
    printToCoordinates(22,50,"Number of days:"); cin>>row;
    for(int i=1;i<(row*col);i++)
            b[i]=0;
    statusUpdate("Schedule has been created");
}

void array::assign()
{
    printToCoordinates(21,50,"which fleet:"); cin>>c;
    printToCoordinates(22,50,"what day:"); cin>>r;
    b[ r * col + c ] = 1;
    statusUpdate("Job assigned");
}

void array::cancel()
{
    printToCoordinates(21,50,"which fleet:"); cin>>c;
    printToCoordinates(22,50,"what day:"); cin>>r;
    b[ r * col + c] = 0;
    statusUpdate("Job canceled");
}

void array::display()
{
        printToCoordinates(0,0,"+============================================+================================+");
        
        for (int i=1;i<19;i++)
                printToCoordinates(i+1,0,"|                                                                             |");
        
        for (int i=1;i<31;i++) printToCoordinates(1,i*2+10,ToString(i/10));
        
        for (int i=1;i<31;i++) printToCoordinates(2,i*2+10,ToString(i%10));
        
	printToCoordinates(3,0,"+ Fleet======================================+================================+");
        
	for(int k=1;k<=col;k++) printToCoordinates(k+3,5, ToString(k));
        
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=col;j++) printToCoordinates(i+3,j*2+10, ToString(b[(i*j)+j]));
	}
}

int menu()
{       
        int ch=0;
        printToCoordinates(20,0,"+============================================+================================+");
	printToCoordinates(21,0,"|1.Create 2.Assign 3.Cancel 4.Display 0.Exit |                                |");
        printToCoordinates(22,0,"|Enter your choice:                          |                                |");
        printToCoordinates(23,0,"+============================================+================================+");
        printToCoordinates(24,0,"|Status:");printToCoordinates(24,79,"|");       
        printToCoordinates(25,0,"+============================================+================================+");
        printToCoordinates(22,20,"");
        cin>>ch;
        return ch;
}

int main()
{
	int ch,x,y;
	array f;
	//linkedlist<int> d;
	clrscr();
	while((ch=menu()) != 0)
	{
		switch(ch)
		{
			case 1:f.create(); break;
			case 2:f.assign(); break;
			case 3:f.cancel(); break;
			case 4:f.display();break;
			/*case 5:d.insert; break;
			case 6:d.extract;  break;
			case 7:d.displayRF;break;
			case 5:exit(0);*/
		}
	}
	getchar();
}

/*
template<class T>
class listelement
{
	T data;
	listelement<T>*next
	friend linkedlist<T>;
};
template<class T>
class linkedlist
{
	listelement<T>*head;
	listelement<T>*tail;
public:
	linkedlist()
	{
		head=0;
		tail=0;
	}
	void displayRF();
	void insert(T item);
	void extract(T item);
};
template<class T>
void linkedlist<T>::insert(T item)
{
	listelement<T>*temp=new listelement<T>;
	temp->data=item;
	temp->data=item;
	temp->next=0;
	tail->next=temp;
	if(head==0)
	head=temp;
	tail=temp;
}
template<class T>
void linkedlist<T>::displayRF()
{
	listelement<T>*current;
	if(head==0)
		cout<<"no damaged vehicles"<<endl;
	else
	{
		cout<<"the damaged vehicles are:"<<endl;
		for(current=head;current!=0;current=current->next)
			cout<<current<<data<<"\t"<<endl;
	}
}
*/