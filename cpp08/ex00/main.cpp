#include "Easyfind.tpp"
#include <iostream>

int main (void)
{
	int	tab[10] = {5, 3, 7, 1, 9, 2, 0, 6, 4, 8};
	
	int *pos = Easyfind(tab, 9);
	std::cout << *pos << std::endl;
}