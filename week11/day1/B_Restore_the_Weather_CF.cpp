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
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> a(n);
        vector<int> b(n),v(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i;
        }
        for(int i=0;i<n;i++) cin>>b[i];
        sort(b.begin(),b.end());
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            // cout<<a[i].first<<" "<<a[i].second<<" -- "<<b[i]<<endl;
            v[a[i].second]=b[i];
        }
        for(int x:v) cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
/*
lets ignore the K value here.
all we have to do is to put all values of a,b into ascending
sort. Which is the simpliest way to minimize their difference. 
Then just print the corresponding value according to the index. 

testcase: 
-1 3 -2 0 -5 -1
-4 0 -1 4  0  0
0  1  2 3  4  5     -->idx 

now lets sort them
-5 -2 -1 -1 0 3
-4 -1  0  0 0 4
 4  2  0  5 3 1     -->idx 

according to the index lets print them: 
0 1  2 3  4 5
0 4 -1 0 -4 0
*/