#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    set<int> st[n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]=='1'){
                st[j+1].insert(i+1);
            }
        }
    }
    for(int i=1;i<=n;i++){
        st[i].insert(i);
    }
    for(int i=1;i<=n;i++){
        cout<<st[i].size()<<" ";
        for(int x:st[i]) cout<<x<<" ";
        cout<<ln;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        mohaimin();
    }
}
/*
we need to make i as a subset of j when we get v[i][j]==1
means row number will be a subset of column number. (1-based)

now whenever we find v[i][j]=='1' we'll just do st[column].insert(row)
so for this testcase: 
4
0001
1001
0001
0000

all set will be like: 
set[1]= 2
set[2]= 0
set[3]= 0
set[4]= 1 2 3

but we can't keep any set empty cause it won't be a proper subset
so we'll just put the row number on their own set. Now no set is
empty. And they'll look like: 
set[1]= 1 2
set[2]= 2
set[3]= 3
set[4]= 1 2 3 4
its also matching all conditions. set[2] is a subset of set[1] &
all 1st 2nd 3rd set are subset of set[4]. 

so final answer is: 
each set's size & the elements in one line. 
2 1 2 
1 2 
1 3 
4 1 2 3 4
*/
