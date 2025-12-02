#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void findCommon(vector<int>& A, vector<int>& B) {
    unordered_set<int> setA(A.begin(), A.end());

    cout << "Common elements: ";

    for (int num : B) {
        if (setA.count(num)) {
            cout << num << " ";
            // Remove to avoid printing duplicates if B has multiples
            setA.erase(num);
        }
    }
    cout << "\n";
}

int main() {
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {3, 4, 5, 6};

    findCommon(A, B);

    return 0;
}

/*Name: Arnav Chandla
Roll No. :1024170259*/
