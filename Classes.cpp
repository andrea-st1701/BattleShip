#include "classes.h"
#include "classesAI.h"
#include "rtClasses.h"
#include <windows.h>
using namespace std;
 table::table()
 {
 	
 	/*"azzeramento" della mappa:
	  tutti i valori a parte quelli della prima colonna e della prima riga vengono portati a 3. 
	  In questo modo si distinguono le posizioni consentite dalla legenda.*/
 	for(int i=1; i<9; i++)
 	{
 		for(int l=1; l<9; l++)
 		{
 			map[i][l]=3;
		 }
	 }
	 //azzeramento prima linea e colonna mappa (legenda): queste vengono effettivamente portate a 0.
	 for (int b=0; b<9; b++)
	 {
	 	map[b][0]=map[0][b]=0;
	 }
	 //riempimento vettore alfabeto usando la tabella ASCII
	 for(int a=0; a<8; a++)
	 {
	 	alf[a]=65+a;
	 }
	 /*azzeramento della tabella id. Il valore è 404 e non 0
	 per distinguerlo dall'id 0 che verrà usato in questa tabella.*/
	for(int f=0; f<9; f++)
	{
		for(int g=0; g<9; g++)
		{
			id[f][g]=404;
		
		}
	
	}
 }
int userTable::print()
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
				 if(map[a][b]==3)
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
 
 
 ship::ship(int l)
 {
 //	l=l>0? l:3;
	length=l;
 	for(int i=0; i<5; i++)
 	{
 		position[i].x=0;
		position[i].y=0;
	 }
 
 }
 void userShip::insertShip(int i, userTable &t)
 {
 		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 		int a=1; 
		point c={0};
 		bool  b=true;
 		char z=0;
 		do{
 			cout<<"inserisci le cordinate della prua della nave "<<i<<" \n y(lettera): ";
 			cin>>z;
 			c.y=(int)z-96;
 			if(c.y>8||c.y<=0)
 			{
 				SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
 				cout<<"errore, riprova...\n";
 				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
 				
			 }
		 }while(c.y>8||c.y<=0);
 		do{
 			do{
 			cout<<"x: ";
 			cin>>c.x;
			 }while(typeid(c.x).name()!=int);
 			c.x=(int)c.x;
 			cout<<c.x;
 			system("pause");
 			if(c.x>8||c.x<=0)
 			{
 				SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
 				cout<<"errore, riprova...\n";
 				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			 }
		 }while(c.x>8||c.x<=0);
 	
 		b=controlValue(c, t, b);
 		if(b==false)
 		{
 			SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
 			cout<<"errore, riprova...\n";
 			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
 			insertShip(i, t);
		 }
		 else
		 {
		 	
		cout<<"specifica il verso della nave:\n 1=verticale\n2=orizzontale\n ";
		cin>>a;
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
 					SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
 					cout<<"errore, riprova...\n";
 					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
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
 					SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
 					cout<<"errore, riprova...\n";
 					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
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
 			default:
 				SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
 				cout<<"valore non consentito, riprova...\n";
 				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
 				insertShip(i, t);	
 				break;
		 }
		
 				
 		for(int z=0; z<length; z++)
 		{
 			t.setMap(1, position[z]);
 			t.setId(i, position[z]);
 						
		 }
	 }
 }
 
 bool ship::controlValue(point c, table &t, bool &b)
 {
 	int map=t.getMap(c);
 	if(map!=3)
 	{
 		b=false;
	 }	
	 return b;
 }
 void ship::stateControl(table &t)
 {
 	bool affondato=true;
 	int map=0;
 	for(int i=0; i<length; i++)
 	{
 		cout<<length<<"\n";
 		cout<<position[i].x<<"\t"<<position[i].y<<"\n";
 		map=t.getMap(position[i]);
 		if(map==1)
 		{
 			affondato=false;
 			//break;
		 }
	 }
	 if(affondato==true)
	 {
	 	cout<<"e AFFONDATA!!! ";
	 }
 }


//cannon utente
cannon::cannon()
{
}

cannon::~cannon()
{
}
 void userCannon::interfaccia(tableAI &t, ShipAI *s)
{
	char z;
	point f;
	do
	{
		cout<<"scrivi le coordinate da colpire\n y(lettera): ";
		cin>>z;
		f.y=(int)z-96;
	}while(f.y<1||f.y>8);
	do
	{
		cout<<"x: ";
		cin>>f.x;
	}while(f.x<1||f.x>8);
	fire(f, t, s);
	
}
void cannon::fire(point f, table &t, ship *s)
{
	int a=t.getMap(f);
	int b=404;
	if(a==1)
	{
		b=t.getId(f);
		t.setMap(2, f);
		cout<<"nave "<<b<<" colpita! ";
		s[b].stateControl(t);
	}
	else if(a==3)
	{
		cout<<"ACQUA\n";
		t.setMap(4, f);
	}
}

