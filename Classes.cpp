

#include "classes.h"
#include <windows.h>
using namespace std;
 table::table()
 {
 	for(int i=1; i<9; i++)
 	{
 		for(int l=1; l<9; l++)
 		{
 			map[i][l]=3;
		 }
	 }
	 for(int a=0; a<8; a++)
	 {
	 	alf[a]=65+a;
	 }
 }
int table::print()
 {
 	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 	for(int a=0; a<9; a++)
 	{
 		for(int b=0; b<9; b++)
 		{
 			if(b==0&&a!=0)
 			{
 				cout<<alf[a-1];
			 }
			 if(a==0&&b!=0)
			 {
			 	cout<<b;
			 }
			 if(map[a][b]==1)
			 {
			 	cout<<"#";
			 }
			 if(map[a][b]==2)
			 {
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
			 	cout<<"#";
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			 }
				 if(map[a][b]==3&&a!=0&&b!=0)
			 {
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			 	cout<<"~~";
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			 }
			 cout<<"\t";
		 }
		 cout<<"\n\n";
	 }
	 for(int v=0; v<80; v++)
	 {
	 	cout<<"_";
	 }
	 cout<<"\n\n";
 }
 
 
 ship::ship(int l)
 {
 	l>0? l:3;
 	length=l;
 
 }
 void ship::insertShip(int i, table &t)
 {
 
 		int a, b=0, x1, y1;
 		cout<<"inserisci le cordinate della prua della nave "<<i<<" \n x: ";
 		cin>>x1;
 		cout<<"y: ";
 		cin>>y1;
 		controlValue(x1, y1, 0, i, t);
 		do
 		{
 			b=1;
 			cout<<"specifica il verso della nave:\n 1=verticale\n2=orizzontale\n ";
 			cin>>a;
 		switch (a)
 		{
 		case 1:
 			for(int f=1; f<length; f++)
 			{
 				position[f][1]=position[f-1][1]+1;
 				position[f][0]=position[f-1][0];
 				
			 }
 				break;
 			case 2:
 			for(int f=1; f<length; f++)
 			{
 				position[f][0]=position[f-1][0]+1;
 				position[f][1]=position[f-1][1];
			 }
 				break;
 			default:
 				system("cls");
 				cout<<"valore non consentito, riprova...\n";
 				b=0;	
		 }
 			
 				
		 }while(b==0);
 		
	 
 }
 
 void ship::controlValue(int x, int y, int b, int i, table &t)
 {
 	if(t.map[y][x]==3)
 	{
 		position[b][0]=x;
 		position[b][1]=y;
 		t.map[y][x]=1;		 
	 }
	 else
	 {
	 	cout<<"errore, riprova...";
	 	insertShip(i, t);
	 }

 }
 
 
 
 

