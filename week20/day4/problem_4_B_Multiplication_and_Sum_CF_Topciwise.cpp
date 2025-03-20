#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1e5+9,MOD=1e9+7;
ll a[maxN], t[4*maxN], lazy[4*maxN];      //t is for tree

void push(int n,int b,int e){
    if(lazy[n]==1) return;      //1 doesn't change value so return
    //ei segment er all node e multiply hobe lazy er value
    t[n]=(1LL*t[n]*lazy[n])%MOD;    
    if(b!=e){       //not a leaf node then
        int l=2*n, r=(2*n)+1;
        //propagate kore diye dibo children ke, parent er lazy giye 
        //multiply hobe & tokhon value aro boro hoye jaite pare tai
        //ekhaneo MOD kore rakhte hobe. 
        lazy[l]=(1LL*lazy[l]*lazy[n])%MOD;    
        lazy[r]=(1LL*lazy[r]*lazy[n])%MOD;
    }
    lazy[n]=1; //lazy part er kaj shesh howar por lazy reset to 1.
    //cause 1 in multiplication doesn't change any value 
}
ll merge(ll l, ll r){
    return (l+r)%MOD;
}
void build(int n,int b,int e){          //O(N)
    lazy[n]=1;  //initially all node's lazy value is 1
    if(b==e){
        t[n]=1;      //initially all values are 1
        return;
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=merge(t[l],t[r]);     
    //backtrack kore ashar por tar 2 child er sum e hobe n node er sum
}

void update(int n,int b,int e,int i,int j,int v){     //O(logN)
    push(n,b,e); //visit er shathe shathe lazy ta update kore dibo
    if(j<b || i>e){ //i,j range er baire so niche ar jawar dorkar nai
        return;     //"out of" segment
    }
    if(b>=i && e<=j){
        //particular ei node er under e all node V diye update hobe
        lazy[n]=v; 
        push(n,b,e); //visit er shathe shathe lazy ta update kore dibo
        return;  //"inside" segment
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    update(l,b,mid,i,j,v);
    update(r,mid+1,e,i,j,v);
    t[n]=merge(t[l],t[r]);     
    //backtrack kore ashar por tar 2 child er sum e hobe n node er sum
}
ll query(int n,int b,int e,int i,int j){     //O(logN)
    push(n,b,e); //visit er shathe shathe lazy ta update kore dibo
    if(e<i || b>j){   //"out of" segment
        return 0; //jehetu sum kortesi so bairer value 0 hishabe jabe
    }
    if(b>=i && e<=j){   //"inside" segment
        return t[n];    //particular segment query range er fully vitore
                        //tai oi segment er sum tai return diye dicchi
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    return merge(query(l,b,mid,i,j),query(r,mid+1,e,i,j)); 
    //just min(left,right) segment theke asha sum add kore return
    //kore dicchi
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
/*
segment tree sum er motoi pray code ta. 
extra:- 
1) update function e i,j pass hobe
2) push function ekta banaite hobe. ekhane current node er sum update 
   hobe & children thakle tader kache curren lazy value propagate hobe.
   then current lazy value ta reset hoye jabe. 
3) push function ta 3 jaygay call hobe. i) update function e dhukei
   ii) update function e range ta fully i,j er moddhe thakle lazy set
   korei ekbar call hobe. iii) query function e dhukei

thats it.
*/
