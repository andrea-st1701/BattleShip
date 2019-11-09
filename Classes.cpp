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
 	l>0? l:3;
 	length=l;
 	for(int i=0; i<5; i++)
 	{
 		position[i][0]=position[i][1]=0;
	 }
 
 }
 void userShip::insertShip(int i, userTable &t)
 {
 		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 		int a=1, x1=0, y1=0;
 		bool  b=true;
 		char z;
 		do{
 			cout<<"inserisci le cordinate della prua della nave "<<i<<" \n y(lettera): ";
 			cin>>z;
 			y1=(int)z-96;
 			if(y1>8||y1<=0)
 			{
 				SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
 				cout<<"errore, riprova...\n";
 				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			 }
		 }while(y1>8||y1<=0);
 		do{
 			cout<<"x: ";
 			cin>>x1;
 			if(x1>8||x1<=0)
 			{
 				SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
 				cout<<"errore, riprova...\n";
 				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
			 }
		 }while(x1>8||x1<=0);
 	
 		b=controlValue(x1, y1, t, b);
 		if(b==false)
 		{
 			SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
 			cout<<"errore, riprova...\n";
 			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
 			insertShip(i, t);
		 }
		 else
		 {
		 	position[0][0]=x1;
		 	position[0][1]=y1;
		cout<<"specifica il verso della nave:\n 1=verticale\n2=orizzontale\n ";
		cin>>a;
 		switch (a)
 		{
 			case 1:
 			for(int f=1; f<length; f++)
 			{
 				b=controlValue(x1, y1+f, t, b);
 		
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
 					SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
 					cout<<"errore, riprova...\n";
 					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
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
 			default:
 				SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_INTENSITY);
 				cout<<"valore non consentito, riprova...\n";
 				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
 				insertShip(i, t);	
 				break;
		 }
		
 				
 		for(int z=0; z<length; z++)
 		{
 			t.setMap(1, position[z][0], position[z][1]);
 			t.setId(i, position[z][0], position[z][1]);
 						
		 }
	 }
 }
 
 bool ship::controlValue(int x, int y, table &t, bool &b)
 {
 	int map=t.getMap(x, y);
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
 		map=t.getMap(position[i][0],position[i][1]);
 		if(map==1)
 		{
 			affondato=false;
 			break;
		 }
	 }
	 if(affondato==true)
	 {
	 	cout<<"e AFFONDATA!!! ";
	 	delete this;
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
	int xf=0, yf=0;
	do
	{
		cout<<"scrivi le coordinate da colpire\n y(lettera): ";
		cin>>z;
		yf=(int)z-96;
	}while(yf<0||yf>8);
	do
	{
		cout<<"x: ";
		cin>>xf;
	}while(xf<0||xf>8);
	fire(xf, yf, t, s);
	
}
void cannon::fire(int x, int y, table &t, ship *s)
{
	int a=t.getMap(x, y);
	int b=404;
	if(a==1)
	{
		b=t.getId(x, y);
		t.setMap(2, x, y);
		cout<<"nave "<<b<<" colpita! ";
	}
	if(a==3)
	{
		cout<<"ACQUA\n";
		t.setMap(4, x, y);
	}
	if(b!=404)
	{
		s[b].stateControl(t);
	}
}

