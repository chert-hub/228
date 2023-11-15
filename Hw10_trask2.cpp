#include <iostream>


template <typename F, typename ... Types >
auto call_func(F func, Types ... args)
{
	return func(args...);
}


template < typename ... Types >
auto sum(Types ... args)
{
	return (args + ...);
}

void f(char value)
{
	std::cout << "char: " << value << std::endl;
}

int main()
{
	call_func(f, 'a');
	std::cout << call_func(sum<double, double>, 1.1, 2.2);
	return 0;
}
