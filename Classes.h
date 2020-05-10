#ifndef CLASSES_H
#define CLASSES_H
#include "rtClasses.h"
#include <iostream>
using namespace std;
class tableUser : public table
{
	public:
		tableUser():table(){};
		void print();
	protected:
};
class shipUser :public ship
{
	public:
		shipUser(int l1, int ID1): ship(l1,ID1){};
		
}; 
class tableAI : public table
{
	public:
		void print();
	protected:
};


#endif
