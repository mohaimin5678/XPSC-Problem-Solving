#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt=0;
    int l=0,r=0;
    while(r<n){
        if(s[r]=='1'){
            r+=(k+1);
            l=r;
        }
        else if(r-l==k){
            cnt++;
            r++;
            l=r;
        }
        else if(s[r]=='0'){
            r++;
            if(r==n) cnt++;
        }
    }
    cout<<cnt<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        //using two pointers sliding window technique
        mohaimin();
    }
    return 0;
}
