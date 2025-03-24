#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1e5+9;
ll a[maxN], t[4*maxN], lazy[4*maxN];      //t is for tree

void push(int n,int b,int e){
    if(lazy[n]==-1) return;      //no lazy value so return
    t[n]=(e-b+1)*lazy[n];  //ei node er under e shob node e lazy[n]
    // boshbe tai ei node e total nodes * lazy[n] boshay dibo
    
    if(b!=e){       //not a leaf node then
        int l=2*n, r=(2*n)+1;
        lazy[l]=lazy[n];   
        lazy[r]=lazy[n];
    }
    lazy[n]=-1; //lazy part er kaj shesh howar por lazy reset to -1.
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
    t[n]=t[l]+t[r];
}

void update(int n,int b,int e,int i,int j,ll v){     //O(logN)
    push(n,b,e); //visit er shathe shathe lazy ta update kore dibo
    if(j<b || i>e){ //"out of" segment
        return;     
    }
    if(b>=i && e<=j){   //"inside" segment
        //particular ei node er under e all node V diye update hobe
        lazy[n]=v; 
        push(n,b,e); //visit er shathe shathe lazy ta update kore dibo
        return;  
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    update(l,b,mid,i,j,v);
    update(r,mid+1,e,i,j,v);
    t[n]=t[l]+t[r];
}
ll query(int n,int b,int e,int i,int j){     //O(logN)
    push(n,b,e); //visit er shathe shathe lazy ta update kore dibo
    if(e<i || b>j){   //"out of" segment
        return 0;     
    }
    if(b>=i && e<=j){   //"inside" segment
        return t[n];    //particular segment query range er fully vitore
                        //tai oi segment er sum tai return diye dicchi
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    return (query(l,b,mid,i,j) + query(r,mid+1,e,i,j));  
}
void mohaimin(){
    int n,m;
    cin>>n>>m;
    build(1,1,n);
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int l,r;
            ll v;
            cin>>l>>r>>v;
            l++;
            update(1,1,n,l,r,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            l++;
            ll ans=query(1,1,n,l,r);
            cout<<ans<<ln;
        }
    }
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
