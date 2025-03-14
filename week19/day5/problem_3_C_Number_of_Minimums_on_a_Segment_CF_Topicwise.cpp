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
struct node{
    int mn,count;
};
node t[4*maxN];      //t is for tree

node merge(node l, node r){
    node ans;             //etay min,min count store kore return korbo
    ans.mn=min(l.mn,r.mn);  //ans node er first value 
    ans.count=0;            //2nd value ta initially 0 store korlam
    if(l.mn==ans.mn){       //jodi left child er shathe min value mile
        ans.count+=l.count; //tahole left er count ta add korbo
    }
    if(r.mn==ans.mn){       //jodi right child er shathe min value mile
        ans.count+=r.count; //tahole right er count ta add korbo
    }
    return ans;        //build hoye jawar por just node ta return korbo
}

void build(int n,int b,int e){          //O(N)
    if(b==e){
        t[n].mn=a[b];  //a[e] o dite parbo since index same e. oi index
        t[n].count=1;  //er value tai node e save hocche & amra count 1
        return;        //o shathe add kortesi jate counting e shubidha hoy
    }
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=merge(t[l],t[r]);
    //backtrack kore ashar por tar 2 child er min & min_count e hobe 
    //n node er min & min_count
}

void update(int n,int b,int e,int i,int v){     //O(logN)
    if(i<b || i>e){   //i range er baire so niche ar jawar dorkar nai
        return;     //"out of" segment
    }
    if(b==e){
        t[n].mn=v;  //particular index e chole ashchi so node update korbo
        t[n].count=1;  //also count tao 1 kore dibo
        return;     //"inside" segment eta
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    update(l,b,mid,i,v);
    update(r,mid+1,e,i,v);
    t[n]=merge(t[l],t[r]);
    //backtrack kore ashar por tar 2 child er min & min_count e hobe 
    //n node er min & min_count
}
node query(int n,int b,int e,int i,int j){     //O(logN)
    if(e<i || b>j){   //"out of" segment
        return {INT_MAX,0}; //pair kore pathabo
        //particular segment query range er baire tai INT_MAX pathabo
        //jate onndiker range er vitorer value ta must min hishabe ney
        //also count e contribute na korar jonno 0 pathabo count parameter e
    }
    if(b>=i && e<=j){   //"inside" segment
        return t[n];    //fully range er vitore thakle min,min_count 
                        //tai return diye dicchi
    }
    //"intersect" segment
    int mid=(b+e)/2;
    int l=2*n, r=(2*n)+1;
    return merge(query(l,b,mid,i,j) , query(r,mid+1,e,i,j)); 
    //just merge(left,right) child segment theke asha min & min_count
    //fix kore return kore dicchi
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
            node ans=query(1,1,n,l,r);      //it'll return a node
            cout<<ans.mn<<" "<<ans.count<<ln;
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
