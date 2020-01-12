#ifndef CLASSESAI_H
#define CLASSESAI_H
#include "rtClasses.h"




class tableAI : public table
{
	public:
		int print();
	protected:
};
class ShipAI : public ship
{
	protected:
	public:
		ShipAI(int l): ship(l){};
		//funzioni utente
		void insertShip(int i, tableAI &t);
};

class userCannon : public cannon
{
	public:
		void interfaccia(tableAI &t, ShipAI* s);
	protected:
};

#endif
