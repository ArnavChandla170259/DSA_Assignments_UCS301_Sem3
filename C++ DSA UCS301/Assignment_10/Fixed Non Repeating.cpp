#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstNonRepeating(vector<int>& nums) {
    unordered_map<int, int> freqMap;

    // Count all frequencies
    for (int num : nums)
        freqMap[num]++;

    // Check array order to find first with count 1
    for (int num : nums) {
        if (freqMap[num] == 1)
            return num;
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 1, 2, 0, 4};

    int result = firstNonRepeating(nums);

    if (result != -1)
        cout << result;
    else
        cout << "No non-repeating element found";

    cout << "\n";
    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
