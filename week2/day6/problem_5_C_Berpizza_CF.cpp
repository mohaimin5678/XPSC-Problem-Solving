#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    set<pair<int,int>> s;   
    //if we give pair inside a set, it will sort based on first value
    multiset<pair<int,int>> ml;
    //it will sort based on first, if same first value then sort 
    //based on second value. both sorting in ascending order
    //but we need multiset's 2nd value on descending order
    //so we can put a - infront which will make it negative!
    //before negative (10,2) then (10,4) was the serial
    //after negative (10,-4) then (10,-2) will be the serial

    vector<int> ans;
    int idx=0;
    for(int i=0;i<n;i++){
        int type;
        cin>>type;
        if(type==1){
            int money;
            cin>>money;
            idx++;
            s.insert({idx,money});
            ml.insert({money,-idx});
        }
        else if(type==2){   //monocarp
            int pos,money;
            pos=s.begin()->first;
            money=s.begin()->second;
            ans.push_back(pos);
            s.erase(s.begin());
            ml.erase({money,-pos});
        }
        else{
            int pos= -ml.rbegin()->second;
            int money=ml.rbegin()->first;
            ans.push_back(pos);
            ml.erase(--ml.end());   //largest value deleted
            s.erase({pos,money});   //same value erased from set
        }
    }
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
/*
testcase:
8
1 8
1 10
1 6
3
2
1 9
2
3

explanation: 
1 8 means 8 amount of money will be spend by customer 1
1 10 means 10 amount of money will be spend by customer 2
1 6 means 6 amount of money will be spend by customer 3
3 means polycarp will serve & he will serve customer 2
2 means monocarp will serve & he will serve customer 1
1 9 means 9 amount of money will be spend by customer 4
2 means monocarp will serve & he will serve customer 3
3 means polycarp will serve & he will serve customer 4
so serving serial is: 2 1 3 4
*/