#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxM=300000;
vector<int> v(maxM);
int n;
int recursion(int l,int r){
    if(r-l==1) return 0;    //base case
    int mid=l+(r-l)/2;
    int val1=*max_element(v.begin()+l,v.begin()+mid);
    int val2=*max_element(v.begin()+mid,v.begin()+r);
    int ans=0;
    if(val1>val2){
        ans++;
        for(int i=0;i<(mid-l);i++){
            swap(v[l+i],v[mid+i]);
        }
    }
    // for(int i=0;i<n;i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<ln;
    return recursion(l,mid) + recursion(mid,r) + ans;
}

void mohaimin(){
    cin>>n;
    vector<int> s(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        s[i]=v[i];
    }
    int ans=recursion(0,n);
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++){
        if(s[i]!=v[i]){
            cout<<-1<<ln;
            return;
        }
    }
    cout<<ans<<ln;
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
/*
left child er max jodi right child er max theke boro hoy tahole
operation hobe must. so left side to right side swap hobe. 
tarpor left side pathabo recursion e, right side pathabo recursion
e & tara answer niye ashle ami je answer ta paisi oita add kore
return pathay dibo. 
r-l==1 hole return 0 cause amra l er shathe mid pathacchi OR
mid er shathe R pathacchi jeta always e 1 beshi so jodi amra
erokom r-l==1 scenario pai tarmane ekhon ekhane just ekta single
value so ekhane kono check korar dorkar nai & etai amader base case. 
*/