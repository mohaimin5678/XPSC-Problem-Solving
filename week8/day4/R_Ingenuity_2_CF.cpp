#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
void mohaimin(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> nor,sou,est,wst;
    for(int i=0;i<n;i++){
        if(s[i]=='N') nor.push_back(i);
        if(s[i]=='S') sou.push_back(i);
        if(s[i]=='E') est.push_back(i);
        if(s[i]=='W') wst.push_back(i);
    }
    vector<char> ans(n);
    int i=0;
    for(i=0;i<min(nor.size(),sou.size());i++){
        if(i%2==0){
            ans[nor[i]]='R';
            ans[sou[i]]='R';
        }
        else{
            ans[nor[i]]='H';
            ans[sou[i]]='H';
        }
    }
    // int j=min(nor.size(),sou.size());
    for(int j=min(nor.size(),sou.size());j<max(nor.size(),sou.size());j+=2){
        if(j<nor.size()){
            if(j+1==nor.size()){
                cout<<"NO"<<endl;
                return;
            }
            ans[nor[j]]='R';
            ans[nor[j+1]]='H';
        }
        else if(j<sou.size()){
            if(j+1==sou.size()){
                cout<<"NO"<<endl;
                return;
            }
            ans[sou[j]]='R';
            ans[sou[j+1]]='H';
        }
    }
    i=0;
    for(i=0;i<min(est.size(),wst.size());i++){
        if(i%2!=0){
            ans[est[i]]='R';
            ans[wst[i]]='R';
        }
        else{
            ans[est[i]]='H';
            ans[wst[i]]='H';
        }
    }
    for(int j=min(est.size(),wst.size());j<max(est.size(),wst.size());j+=2){
        if(j<est.size()){
            if(j+1==est.size()){
                cout<<"NO"<<endl;
                return;
            }
            ans[est[j]]='R';
            ans[est[j+1]]='H';
        }
        else if(j<wst.size()){
            if(j+1==wst.size()){
                cout<<"NO"<<endl;
                return;
            }
            ans[wst[j]]='R';
            ans[wst[j+1]]='H';
        }
    }
    int cntR=0,cntH=0;
    for(auto c:ans){
        if(c=='R') cntR++;
        else cntH++;
    }
    if(cntR==0 || cntH==0){
        cout<<"NO"<<endl;
        return;
    }
    
    for(auto c:ans){
        cout<<c;
    }
    cout<<endl;
    
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
wha is needed is that given string has moves which we will distribute
between R & H where both should have atleast 1 move & after finishing 
all of their moves, both has to be ended up in the same position. if
not then print -1 

focus that if we give N which is (x,y+1) == (0,1)
& then we give S which is (x,y-1) == (0,1-1) = (0,0)
means a pair of NS/SN doesn't change their index after operation is done. 
AGAIN if we give E which is (x+1,y) == (0+1,0) = (1,0)
& then we give W which is (x-1,y) == (1-1,0) = (0,0)
means a pair of WE/EW doesn't change their index after operation is done. 

Now lets see when we'll print -1. 
if after pairing them, particular remaining direction is odd numbered. 
means suppose we have s=WWWWE
here we can make 1 pair of (WE) then we'll still have 3 more W. 
in that situation, we can't keep both R & H in the same position. 

also if we can't give atleast one directional move to R/H then its 
also -1. 

now approach explanation: 
6
NENSNE
012345
here first we calculated the directions with their indices. 
Nor=0,2,4
Sou=3
Est=1,5
ans=[]

for(i=0;i<min(nor.size(),sou.size());i++){
    if(i%2==0){
        ans[nor[i]]='R';
        ans[sou[i]]='R';
    }
    else{
        ans[nor[i]]='H';
        ans[sou[i]]='H';
    }
}
here, min is 1 so this loop will work 1 time. 
since i=0 so ans[nor[i]]==ans[0]='R' && ans[sou[i]]==ans[3]='R'
so ans=[R__R__]
then we have to another loop for the remaining north indices. 
for(int j=min(nor.size(),sou.size());j<max(nor.size(),sou.size());j+=2){
    if(j<nor.size()){
        if(j+1==nor.size()){
            cout<<"NO"<<endl;
            return;
        }
        ans[nor[j]]='R';
        ans[nor[j+1]]='H';
    }
    else if(j<sou.size()){
        if(j+1==sou.size()){
            cout<<"NO"<<endl;
            return;
        }
        ans[sou[j]]='R';
        ans[sou[j+1]]='H';
    }
}
since remaining are from north so it will go inside first if condtion,
inner if checking the possibilities of odd. if its odd then NO & return. 
since for this testcase its even so ans[nor[j]]==ans[nor[1]]=ans[2]=R
&& ans[nor[j+1]]==ans[nor[2]]=ans[4]=H
so ans=[R_RRH_]

now
i=0;
for(i=0;i<min(est.size(),wst.size());i++){
    if(i%2!=0){
        ans[est[i]]='R';
        ans[wst[i]]='R';
    }
    else{
        ans[est[i]]='H';
        ans[wst[i]]='H';
    }
}
this for loop won't get executed because wst.size()==0
but,
for(int j=min(est.size(),wst.size());j<max(est.size(),wst.size());j+=2){
    if(j<est.size()){
        if(j+1==est.size()){
            cout<<"NO"<<endl;
            return;
        }
        ans[est[j]]='R';
        ans[est[j+1]]='H';
    }
    else if(j<wst.size()){
        if(j+1==wst.size()){
            cout<<"NO"<<endl;
            return;
        }
        ans[wst[j]]='R';
        ans[wst[j+1]]='H';
    }
}
this loop will get executed for est & if condition will operate
since est.size() is even so ans[est[j]]==ans[est[0]]=ans[1]='R'
&& ans[est[j+1]]==ans[est[1]]=ans[5]='H';
so ans=[RRRRHH]
*/