#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <iostream>

class table 
{
	
	char alf[8];
	public:
		char map[9][9];
		table();
		int print();
};
class ship
{
	int length;
	int position[5][2];
	public:
		ship(int l);
		void insertShip(int i, table &t);
		void controlValue(int x, int y, int b, int i, table &t);
		int stateControl();
};

#endif 
