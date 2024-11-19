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
        string s;
        cin>>n>>s;
        int op=0;
        bool flag=false;
        char cur=s[0];
        int zero=0,one=0;
        if(s[0]=='1') one++;
        else zero++;
        for(int i=0;i<n;i++){
            
            if(s[i]!=cur){
                if(s[i]=='1') one++;
                else zero++;
                cur=s[i];
            }
            
        }
        if(zero>one){
            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    flag=true;
                }

                if(s[i]=='0' && flag==true){
                    flag=false;
                    op++;
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(s[i]=='0'){
                    flag=true;
                }

                if(s[i]=='1' && flag==true){
                    flag=false;
                    op++;
                }
                if(i==n-1 && flag==true) op++;
            }
        }
        cout<<op<<endl;
    }
    return 0;
}