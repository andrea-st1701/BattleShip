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
	
		
 		int a=1;
		point c;
 		bool  b=true;
 		c.x=rand()%8+1;
 		c.y=rand()%8+1;
 		b=controlValue(c, t, b);
 		if(b==false)
 		{
 			insertShip(i, t);//!!!
		 }
		 else
		 {
		 	
		a=rand()%2+1;
 		switch (a)
 		{
 			case 1:
 			for(int f=0; f<length-1; f++)
 			{
 				c.y+=1;
 				b=controlValue(c, t, b);
 		
			 }
			if(b==false)
 			{
				insertShip(i, t);
			}
			 else
			 {
			 	c.y-=length;
			 	for(int g=0; g<length; g++)
			 	{
			 		c.y+=1;
			 		position[g].x=c.x;
			 		position[g].y=c.y;
				 }
			 }
 				break;
 			case 2:
 			for(int f=0; f<length-1; f++)
 			{
 				c.x+=1;
 				b=controlValue(c, t, b);
			 }
			 	if(b==false)
 				{
					insertShip(i, t);
				 }
				 else
				 {
				 	c.x-=length;
				 	for(int g=0; g<length; g++)
				 	{
				 		c.x+=1;
				 		position[g].x=c.x;
				 		position[g].y=c.y;
					 }
				 }
 				break;
 	
		 }
		
 				
 			for(int z=0; z<length; z++)
 		{
 			t.setMap(1, position[z]);
 			t.setId(i, position[z]);
 						
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
			 if(map[a][b]==1)
			 {
			 	cout<<"#";
			 }
			 if(map[a][b]==2)
			 {
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
			 	cout<<"X";
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			 }
				 if(map[a][b]==3 /*||map[a][b]==1*/)
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
	 	for(int a=0; a<9; a++)
 	{
 		for(int b=0; b<9; b++)
 		{
 			//cout<<map[a][b]<<"\t";
		 }
		 cout<<"\n\n";
	 }
 }
 //non va
void cannonAI::interfaccia(userTable &t, userShip *s)
{
	int  a;
	point f;
	a=getHit();
	if(a==-1)
	{
		srand(time(NULL));
		upHit(1);
	}
	if(a<=0)
	{
		f.x=rand()%8+1;
		f.y=rand()%8+1;
		setLast(f.x, 0);
		setLast(f.y, 1);
	}
	begin:
	if(a>0&&RLhoriz[1]) //se la nave è orizzontale
	{
		point c;
		c.x=getLast(0);
		c.y=getLast(1);
		if(RLhoriz[0]) //se la nave è verso destra
		{
			f.x=c.x+1;
			f.y=c.y;
		}
		if(!RLhoriz[0])//se la nave è verso sinistra
		{
			f.x=c.x-1;
			f.y=c.y;
		}
		int hit= t.getMap(f);
		if(hit==1)
		{
			upHit(1);
			setLast(f.x, 0);
			setLast(f.y, 1);
		}
		else
		{
			if(RLhoriz[0])//se prima si è controllata la possibilità orizzontale destra o verticale destra
			{
				!RLhoriz[0]; //si cambia in orizzontale/verticale sinistra=verso il basso
				goto begin;
			}
			if(RLhoriz[1]&&!RLhoriz[0])//possibilità orizzontale sinistra
			{
				RLhoriz[1];//vericale
				RLhoriz[0];//destra
				goto begin;
			}
		}
	}
	fire(f, t, s);
}
