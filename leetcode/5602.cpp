#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        int len = nums.size();
        vector<int> prefixSum(nums.size()+1, 0);
        for (int i = 0; i < len; i++){
            total += nums[i];
            prefixSum[i+1] = total;
        }
        int target = total - x;
        if (target < 0) return -1;
        if (target == 0) return len;
        int max_len = 0;
        // 0-n 遍历所有可能的子串，可以考虑从长到短
        int left = 0; // 0 - len
        int right = 1; // 1 - len+1
        
        while(1){
            cout << left << " " << right << endl;
            if (right > len+1) break;
            if (left > len+1) break;
            
            int cur_sum = prefixSum[right]-prefixSum[left];
            if (cur_sum < target && right >= len+1) break;
            
            if (cur_sum < target){
                right ++;
            } else if (cur_sum > target){
                left ++;
            } else{
                max_len = max(max_len, (right-left));
                right++;
                left++;
            }
            
        }

        if (max_len == 0){
            return -1;
        }
        return len - max_len;
    }
};


int main(){
    // vector<int> nums{1,1,4,2,3};
    vector<int> nums{3,2,20,1,1,3};
    cout << Solution().minOperations(nums, 10) << endl;
}