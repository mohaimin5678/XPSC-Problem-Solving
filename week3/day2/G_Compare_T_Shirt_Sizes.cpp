//https://codeforces.com/contest/1741
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        if(a==b) cout<<"="<<endl;
        else{ 
            char c1;
            int cnt1=0;
            for(int i=0;i<a.size();i++){
                if(a[i]!='X') c1=a[i];
                else{ 
                    cnt1++;
                }
            }
            char c2;
            int cnt2=0;
            for(int i=0;i<b.size();i++){
                if(b[i]!='X') c2=b[i];
                else{ 
                    cnt2++;
                }
            }
            if(c1==c2){
                if(c1!='S'){
                    if(cnt1>cnt2) cout<<">"<<endl;
                    else cout<<"<"<<endl;
                }
                else{
                    if(cnt1>cnt2) cout<<"<"<<endl;
                    else cout<<">"<<endl;
                }
            }
            else{
                if(c1=='L' && c2=='M') cout<<">"<<endl;
                else if(c1=='S' && c2=='M') cout<<"<"<<endl;
                else if(c1=='L' && c2=='S') cout<<">"<<endl;
                else if(c1=='S' && c2=='L') cout<<"<"<<endl;
                else if(c1=='M' && c2=='S') cout<<">"<<endl;
                else if(c1=='M' && c2=='L') cout<<"<"<<endl;
            }
        }
    }
    return 0;
}