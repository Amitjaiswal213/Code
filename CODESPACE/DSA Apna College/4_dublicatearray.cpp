#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> numSet;
    
    for (int num : nums) {
        if (numSet.find(num) != numSet.end()) {
            return true; // Duplicate found
        }
        numSet.insert(num);
    }
    
    return false; // No duplicate found
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    
    bool result = containsDuplicate(nums);
    
    if (result) {
        cout << "The array contains duplicate elements." << endl;
    } else {
        cout << "The array does not contain any duplicates." << endl;
    }
    
    return 0;
}
