#include "classesAI.h"
#include "classes.h"
#include "rtClasses.h"
#include <stdlib.h>
#include <iostream>
#include<time.h>
#include <windows.h>
using namespace std;

void ShipAI::insertShip(int i, tableAI &t)
{
	
		
 		int a=1, x1=0, y1=0;
 		bool  b=true;
 		x1=rand()%8+1;
 		y1=rand()%8+1;
 		b=controlValue(x1, y1, t, b);
 		if(b==false)
 		{
 			insertShip(i, t);//!!!
		 }
		 else
		 {
		 	position[0][0]=x1;
		 	position[0][1]=y1;
		a=rand()%2+1;
 		switch (a)
 		{
 			case 1:
 			for(int f=1; f<length; f++)
 			{
 				b=controlValue(x1, y1+f, t, b);
 		
			 }
			 		if(b==false)
 				{
					insertShip(i, t);
				 }
				 else
				 {
				 	for(int g=0; g<length; g++)
				 	{
				 		position[g][0]=x1;
				 		position[g][1]=y1+g;
					 }
				 }
 				break;
 			case 2:
 			for(int f=1; f<length; f++)
 			{
 				b=controlValue(x1+f, y1, t, b);
			 }
			 	if(b==false)
 				{
					insertShip(i, t);
				 }
				 else
				 {
				 	for(int g=0; g<length; g++)
				 	{
				 		position[g][0]=x1+g;
				 		position[g][1]=y1;
					 }
				 }
 				break;
 	
		 }
		
 				
 			for(int z=0; z<length; z++)
 		{
 			t.setMap(1, position[z][0], position[z][1]);
 			t.setId(i-1, position[z][0], position[z][1]);
 						
		 }
	 }
}
int tableAI::print()
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
			 if(map[a][b]==2)
			 {
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
			 	cout<<"X";
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			 }
				 if(map[a][b]==3||map[a][b]==1)
			 {
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			 	cout<<"~~";
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			 }
			   if(map[a][b]==4)
			 {
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			 	cout<<"O";
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
void cannonAI::interfaccia(userTable &t, userShip *s)
{
	int xf=0, yf=0, a;
	a=getHit();
	if(a==-1)
	{
		srand(time(NULL));
		upHit(1);
	}
	if(a<=0)
	{
		xf=rand()%8+1;
		yf=rand()%8+1;
		setLast(xf, 0);
		setLast(yf, 1);
	}
	begin:
	if(a>0&&RLhoriz[1]) //se la nave è orizzontale
	{
		int x, y;
		x=getLast(0);
		y=getLast(1);
		if(RLhoriz[0]) //se la nave è verso destra
		{
			xf=x+1;
			yf=y;
		}
		if(!RLhoriz[0])//se la nave è verso sinistra
		{
			xf=x-1;
			yf=y;
		}
		int hit= t.getMap(xf, yf);
		if(hit==1)
		{
			upHit(1);
			setLast(xf, 0);
			setLast(yf, 1);
		}
		else
		{
			if(RLhoriz[1])//se prima si è controllata la possibilità orizzontale destra o verticale destra
			{
				!RLhoriz[0]; //si cambia in orizzontale/verticale sinistra=verso il basso
				goto begin;
			}
			if(RLhoriz[1]&&!RLhoriz[0])//possibilità orizzontale sinistra
			{
				!RLhoriz[0];//vericale
				RLhoriz[1];//destra
			}
		}
	}
	fire(xf, yf, t, s);
}
