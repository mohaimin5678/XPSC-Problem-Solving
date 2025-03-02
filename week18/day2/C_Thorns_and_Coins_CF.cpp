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
    // char a[n];
    // vector<char> v(n);
    // for(int i=0;i<n;i++){
    //     cin>>v[i];
    // }
    string s;
    cin>>s;
    int coin=0;
    for(int i=0;i<n;){
        if(s[i]=='@'){
            coin++;
            // cout<<"hamaise"<<endl;
            if(i==n-1) break;
        }
        else if(s[i]=='*'){
            break;
        }
        else if(s[i]=='.'){
            if(i==n-1) break;
        }

        if(i+1<n){
            if(s[i+1]=='*'){
                if(i+2<n){
                    i=i+2;
                }
                else{
                    break;
                }
            }
            else if(s[i+1]=='.' || s[i+1]=='@'){
                i++;
            }
        }
    }
    cout<<coin<<ln;
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