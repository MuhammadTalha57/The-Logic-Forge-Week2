#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(N * S)
Space Complexity = O(S)

*/


bool can_balance_scales(vector<int>& arr) {
    int s = accumulate(arr.begin(), arr.end(), 0);
    if(s & 1) return false;

    vector<bool> possibleSums(s / 2 + 1, false);

    possibleSums[s / 2] = true;

    sort(arr.rbegin(), arr.rend());

    for(int i = 0; i < arr.size(); i++) {
        for(int sm = arr[i]; sm <= s / 2; sm++) {
            if(possibleSums[sm]) {
                possibleSums[sm - arr[i]] = true;
            }
        }
    }

    return possibleSums[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> arr = {1, 3, 5};
    cout << can_balance_scales(arr);

    return 0;
}