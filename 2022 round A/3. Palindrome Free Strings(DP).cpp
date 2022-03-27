#include<bits/stdc++.h>
using namespace std;
#define endl "\n"

const int mxN = 50000;

void solve() {
    int n; string s;
    cin >> n >> s;
    bool dp[mxN+1][32];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    
    for(int idx = 0; idx < n; idx++) {
        for(int k = 0; k < 32; k++) {
            if(!dp[idx][k]) continue;
            for(int c : {0, 1}) {
                if(s[idx] - '0' == (c^1)) continue; //By toggle, if both same -> pass, if both different -> calculate
                int nk = (k<<1)|c;
                if((idx < 4 || (nk>>0&1) != (nk>>4&1) || (nk>>1&1) != (nk>>3&1))&&(idx < 5 || 
                (nk>>0&1) != (nk>>5&1) || (nk>>1&1) != (nk>>4&1)||(nk>>2&1) != (nk>>3&1))) {
                    dp[idx+1][nk&31] = 1;
                }
            }    
        }
    }
    
    int flag = 0;
    for(int i = 0; i < 32; i++) {
        flag |= dp[n][i];
    }
    
    if(flag) cout << "POSSIBLE";
    else cout << "IMPOSSIBLE";    
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}




