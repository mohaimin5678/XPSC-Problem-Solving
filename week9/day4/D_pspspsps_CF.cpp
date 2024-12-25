//Not accepted
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
        bool alldot=true;
        bool allp=true;
        bool alls=true;
        for(int i=0;i<n;i++){
            if(s[i]!='.'){
                alldot=false;
            }
            if(s[i]!='p') allp=false;
            if(s[i]!='s') alls=false;
        }
        if(alldot || allp || alls) cout<<"YES"<<endl;
        else{
            bool p_present=false,yes=true;
            for(int i=0;i<n;i++){
                if(s[i]=='p'){
                    p_present=true;
                    bool s_found=false;
                    if(i==n-1) continue;
                    for(int j=1;j<i;j++){
                        if(s[j]=='s'){
                            cout<<"NO"<<endl;
                            s_found=true;
                            break;
                        }
                    }
                    if(s_found){
                        yes=false;
                        break;
                    }
                }
                else if(s[i]=='s'){
                    if(p_present){
                        cout<<"NO"<<endl;
                        yes=false;
                        break;
                    }
                }
            }
            if(yes) cout<<"YES"<<endl;
        }
    }
    return 0;
}