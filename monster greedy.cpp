#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3 + 10;

int vis[maxn][maxn];

int main() {
    string s;cin>>s;
    int len = s.size();
    int res = 0;
    for(int i = 0;i < len;i++) {
        int cur = 0;
        for(int j = i;j < len;j++) {
            if(s[j] == '(' || s[j] == '?')
                cur++;
            else cur--;
            if(cur >= 0) vis[i][j]++;
            else break;
        }
    }

    for(int i = len - 1;i >= 0;i--) {
        int cur = 0;
        for(int j = i;j >= 0;j--) {
            if(s[j] == ')' || s[j] == '?') {
                cur++;
            } else {
                cur--;
            }
            if(cur >= 0) vis[j][i]++;
            else break;
        }
    }
    for(int i = 0;i < len;i++) {
        for(int j = 0;j < len;j++) {
            if((i + j) % 2 && vis[i][j] == 2) {
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
