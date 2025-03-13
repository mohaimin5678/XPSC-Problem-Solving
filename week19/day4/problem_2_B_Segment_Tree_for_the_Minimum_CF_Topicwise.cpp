#include<bits/stdc++.h>
#define ll long long int
#define ln '\n'
#define cyes cout<<"YES"<<ln
#define cno cout<<"NO"<<ln
#define yes cout<<"Yes"<<ln
#define no cout<<"No"<<ln
using namespace std;
const int maxN=1e5+9;
ll a[maxN], t[4*maxN];      //t is for tree
void build(int n,int b,int e){          //O(N)
    if(b==e){
        t[n]=a[b];      //a[e] o dite parbo since index same e. oi index
        return;         //er value tai node e save hocche
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=min(t[l],t[r]);
    //backtrack kore ashar por tar 2 child er min e hobe n node er min
}

void update(int n,int b,int e,int i,int v){     //O(logN)
    if(i<b || i>e){   //i range er baire so niche ar jawar dorkar nai
        return;     //"out of" segment
    }
    if(b==e){
        t[n]=v;  //particular index e chole ashchi so node update korbo
        return;  //"inside" segment
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    update(l,b,mid,i,v);
    update(r,mid+1,e,i,v);
    t[n]=min(t[l],t[r]);
    //backtrack kore ashar por tar 2 child er min e hobe n node er min
}
ll query(int n,int b,int e,int i,int j){     //O(logN)
    if(e<i || b>j){   //"out of" segment
        return INT_MAX;
        //particular segment query range er baire tai INT_MAX pathabo
        //jate onndiker range er vitorer value ta must min hishabe ney
    }
    if(b>=i && e<=j){   //"inside" segment
        return t[n];    //particular segment query range er fully vitore
                        //tai oi segment er sum tai return diye dicchi
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    return min(query(l,b,mid,i,j) , query(r,mid+1,e,i,j)); 
    //just min(left,right) child segment theke asha min fix kore return
    //kore dicchi
}
void mohaimin(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int idx,v;
            cin>>idx>>v;
            idx++;
            update(1,1,n,idx,v);
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
