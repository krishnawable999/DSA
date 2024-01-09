#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {1, 3, 4, 1, 2, 3, 1};

    int elementToDelete = 1; // Replace with the element you want to delete

    // Find the iterator pointing to the first occurrence of the element
    auto it = std::find(nums.begin(), nums.end(), elementToDelete);

    // Check if the element is found before erasing it
    if (it != nums.end()) {
        // Erase the element from the vector
        nums.erase(it);
    }

    // Print the updated vector
    for (int num : nums) {
        std::cout << num << " ";
    }

    return 0;
}
