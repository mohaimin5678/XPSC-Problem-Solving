#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1e5+9;
ll a[maxN];
ll t[4*maxN];
ll lazy[4*maxN];      

void push(int n,int b,int e){
    if(lazy[n]==0) return;      //no lazy value so return
    if(lazy[n]%2==1){       //if value is odd means true so change
        if(t[n]==1) t[n]=0;
        else t[n]=1;
    } 
    // cout<<t[n]<<ln;  
    if(b!=e){                       //not a leaf node then
        int l=2*n, r=(2*n)+1;
        lazy[l]+=lazy[n];   
        lazy[r]+=lazy[n];
    }
    lazy[n]=0; //lazy part er kaj shesh howar por lazy reset to -1.
    //cause node can be updated by 0 also. so returing when finding 
    //0 caused WA for a long time. returning -1 solved the issue. 
}

void build(int n,int b,int e){          //O(N)
    if(b==e){
        t[n]=a[b];      //a[e] o dite parbo since index same e. oi index
        return;         //er value tai node e save hocche
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    build(l,b,mid);
    build(r,mid+1,e);
    // t[n]=max(t[l],t[r]);
    // t[n]=t[l]+t[r];
}

void update(int n,int b,int e,int i,int j){     //O(logN)
    push(n,b,e); //visit er shathe shathe lazy ta update kore dibo
    if(j<b || i>e){ //i,j range er baire so niche ar jawar dorkar nai
        return;     //"out of" segment
    }
    if(b>=i && e<=j){
        //particular ei node er under e all node V diye update hobe
        lazy[n]++;    //using XOR will change T to F & F to T
        push(n,b,e); //visit er shathe shathe lazy ta update kore dibo
        return;  //"inside" segment
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);
    // t[n]=max(t[l],t[r]);
    // t[n]=t[l]+t[r];
}
void query(int n,int b,int e,int i,int j){     //O(logN)
    push(n,b,e); //visit er shathe shathe lazy ta update kore dibo
    if(e<i || b>j){   //"out of" segment
        return;     //particular segment query range er baire
    }
    if(b>=i && e<=j){   //"inside" segment
        cout<<t[n]<<ln;
        return;    //particular segment query range er fully vitore
                        //tai oi segment er sum tai return diye dicchi
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    if(i<=mid) query(l,b,mid,i,j); 
    query(r,mid+1,e,i,j);  
}
void mohaimin(){
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        a[i+1]=s[i]-'0';
    }
    for(int i=0;i<4*s.size();i++) lazy[i]=0;
    int m;
    cin>>m;
    int n=s.size();
    build(1,1,n);
    while(m--){
        char t;
        cin>>t;
        if(t=='I'){
            int l,r;
            // bool v=true;
            cin>>l>>r;
            // l++;
            update(1,1,n,l,r);
        }
        else{
            int l;
            cin>>l;
            // l++;
            query(1,1,n,l,l);
            // cout<<ans<<ln;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<":"<<ln;
        mohaimin();
    }
}
