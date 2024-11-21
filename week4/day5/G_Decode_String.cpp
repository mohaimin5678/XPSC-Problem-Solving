#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // string s="a";
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        stack<char> st;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                string x="";
                x+=s[i-1];
                x+=s[i-2];
                i-=2;
                reverse(x.begin(),x.end());
                // cout<<x<<endl;
                int num=stoi(x);
                num--;
                char c='a'+num;
                // cout<<c<<endl;
                st.push(c);
            }
            else{
                
                int num=s[i]-'0';
                num--;
                char c='a'+num;
                // cout<<c<<endl;
                st.push(c);
            }
        }
        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }
        cout<<endl;
    }
    return 0;
}