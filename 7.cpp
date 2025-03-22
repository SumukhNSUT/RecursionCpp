// print subsequence with sum = k
#include <iostream>
#include<vector>
using namespace std;

int sum_ele(vector<int> v) {
    int s = 0;
    for (auto it : v) {
        s = s + it;
    }
    return s;
}

void print(vector<int>& v, int sum, int idx, vector<int>& ans) {
    if (idx >= v.size()) {
        if (sum_ele(ans) == sum) {
            for (auto it : ans) {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    ans.push_back(v[idx]);
    print(v, sum, idx + 1, ans);

    ans.pop_back();
    print(v, sum, idx + 1, ans);

}

int main() {
    vector<int> v = { 1,2,3,4,5,5,6,7 };
    vector<int> ans;
    int sum = 8;
    int idx = 0;
    print(v, sum, idx, ans);
    return 0;
}