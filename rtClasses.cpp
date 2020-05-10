#include "rtClasses.h"
matrix::matrix(int l)
{
	s=l;
	//allocazione dinamica matrice
	m=(int**)malloc(l*sizeof(int*));
	for(int i=0; i<l; i++)
	{
		m[i]=(int*)malloc(l*sizeof(int));
	}
	//
	for(int i=0; i<l; i++)
	{
		for(int j=0; j<l; j++)
		{
				m[i][j]=0;
		}
	}
	corner.x=corner.y=1;
}
matrix::~matrix()
{
	for(int i=0; i<s; i++)
	{
		free(m[i]);
	}
	free(m);
	//cout<<"matrix died\n";//enable for debug
}
void matrix::rotate(int f)
{
	int m2[s][s];
	switch (f)
	{
		case 0:
			for(int i=0; i<s; i++)
			{
				for(int j=0; j<s; j++)
				{
					m2[i][j]=m[j][i];
				}
			}
			for(int i=0; i<s; i++)
			{
				for(int j=0; j<s; j++)
				{
					m[i][j]=m2[i][j];
				}
			}
		case 1:
			for(int i=0; i<s; i++)
			{
				for(int j=0; j<s; j++)
				{
					//!!!
				}
			}
	}
}
table::table()
{
	map2=new matrix(9);
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			if(i==0||j==0)
			{
				map[i][j]=0;
			}
			else
			{	
				map[i][j]=404; //i=riga, j=colonna
			}
		}
	}
}
table::~table()
{
	//debug code
}
ship::ship(int l, int ID)
{
	if (!((l>0&&l<6)&&(ID>=0&&ID<6)))
	{
		cout<<"errore, controlla costruttori ship nel main";
	}
	else
	{
		length=l;
		id=ID;
		pos=(pt*)malloc(l*sizeof(pt));
		if(!pos)
		{
			cout<<"memory allocation failed ercod01";
		}
		for(int i=0; i<l; i++)
		{
			pos[i].x=0;
			pos[i].y=0;
		}
		a=new matrix(l);
		pt x;
			for(int i=0; i<l; i++)
			{
				for(int j=0; j<l; j++)
				{
					if(j==0)
					{
						x.x=j;
						x.y=i;
						a->setVal(x,1);
					}
		}
	}
	}
}
ship::~ship()
{
	free(pos);
	//cout<<"ship died\n";//enable for debug
}
