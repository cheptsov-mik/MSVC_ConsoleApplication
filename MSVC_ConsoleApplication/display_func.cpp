#include <iostream>

void display()
{
	static int i = 0;
	i++;
	std::cout << "i=" << i << std::endl;
}
