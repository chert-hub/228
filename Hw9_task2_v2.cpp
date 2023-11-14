#include <iostream>
#include <vector>
#include <functional>
template<typename T, std::size_t N>
class Array
{
public:
	Array()
	{
		input_array();
	}

	~Array()
	{
		std::cout << "Destructor was called \n";
	}

	bool empty()
	{
		return N == 0;
	}

	size_t size() {
		return N;
	}

	void swap(int a, int b) {
		if ((a < 0 || a >= N) || (b < 0 || b >= N)) {
			throw std::string("Exception int swap");
		}
		data[a] ^= data[b];
		data[b] ^= data[a];
		data[a] ^= data[b];
	}

	T back() {
		if (N == 0) {
			throw std::string("Exception in back");
		}
		return data[N - 1];
	}
	void out() {
		if (N == 0) {
			throw std::string("Exception in size");
		}
		for (int i = 0; i < N; i++) {
			std::cout << data[i] << " ";
		}
	}

	T front() {
		if (N == 0) {
			throw std::string("Exception in back");
		}
		return  data[0];
	}

private:
	T data[N];
	void input_array() {
		std::cout << "Enter the each of " << N << " elements of array \n";
		for (int i = 0; i < N; i++) {
			std::cin >> data[i];
		}
	}
};

int main()
{
	try {
		Array<int, 5> M;
		M.swap(2, 3);
		M.out();
	}
	catch (std::string e) {
		std::cout << e;
	}
	return 0;
}
