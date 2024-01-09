#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int> &nums, vector<vector<int>> &ans)
{

    while (nums.size() != 0)
    {
        vector<int> v;
        unordered_map<int, int> mp;
        for (auto it : nums)
        {
            mp[it]++;
        }
        for (auto it : mp)
        {
            v.push_back(it.first);
            int eletodel = it.first;
            auto itt = std::find(nums.begin(), nums.end(), eletodel);
            if (itt != nums.end()) {
        // Erase the element from the vector
        nums.erase(itt);
          }
        }

        ans.push_back(v);
//         int i = 0, j = 0;
//         sort(v.begin(),v.end());
//         sort(nums.begin(),nums.end());
//         while (i < v.size() && j < nums.size()) {
//     if (v[i] == nums[j]) {
//         // Matching element found, erase it from nums
//         nums.erase(std::remove(nums.begin(), nums.end(), v[i]), nums.end());
//         i++;
//         j++;
//     } else {
//         // No match found, move to the next element in nums
//         j++;
//     }
// }

        mp.clear();
        v.clear();
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 3, 4, 1, 2, 3, 1};
    // vector<int> nums = {1,2,3,4};

    vector<vector<int>> ans;
    //sort(nums.begin(),nums.end());
    solve(nums,ans);
    for(int i=0 ; i<ans.size() ; i++){
        for(int j=0 ; j<ans[i].size() ; j++){
            cout << ans[i][j]<<" ";
        }
        cout << endl;
    }
}