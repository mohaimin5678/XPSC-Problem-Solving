#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<string,int> count;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(count[s]==0) cout<<"OK"<<endl;
        else cout<<s<<count[s]<<endl;
        count[s]++;
    }
    
    return 0;
}