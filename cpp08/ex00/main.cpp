#include "Easyfind.tpp"
#include <iostream>
#include <vector>

int main (void)
{
	std::vector<int> tab;
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        const int value = rand() % 100;
        tab.push_back(value);
    }	
	std::cout << *Easyfind(tab, 9) << std::endl;
}