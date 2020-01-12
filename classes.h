#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <iostream>
#include "rtClasses.h"
using namespace std;

class userTable : public table
{
	protected:
	public:
		
		userTable():table(){};
		~userTable(){};
		int print();
};
class userShip: public ship
{
	protected:
	public:
		userShip(int l): ship(l){};
		//funzioni utente
		void insertShip(int i, userTable &t);
};
class cannonAI : public cannon
{
	private:
		int* timesHit=new int;
		int last[2];
	protected:
		bool RLhoriz[2]={1, 1};
	public:
		cannonAI(){*timesHit=-1;};
		~cannonAI(){delete timesHit;};
		int getHit(){return *timesHit;};
		void upHit(bool up){up==true?*timesHit++: *timesHit--;};
		void interfaccia(userTable &t, userShip *s);
		int getLast(int v){return last[v];};
		void setLast(int value, int v){value>0&&value<8 ? last[v]=value : 0;};
};




#endif
