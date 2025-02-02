#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
void mohaimin(){
    string s;
    cin>>s;
    int cnt=0;
    stack<char> st;
    st.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(!st.empty() && st.top()==s[i]){
            cnt++;
            st.pop();
        }
        else st.push(s[i]);
    }
    if(cnt%2==0) cno;
    else cyes;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--){
        mohaimin();
    }
}