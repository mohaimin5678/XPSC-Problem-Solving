#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;
char first,last;
bool compare(pair<char,int> a,pair<char,int> b){
    return a.second<b.second;
}
bool compareChar(pair<char,int> a,pair<char,int> b){
    //if condition fillup means descending order sorting
    if(first>last) return a.first>b.first;
    return a.first<b.first; //ascending order sorting
}
void mohaimin(){
    string s;
    cin>>s;
    int n=s.size()-1;
    char start=min(s[0],s[n]);
    char end=max(s[0],s[n]);
    first=s[0];
    last=s[n];
    vector<pair<char,int>> order;
    for(int i=0;i<s.size();i++){
        if(s[i]>=start && s[i]<=end){
            //only taking them whos filling the range
            order.push_back({s[i],i+1});
        }
    }
    sort(order.begin(),order.end(),compare); //index wise sorting
    if(order.size()>2){
        sort(order.begin()+1,order.begin()+order.size()-1,compareChar);
        //char wise sorting
    }
    vector<int> v;
    ll cost=0;

    v.push_back(1); //initial insert
    for(int i=1;i<order.size();i++){
        //here we are taking the difference between current
        //& previous char & adding it to the cost
        cost+=abs(order[i-1].first-order[i].first);
        //taking the index serial into vector
        v.push_back(order[i].second);
    }
    cout<<cost<<" "<<v.size()<<endl;
    for(int x:v){
        cout<<x<<" ";
    }
    cout<<endl;
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
    return 0;
}
/*
testcase:
string: codeforces
index:  12345678910

range is between c & s. here all of them are inside range.
after index wise sorting the string won't change anything.
since we are taking all the character here. if any of the 
character actually went out of the range then this sort will
show the difference.

but after char wise sorting we are getting: 
string: ccdeefoors
index:  18349526710
cost=(c-c)+(c-d)+.....+(r-s)
which is 16
*/