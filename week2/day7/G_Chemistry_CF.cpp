#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,op;
        cin>>n>>op;
        string s;
        cin>>s;
        map<char,int> freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        int odd=0;
        for(auto [x,y]:freq){
            if(y%2==1) odd++;
        }
        
        if(odd-1<=op) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}