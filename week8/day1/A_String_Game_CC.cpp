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
        int unpair=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                unpair++;
            }
        }
        int cnt=min(unpair,n-unpair);
        if(cnt%2==0){
            cout<<"Ramos"<<endl;
        }
        else cout<<"Zlatan"<<endl;
    }
    return 0;
}