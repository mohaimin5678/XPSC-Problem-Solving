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
    if(lazy[n]==0) return;      //no lazy value so return
    //ei segment er all node count * per node e add howa value
    t[n]+=(1LL*(e-b+1)*lazy[n]);    
    if(b!=e){       //not a leaf node then
        int l=2*n, r=(2*n)+1;
        //propagate kore diye dibo children ke
        lazy[l]+=lazy[n];
        lazy[r]+=lazy[n];
    }
    lazy[n]=0; //lazy part er kaj shesh howar por lazy reset to 0. 
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
    t[n]=t[l]+t[r];
    //backtrack kore ashar por tar 2 child er sum e hobe n node er sum
}
ll query(int n,int b,int e,int i,int j){     //O(logN)
    push(n,b,e); //visit er shathe shathe lazy ta update kore dibo
    if(e<i || b>j){   //"out of" segment
        return 0;     //particular segment query range er baire
    }
    if(b>=i && e<=j){   //"inside" segment
        return t[n];    //particular segment query range er fully vitore
                        //tai oi segment er sum tai return diye dicchi
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    return query(l,b,mid,i,j) + query(r,mid+1,e,i,j); 
    //just both left+right child segment theke asha sum add kore return
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
            int l,r,v;
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