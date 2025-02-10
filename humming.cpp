#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate hamming distance between two strings
int calculateHammingDistance(const string& original, const string& transformed) {
    int distance = 0;
    for (size_t i = 0; i < original.size(); ++i) {
        if (original[i] != transformed[i]) {
            ++distance;
        }
    }
    return distance;
}

// Function to check if the string is a valid binary string
bool isValidBinaryString(const string& s) {
    for (char c : s) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

// Function to calculate minimum cost and hamming distance
int getMinimumCostHammingDistance(const string& original, int A, int B) {
    int count0 = count(original.begin(), original.end(), '0');
    int count1 = original.size() - count0;

    // Rearrange to achieve minimal cost: either "000...111" or "111...000"
    string transformed1 = string(count1, '1') + string(count0, '0');
    string transformed2 = string(count0, '0') + string(count1, '1');

    // Calculate the cost of both transformations
    int cost1 = (count1 > 0 && count0 > 0) ? (count1 - 1) * A : 0;
    int cost2 = (count1 > 0 && count0 > 0) ? (count0 - 1) * B : 0;

    // Choose the transformation with the minimum cost
    string minTransformed = (cost1 < cost2) ? transformed1 : transformed2;
    
    // Calculate the Hamming distance for the selected transformation
    return calculateHammingDistance(original, minTransformed);
}

int main() {
    int T;
    cin >> T;
    vector<int> results;

    for (int t = 0; t < T; ++t) {
        string binaryString;
        int A, B;
        cin >> binaryString >> A >> B;

        if (!isValidBinaryString(binaryString)) {
            results.push_back(-1); // Use -1 to indicate INVALID
            continue;
        }

        int hammingDistance = getMinimumCostHammingDistance(binaryString, A, B);
        results.push_back(hammingDistance);
    }

    for (int result : results) {
        if (result == -1) {
            cout << "INVALID" << endl;
        } else {
            cout << result << endl;
        }
    }

    return 0;
}
