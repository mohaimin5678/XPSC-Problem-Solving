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
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            v[i]=(a[i]-b[i]);
        }
        int cnt=0;
        sort(v.begin(),v.end(),greater<int>());
        int i=0,j=n-1;
        while(i<j){
            if(v[i]+v[j]>0) i++;
            else if(v[i]+v[j]<=0){
                cnt++;
                i++;
                j--;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
/*
6
8 3 9  2  4  5
5 3 1  4  5  10
----------------- (-)
3 0 8 -2 -1 -5

sorting the sub array on descending order: 8 3 0 -1 -2 -5
from there using two pointers & if their sum <=0 then cnt++
*/