#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "classes.h"
#include "rtClasses.h"
#include "classesAI.h"
using namespace std;

int main()
{
	srand(time(0));
	userTable table1;
	tableAI table2;
	userShip*  ships[5]={ new userShip(5), new userShip(4), new userShip(3),  new userShip(3), new userShip(2)};
	ShipAI*  AIships[5]={ new ShipAI(5), new ShipAI(4), new ShipAI(3),  new ShipAI(3), new ShipAI(2)};
	table1.print();

	//inserimento navi utente
	for(int a=0; a<5; a++)
	{
		ships[a]->insertShip(a, table1);
		system("cls");
		table1.print();
	}
	//inserimento navi AI
	for(int a=0; a<5; a++)
	{
		AIships[a]->insertShip(a, table2);
	}
	table2.print();
	userCannon cannon1;
	//cannonAI cannon2;
	while(1)
	{
		bool affondato=false;
		system("cls");
		table1.print();
		table2.print();
		cannon1.interfaccia(table2, *AIships);
		system("pause");
		//cannon2.interfaccia(table1, *ships);
	}
	delete ships;
	delete AIships;
 	system("pause");
	}

