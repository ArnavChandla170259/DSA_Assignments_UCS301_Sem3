#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;

    for (int num : nums) {
        if (s.count(num))
            return true;
        s.insert(num);
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    if (containsDuplicate(nums))
        cout << "true";
    else
        cout << "false";

    cout << "\n";
    return 0;
}
/*Name: Arnav Chandla
Roll No. :1024170259*/
