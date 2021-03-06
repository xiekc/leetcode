#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(!(nums[i]>0&&nums[i]<=n)){
                nums[i]=0;
            }
        }

        for(int i=0;i<n;i++){
            if((nums[i]%(2*n))==0)continue;
            nums[(nums[i]-1)%n]+=2*n;
        }

        for(int i=0;i<n;i++){
            if(nums[i]<=n)return i+1;
        }

        return n+1;
    }
};

int main(){
    Solution s;
    vector<int>v;
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(-1);
    v.push_back(1);
    cout<<s.firstMissingPositive(v)<<endl;
}