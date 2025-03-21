#include <iostream>
#include <vector>
using namespace std;

void printsubseq(vector<int>& arr, int index, int n, vector<int>& ans) {
    if (index >= n) {
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl; // Print each subsequence on a new line
        return;
    }

    // Include the current element
    ans.push_back(arr[index]);
    printsubseq(arr, index + 1, n, ans);
    ans.pop_back();

    // Exclude the current element
    printsubseq(arr, index + 1, n, ans);
}

int main() {
    vector<int> arr = { 1, 2, 3 };
    int n = arr.size();
    vector<int> ans;
    printsubseq(arr, 0, n, ans);
    return 0;
}