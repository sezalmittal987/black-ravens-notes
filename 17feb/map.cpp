#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    // creation
    map<string, int> m;

    // insertion
    m.insert({"apple", 4});
    m["apple"] = 5;
    m["cherry"]  = 6;
    m["banana"] = 0;

    // accessing
    cout<<m["apple"]<<endl;
    m["apple"] *= 10;
    cout<<m["apple"]<<endl;

    // delete
    // m.erase("banana");

    //iteration
    for(auto u : m ){
        cout<<u.first<<" "<<u.second<<endl;
    }

    // for( auto it = m.begin(); it!= m.end() ; it++ ){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }

    // check if key is present or not
    if(m.count("cherry") == 0) {
        cout<<"Key is not present"<<endl;
    }
    else{
        cout<<"Key is present"<<endl;
    }
    
    auto it2 = m.find("banana");
    if( it2 == m.end() ) {
        cout<<"Key is not present"<<endl;
    }
    else{
        cout<<it2->first<<" "<<it2->second<<endl;
    }

    // you have to find the key next to banana
    it2++;
    cout<<it2->first<<" "<<it2->second<<endl;

    it2--;
    cout<<it2->first<<" "<<it2->second<<endl;

    it2--;
    cout<<it2->first<<" "<<it2->second<<endl;
}