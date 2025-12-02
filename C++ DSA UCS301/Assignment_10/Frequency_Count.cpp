#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void countFrequency(vector<int>& nums) {
    unordered_map<int, int> freqMap;

    for (int num : nums) {
        freqMap[num]++;
    }

    for (auto i : freqMap) {
        cout << i.first << " -> " << i.second << " times\n";
    }
}

int main() {
    vector<int> nums = {2, 3, 2, 4, 3, 2};

    countFrequency(nums);

    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
