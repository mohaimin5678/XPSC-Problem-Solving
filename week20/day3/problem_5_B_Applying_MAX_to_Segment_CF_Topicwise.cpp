#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1e5+9;
int a[maxN], t[4*maxN], lazy[4*maxN];      //t is for tree

void push(int n,int b,int e){
    if(lazy[n]==0) return;      //no lazy value so return
    t[n]=max(t[n],lazy[n]);    
    if(b!=e){       //not a leaf node then
        int l=2*n, r=(2*n)+1;
        //propagate kore diye dibo children ke new max ta. since
        //amra parent node e max place korsi jeta actually ashchei
        //child node theke! so child node e parent node e je value
        //ta diye update korsi sheta diye check korbo child e ekhon
        //kon max value ta use hobe. cause ekhane age theke er thekeo
        //bigger value lazy part hishabe thake pare. thats why ekhane
        //max of child's lazy & parent's lazy newa hoise.
        lazy[l]=max(lazy[n],lazy[l]);   
        lazy[r]=max(lazy[n],lazy[r]);
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
    t[n]=max(t[l],t[r]);
}

void update(int n,int b,int e,int i,int j,ll v){     //O(logN)
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
    t[n]=max(t[l],t[r]);
}
int query(int n,int b,int e,int i,int j){     //O(logN)
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
    return max(query(l,b,mid,i,j),query(r,mid+1,e,i,j)); 
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
            int l;
            cin>>l;
            l++;
            int ans=query(1,1,n,l,l);
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
