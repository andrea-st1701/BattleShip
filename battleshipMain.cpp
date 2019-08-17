#include <iostream>
#include "classes.h"

using namespace std;

int main()
{
	table table1, table2;
	ship ship1(5), ship2(4), ship3(3), ship4(3), ship5(2);
	ship AIship1(5), AIship2(4), AIship3(3), AIship4(3), AIship5(2);
	table1.print();
	table2.print();
	ship1.insertShip(1, table1);
	system("cls");
	table1.print();
	ship2.insertShip(2, table1);
	system("cls");
	table1.print();
	ship3.insertShip(3, table1);
	system("cls");
	table1.print();
	ship4.insertShip(4, table1);
	system("cls");
	table1.print();
	ship5.insertShip(5, table1);
	system("cls");
	table1.print();
}
