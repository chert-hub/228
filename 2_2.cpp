#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = { 64, 25, 12, 22, 11 };

    std::cout << "source array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }

    std::cout << "\nSorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }

    return 0;
}