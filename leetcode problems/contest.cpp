#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> calcIntersectionValues(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_map<int, int> count1, count2;

    for (int num : nums1) {
        count1[num]++;
    }

    for (int num : nums2) {
        count2[num]++;
    }

    int result1 = 0, result2 = 0;

    for (const auto& entry : count1) {
        if (count2.count(entry.first) > 0) {
            result1 += entry.second;
        }
    }

    for (const auto& entry : count2) {
        if (count1.count(entry.first) > 0) {
            result2 += entry.second;
        }
    }

    return {result1, result2};
}

int main() {
    // Example usage
    std::vector<int> nums1 = {3, 4, 2, 3};
    std::vector<int> nums2 = {1, 5};
    
    std::vector<int> answer = calcIntersectionValues(nums1, nums2);

    // Output the result
    std::cout << "Result: [" << answer[0] << ", " << answer[1] << "]" << std::endl;

    return 0;
}
