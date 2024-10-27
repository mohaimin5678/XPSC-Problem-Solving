#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    if(s.size()==4){
        cout<<s<<'\n';
    }
    else{
        int sz=s.size();
        int rem=4-sz;
        while(rem--){
            s="0"+s;
        }
        cout<<s<<'\n';
    }
    return 0;
}