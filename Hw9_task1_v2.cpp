#include <iostream>
#include <vector>
#include <functional> 
//std::function<bool(T, T)> f
template<typename T, std::size_t N, typename C> 
void quicksort(T(&v)[N], int low, int high, C function) {
	int p;
	std::function<int(T(&v)[N], int, int, std::function<bool(T, T)>)> fun = [](T(&v)[N], int low, int high, C function)->int //функции fun приравнивает лямбда функция разбиения Хоара
		{
			auto pivot = v[(low + high) / 2];
			auto i = low;
			auto j = high;
			while (i <= j)
			{
				while (function(v[i], pivot))
				{
					i++;
				}

				while (function(pivot, v[j]))
				{
					j--;
				}

				if (i >= j)
				{
					return j;
				}

				std::swap(v[i], v[j]);
				i++;
				j--;
			}
		};
	if (low < high)
	{
		p = fun(v, low, high, function);
		quicksort<T, N>(v, low, p, function);
		quicksort<T, N>(v, p + 1, high, function);
	}
}

template<typename T> 
void quicksort(T* V, std::size_t N, int low, int high, bool t) {
	int p; 
	std::function<bool(T, T)> comparator = [t](T a, T b)->bool {return t ? a<b : a>b; };
	std::function<int(T*, std::size_t, int, int, std::function<bool(T, T)>)> fun = [](T* V, std::size_t N, int low, int high, std::function<bool(T, T)> comparator)->int 
		{
			auto pivot = V[(low + high) / 2];
			auto i = low;
			auto j = high;
			while (i <= j)
			{
				while (comparator(V[i], pivot))
				{
					i++;
				}

				while (comparator(pivot, V[j]))
				{
					j--;
				}

				if (i >= j)
				{
					return j;
				}

				std::swap(V[i], V[j]);
				i++;
				j--;
			}
		};
	if (low < high)
	{
		p = fun(V, N, low, high, comparator);
		quicksort<T>(V, N, low, p, t);
		quicksort<T>(V, N, p + 1, high, t);
	}
}

template<typename T>
std::function<bool(T, T)> greater = [](T a, T b)->bool {return a < b; };

template<typename T>
std::function<bool(T, T)> less = [](T a, T b)->bool {return a > b; };


int main()
{
	//std::cout<<2<<std::endl;
	double* Dynamic = new double[3] { 4.2, 4.1, 7.5}; 
	double Static[3]{ 4.4, 1.1, 7.5 }; 

	std::cout << "Here we have Dynamic(double) and Static(int) arrays \n" << "Both are: { 4, 41, 75, 55, 53,42,555,2321,42,34,11,1} \n" << std::endl;
	int high = 2; 
	int low = 0; 
	bool t, type;
	std::cout << "Enter type of array: 1 - Dynamic(double), 0 - Static(int):" << "";
	std::cin >> type;
	std::cout << "Enter sorting type: 1 - greater, 0 - less:" << "";
	std::cin >> t;
	

	if (type)
	{
		/*quicksort(Dynamic, 3, low, high, comparator); //сортируем
		for (int k = 0; k < 3; k++)//вывод
		{
			std::cout << Dynamic[k] << ' ';
		}*/
	}
	else
	{
		quicksort(Static, low, high, greater<double>);
		for (int k = 0; k < 3; k++)
		{
			std::cout << Static[k] << ' ';
		}
	}
	return 0;
}