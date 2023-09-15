#include <iostream>
#include <vector>
#include <algorithm>

void generatePermutations(std::vector<int>& nums, int N) {
    
    do {
        
        for (int i = 0; i <= N; i++) {
            std::cout << nums[i] << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(nums.begin(), nums.end()));
}

int main() {
    int N;
    std::cout << "Enter an integer N: ";
    std::cin >> N;

    
    std::vector<int> nums(N + 1);
    for (int i = 0; i <= N; i++) {
        nums[i] = i;
    }

    
    generatePermutations(nums, N);

    return 0;
}
