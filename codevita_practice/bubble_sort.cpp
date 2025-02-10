#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countSwaps(const vector<int>& arr, const vector<int>& target) {
    int n = arr.size();
    vector<bool> visited(n, false);
    int swapCount = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || arr[i] == target[i]) continue;

        int cycleSize = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = find(target.begin(), target.end(), arr[j]) - target.begin();
            cycleSize++;
        }

        if (cycleSize > 1) swapCount += (cycleSize - 1);
    }

    return swapCount;
}

int minSwapsToBeautiful(vector<int>& arr) {
    int n = arr.size();
    vector<int> ascArr = arr;
    sort(ascArr.begin(), ascArr.end());

    vector<int> descArr = arr;
    sort(descArr.begin(), descArr.end(), greater<int>());

    int ascSwaps = countSwaps(arr, ascArr);
    int descSwaps = countSwaps(arr, descArr);

    return min(ascSwaps, descSwaps);
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << minSwapsToBeautiful(arr) << endl;

    return 0;
}
