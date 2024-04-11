#include "Easyfind.tpp"
#include <iostream>
#include <vector>

int main (void)
{
    try
    {
    	std::vector<int> tab;
        srand(time(NULL));
        for (int i = 0; i < 1000; i++)
        {
            const int value = rand() % 100;
            tab.push_back(value);
        }	
    	std::cout << *Easyfind(tab, 9) << std::endl;
    } catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}