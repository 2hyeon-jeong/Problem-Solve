// boj 10819
#include <bits/stdc++.h>
using namespace std;

int n; 
vector<int> nums;
vector<int> temp;
int used[10];
int ans;

void dfs(int dep) {
    if (dep == n) {
        int t = 0;
        for (int i = 0; i < n-1; ++i) {
            t += abs(temp[i] - temp[i+1]);
        }
        ans = max(ans, t);
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        used[i] = 1;
        temp.push_back(nums[i]);
        dfs(dep+1);
        temp.pop_back();
        used[i] = 0;
    }
}

void solve() {
    cin >> n;
    nums.resize(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    dfs(0);
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}