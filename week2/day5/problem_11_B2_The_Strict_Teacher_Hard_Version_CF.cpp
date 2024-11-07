#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
void mohaimin(){
    int n,t,q;
    cin>>n>>t>>q;
    vector<int> tech(t);
    for(int i=0;i<t;i++) cin>>tech[i];
    sort(tech.begin(),tech.end());
    while(q--){
        int x;
        cin>>x;
        if(x<tech[0]){
            //first teacher er theke low value hole david ekdom
            //left position e jaite parbe
            cout<<tech[0]-1<<endl; //so oi position e jaite eto sec lagbe
            continue;
        }
        else if(x>tech[t-1]){
            //last teacher er theke higher value hole david ekdom
            //right position e jaite parbe
            cout<<n-tech[t-1]<<endl; //so oi position e jaite eto sec lagbe
            continue;
        }
        
        //ekhon amar ekta bepar kheyal rakhte hobe je ekhane ami chaitesi ki
        //chaitesi x er ekdom nearby 2ta value. lowerbound use korle je
        //value ta chai sheita/tar theke slightly bigger value return dibe
        //Jehetu ekhane shob distinct value tai lowerbound e slightly
        //bigger value tai return dibe & oi iterator ke 1bar decrement
        //korlei x er slightly lower value ta peye jabo cause eta sorted.
        auto it=lower_bound(tech.begin(),tech.end(),x);
        auto it2=it;
        it2--;
        //it is slightly bigger & it2 is slightly smaller
        int l=*it2;
        int r=*it;
        int mid=(l+r)/2;
        cout<<min(abs(mid-l),abs(r-mid))<<endl;
        //for example:
        /*
        for testcase 2:
        int x=3
        so l=1 & r=4
        so mid=2
        min((2-1),(4-2))=1 == ans
        */
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests;
    cin>>tests;
    while(tests--){
        mohaimin();
    }
    return 0;
}