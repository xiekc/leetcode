#include <iostream>
#include <vector>
using namespace std;

// CSP
// in fact, we dont need to count sum every time
class Solution {
    vector<vector<int>> ans;
    int target;
    vector<int> candidates;

    void backtrack(vector<int> vec, int index, int remain) {
        if (remain == 0) {
            ans.push_back(vec);
            return;
        }
        if (remain < 0)
            return;
        for (int i = index; i < candidates.size(); i++) {
            vec.push_back(candidates[i]);
            backtrack(vec, i, remain - candidates[i]);
            vec.pop_back();
        }
    }

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        this->target = target;
        this->candidates = candidates;
        vector<int> vec;
        backtrack(vec, 0, target);
        return this->ans;
    }
};
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
int main(int argc, char const *argv[]) {
    vector<int> candidates1 = {2, 3, 5};
    vector<int> candidates2 = {2, 3, 6, 7};
    Solution sol;
    auto ans = sol.combinationSum(candidates2, 8);

    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
