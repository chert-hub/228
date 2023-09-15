
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr = { 2, 4, 6, 8, 8, 10 };

    int target = 6;

    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target) {
            left = mid + 1;
        }
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        else {
            // Нашли искомое число, ищем первое вхождение
            result = mid;
            right = mid - 1;
        }
    }

    if (result != -1) {
        std::cout << "The first occurrence of a number " << target << " in the array on the index " << result << std::endl;
    }
    else {
        std::cout << "Number " << target << " not found in the array" << std::endl;
    }

    return 0;
}