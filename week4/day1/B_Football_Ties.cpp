#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int adraw=a-(3*(a/3));
        int bdraw=b-(3*(b/3));
        cout<<min(adraw,bdraw)<<endl;
    }
    return 0;
}