#include <iostream>

int main()
{
	int a;
	while (std::cin >> a)
		std::cout << a << " converts to "<< int(__builtin_bswap32(a)) << '\n';
}
