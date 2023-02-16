#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
    // declare
    unordered_map< string, int> m;

    //insertion
    m.insert({"apple", 1});
    m.insert(make_pair("banana", 2));

    m["cherry"] = 3;

    // access
    cout<<m["apple"]<<endl;
    m["apple"] *= 4;
    cout<<m["apple"] <<endl;

    cout<<m.at("apple")<<endl;

    // cout<<m.at("dragon fruit")<<endl; // throws error
    cout<<m["dragon fruit"]<<endl; // m[key] if it doesn't exist, then it creates a new pair as {key, 0}

    // question
    m["orange"] += 2;
    cout<<m["orange"]<<endl; 

    // deletion
    m.erase("orange");

    // iterate
    for( pair<string, int> p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }

    for ( auto it = m.begin() ; it!= m.end() ; it++ ){ // operator overloading it-- 
        cout<< (*it).first<<" "<<(*it).second<<endl;
    }
    
    //iterating vector
    /*
    int v[] = {1, 2, 3, 4, 5};
    for( int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    */
}