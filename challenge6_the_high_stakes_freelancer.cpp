#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(NM)
Space Complexity = O(NM)

Efficient for N, M <= O(10^3)

*/

int maximize_freelance_profit(vector<int>& deadlines, vector<int>& profits) {
    sort(deadlines.begin(), deadlines.end());
    vector<int> compatibleJob(deadlines.size());

    compatibleJob[0] = -1;
    for(int i = 1; i < deadlines.size(); i++) {
        compatibleJob[i] = -1;
        int lo = 0, hi = i - 1, m;
        while(lo <= hi) {
            m = (lo + hi) / 2;
            if(deadlines[m] < deadlines[i]) {
                compatibleJob[i] = m;
                lo = m + 1;
            } else {
                hi = m - 1;
            }
        }        
        // if(deadlines[lo] < deadlines[i]) compatibleJob[i] = lo;

    }

    vector<int> dp(deadlines.size(), 0);

    dp[0] = profits[0];

    for(int i = 1; i < deadlines.size(); i++) {
        dp[i] = profits[i];
        if(compatibleJob[i] != -1) dp[i] += dp[compatibleJob[i]];
    }

    return dp.back();

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> deadlines = {4, 1, 1, 1};
    vector<int> profits = {20, 10, 40, 30};

    cout << maximize_freelance_profit(deadlines, profits);

    return 0;
}