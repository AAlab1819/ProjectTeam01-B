#include<bits/stdc++.h>
using namespace std;

const char open='(',close=')';
string str;
int ans,e;
int DP[5005][5005];

bool solve(int pos,int nopen){
    if (pos==e)
        return nopen==0;
    if (DP[pos][nopen]!=-1)
        return DP[pos][nopen];
    if (str[pos]==open)
        return DP[pos][nopen]=solve(pos+1, nopen+1);
    if (str[pos]==close)
        return DP[pos][nopen]=nopen?solve(pos+1, nopen-1):false;
    return DP[pos][nopen]=max(nopen?solve(pos+1, nopen-1):false,solve(pos+1, nopen+1));
}
int main(){
    cin>>str;
    for (int j=(int)str.size()-1; j>=0; j--) {
        memset(DP, -1, sizeof(DP));
        e=j+1;
        for (int i=0; i<j; i++) ans+=solve(i, 0);
    }
    cout<<ans<<endl;
    return 0;
}
