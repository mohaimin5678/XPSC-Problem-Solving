#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    float win,draw,lose;
    cin>>win>>draw>>lose;
    float a=0,b=0;
    a=win+(draw*0.5);
    b=(draw*0.5)+lose;
    if(win+draw+lose==4){
        if(a>b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    else{
        float left=4-(win+draw+lose);
        a+=left;
        if(a>b) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}