#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    map<string,string> ans,has; 
    //ans diye old er new handle ki
    //has diye new er old handle ki 
    while(n--){
        string a,b;
        cin>>a>>b;

        if(has.find(a)!=has.end()){
            string s=has[a];
            // cout<<s<<'\n';
            ans[s]=b;
            has.erase(a);
            has[b]=s;
        }
        else{
            //old handle er value hishabe new handle
            ans[a]=b;
            //new handle er value hishabe old handle
            has[b]=a;
        }
        
    }
    cout<<ans.size()<<'\n';
    for(auto [x,y]:ans){
        cout<<x<<" "<<y<<'\n';
    }
    return 0;
}