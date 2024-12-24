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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int a=0,b=0,c=0,d=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='A') a++;
            if(s[i]=='B') b++;
            if(s[i]=='C') c++;
            if(s[i]=='D') d++;
        }
        int marks=0;
        marks+=min(n,a);
        marks+=min(n,b);
        marks+=min(n,c);
        marks+=min(n,d);
        cout<<marks<<endl;
    }
    return 0;
}