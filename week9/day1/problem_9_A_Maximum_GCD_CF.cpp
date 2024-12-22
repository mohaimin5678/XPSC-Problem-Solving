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
        if(n==1){
            cout<<-1<<endl;
        }
        else if(n==2) cout<<__gcd(1,2)<<endl; //always be 1
        else{
            cout<<(n/2)<<endl;  //thats the highest we can get
        }
    }
    return 0;
}
/*
suppose n=10
if we take 5 & 10 then their gcd is 5 which is the highest.
again if n=13 
if we take 6 & 12 then their gcd is 6 which is the highest
*/