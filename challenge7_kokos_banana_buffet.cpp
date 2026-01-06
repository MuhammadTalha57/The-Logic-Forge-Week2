#include <bits/stdc++.h>

using namespace std;

/*
Asymptotic Analysis

Time Complexity = O(N Log max(piles))
Space Complexity = O(1)

*/

bool check(vector<int>& piles, int s, int k) {
    long long time = 0;
    for(int i = 0; i < piles.size(); i++) {
        time += (long long)( (piles[i] + s - 1) / s);
    }

    return time <= k;
}

int calculate_minimum_speed(vector<int>& piles, int k) {
    int lo = 1, hi = *max_element(piles.begin(), piles.end()), m;
    int ans = hi;
    while(lo <= hi) {
        m = (lo + hi) / 2;
        if(check(piles, m, k)) {
            ans = m;
            hi = m -1;
        } else lo = m + 1;
    }

    return ans;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> piles = {5, 10, 15, 20};
    int k = 7;

    cout << calculate_minimum_speed(piles, k);

    return 0;
}