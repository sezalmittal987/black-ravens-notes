#include<iostream>
#include<set>
#include<string>
using namespace std;

int main(){
    // creation
    set<string> s;

    //insertion
    s.insert("orange");
    s.insert("apple");
    s.insert("banana");
    s.insert("cherry");

    // present or not
    // count() or find()
    if( s.count("orange") == 0){
        cout<<"Value is not present!"<<endl;
    }
    else{
        cout<<"Value is present!"<<endl;
    }

    //deletion
    s.erase("cherry");

    //iteration
    for( auto u  :s ){
        cout<< u <<" ";
    }
    cout<<endl;
    for(auto it = s.begin() ;it!= s.end(); it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;

}