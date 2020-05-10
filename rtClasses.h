#ifndef RTCLASSES_H
#define RTCLASSES_H
#include <iostream>
#include <stdlib.h>
using namespace std;

struct pt
{
	int x;
	int y;
};
class matrix
{
	private:
		int** m;
		int s;
		pt corner;
	public:
		matrix(int);
		~matrix();
		void rotate(int);
		int getVal(int x, int y){return m[y][x];}
		int getL(){return s;};
		pt getCorn(){pt c; c.x=corner.x;c.y=corner.y;return c;}
		void setVal(pt a, int v){m[a.y][a.x]=v;}
		//friends
};
class table
{
	protected:
		int map[9][9];
		matrix* map2;
	public:
		table();
		~table();
		//friends
		
		
};
class ship
{
	protected:
		int id;
		int length;
		pt *pos;
		matrix* a;
	public:
		ship(int, int);
		~ship();
		void deleteM(){delete a;};
		//friends
		
		
	
};

#endif
