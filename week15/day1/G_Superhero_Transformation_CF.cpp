#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
bool isvowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return true;
    else return false;
}
void mohaimin(){
    string a,b;
    cin>>a>>b;
    if(a.size()!=b.size()){
        no;
        return;
    }
    for(int i=0;i<a.size();i++){
        if(isvowel(a[i])!=isvowel(b[i])){
            no;
            return;
        }
    }
    yes;
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