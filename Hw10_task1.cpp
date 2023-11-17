
#include <iostream>

template < typename ... Types >
auto memory_count0(Types ... args)
{
	return (sizeof(args) + ...);
}


template <typename T1>
auto memory_count1(T1 arg)
{
	return sizeof(arg);
}


template <typename T1, typename ... Types >
auto memory_count1(T1 arg, Types ... args)
{
	return sizeof(arg) + memory_count1(args...);
}

int main()
{
	int list[2]{ 1,2 };
	std::cout << sizeof(list[0]) << std::endl;
	std::cout << sizeof(list) << std::endl;
	std::cout << memory_count0(1, 2) << std::endl;
	std::cout << memory_count1(0, 1, 2) << std::endl;
	return 0;
}