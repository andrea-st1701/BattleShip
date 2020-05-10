#include "Classes.h"
#include <windows.h>
void tableUser::print()
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 	for(int a=0; a<9; a++)
 	{
 		for(int b=0; b<9; b++)
 		{
 			
 			if(map[a][b]==0)
 			{
 				
	 			if(b==0&&a!=0)
	 			{
	 				cout<<(char)(64+a);
				}
				if(a==0&&b!=0)
				{
				 	cout<<b;
				}
			}
			if(map[a][b]>0&&map[a][b]<6)
			{
			 	cout<<"#";
			}
			if(map[a][b]==6)
			{
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
			 	cout<<"#";
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			}
			if(map[a][b]==404)
			{
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			 	cout<<"~~";
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			}
			if(map[a][b]==-1)
			{
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			 	cout<<"O";
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			}
				if(map2->getVal(b,a)==1)
 			{
 				SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			 	cout<<"#";
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
void tableAI::print()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 	for(int a=0; a<9; a++)
 	{
 		for(int b=0; b<9; b++)
 		{
 			if(map[a][b]==0)
 			{
 				
	 			if(b==0&&a!=0)
	 			{
	 				cout<<(char)(64+a);
				}
				if(a==0&&b!=0)
				{
				 	cout<<b;
				}
			}
			if(map[a][b]>0&&map[a][b]<6)
			{
			 	cout<<"~~";
			}
			if(map[a][b]==6)
			{
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
			 	cout<<"X";
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			}
			if(map[a][b]==404)
			{
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_INTENSITY);
			 	cout<<"~~";
			 	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			}
			if(map[a][b]==-1)
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
