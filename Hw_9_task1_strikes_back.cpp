#include <functional>
#include <iostream>

using uint = unsigned int;

template <typename T>
uint partition(T* data, uint l, uint r, std::function<bool(T, T)> comparator);

template <typename T>
void quickSort(T* data, uint l, uint r, std::function<bool(T, T)> comparator = std::less<T>{})
{
	if (l < r)
	{
		uint q = partition(data, l, r, comparator);
		quickSort(data, l, q, comparator);
		quickSort(data, q + 1, r, comparator);
	}
}

template <typename T>
void quickSort(T data, uint l, uint r, std::function<bool(T, T)> comparator = std::less<T>{})
{
	if (l < r)
	{
		uint q = partition(data, l, r, comparator);
		quickSort(data, l, q, comparator);
		quickSort(data, q + 1, r, comparator);
	}
}

template <typename T>
uint partition(T* data, uint l, uint r, std::function<bool(T, T)> comparator)
{
	T mid = data[(l + r) / 2];
	int i = l;
	int j = r;
	while (i <= j)
	{
		while (comparator(data[i], mid))
			i++;
		while (comparator(mid, data[j]))
			j--;
		if (i >= j)
			break;
		std::swap(data[i++], data[j--]);
	}
	return j;
}


int main()
{
	auto data = new int[5] { 3, -4, 1, 5, 2 };
	int data_2[5] = { 3, -4, 5, 2, 1 };
	quickSort(data_2, 0, 4, std::function<bool(int, int)>{std::greater<int>{}});
	quickSort(data, 0, 4, std::function<bool(int, int)>{std::greater<int>{}});
	for (auto i = 0u; i < 5; i++)
	{
		std::cout << data[i] << '\t' << data_2[i] << '\n';
	}

	return 0;
}