#ifndef RTCLASSES_H_INCLUDED
#define RTCLASSES_H_INCLUDED
#include <iostream>
struct point
{
	int x;
	int y;
};

class table 
{
	protected:
	int id[9][9];
	int map[9][9];
	char alf[8];
	public:
		
		table();
		~table(){};
		int getMap(point a){return map[a.y][a.x];};
		void setMap(int value, point a){map[a.y][a.x]=value;};
		int getId(point a){return id[a.y][a.x];};
		void setId(int value, point a){id[a.y][a.x]=value;};
		//virtual int print(){};
};
class ship
{
	protected:
	int length;
	point position[5];
	public:
		//funzioni utente
		ship(int l);
		~ship(){};
	 	bool controlValue(point c, table &t, bool &b);
		void stateControl(table &t);
};

class cannon
{
	int lastShot[2];
	public:
		cannon( );
		~cannon();
		void fire(point f, table &t, ship *s);
	protected:
};



#endif
