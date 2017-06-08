#include "Hastable.h"
#include <iostream>

void main()
{
	Table<int,double> t(50);
	t.Add(2,5);
	t.Add(3,8);
	t.Add(4,9);
	t.Add(5,10);
	std::cout<<t[9].GetData()<<std::endl;
	std::cout<<t.min()<<std::endl;
	std::cin.get();

}