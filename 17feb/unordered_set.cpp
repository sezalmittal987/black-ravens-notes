#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    // creation
    unordered_set<int> s;

    // insertion
    s.insert(2);
    s.insert(12);
    s.insert(10);
    s.insert(20);

    // present or not
    auto it = s.find(13);
    if( it == s.end()) {
        cout<<"Value is not present!"<<endl;
    }
    else {
        cout<<"Value is present!"<<endl;
    }

    // deletion
    s.erase(2);

    // iteration
    for(auto u : s){
        cout<<u<<" ";
    }
    cout<<endl;

    for(auto it = s.begin() ; it!= s.end() ;it++){
        cout<< (*it)<<endl;
    }

}