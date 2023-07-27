#include<iostream>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0]; // Initialize maxSum to the first element
    int currentSum = nums[0]; // Initialize currentSum to the first element
    
    for (int i = 1; i < nums.size(); i++) {
        // Choose between the current element or extending the subarray
        currentSum = std::max(nums[i], currentSum + nums[i]);
        
        // Update the maxSum if needed
        maxSum = std::max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int result = maxSubArray(nums);
    
    cout << "Maximum Subarray Sum: " << result << endl;
    
    return 0;
}
