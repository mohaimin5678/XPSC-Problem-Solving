#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void mohaimin(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    set<int> st;
    //taking all index value & automatically sorting it & removing duplicate    
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
    string a;
    cin>>a;
    sort(a.begin(),a.end());    //sorting the string lexicographically 
    int idx=0;
    for(auto v:st){
        //For same index, small character will be assigned also if a 
        //character (b) supposed to insert into index 1 but it didn't 
        //because of a smaller character(a) inserted into that index,
        //the bigger character(b) will be inserted into index 2!
        s[v-1]=a[idx];
        idx++;
    }
    cout<<s<<endl;
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
    return 0;
}
/*
example testcase:
3 3
zxy
1 2 1
bca

here after inserting into set the operation will be: 1 2
& string will be= abc
for index 1: s[0]=z which will be replaced by a so s[0]=a
for index 2: s[1]=x which will be replaced by b so s[1]=b
final answer: aby

Note that here b supposed to insert into index 1 according to the
testcase but since 'a' < 'b' so 'a' inserted into index 1. But 'b' didn't
removed. It changed it's supposed index & inserted into index 2. 
*/