#include <iostream>
using namespace std;

int main(){
    char fruit;
    char color;
    cin>>fruit;
    // if( fruit == 'A'){
    //     color = 'R';
    // }    
    // else{
    //     color = 'Y';
    // }
    // cout<<color<<endl;


    if( fruit == 'A'){
        cout<<"Red"<<endl;
    }  
    else if( fruit == 'C'){
        cout<<"Cherry"<<endl;
    }
    else{ 
        cout<<"Yellow"<<endl;
    }


    if( fruit == 'A' or fruit == 'B'){
        cout<<"Red"<<endl;
    }    
    if(fruit == 'B') {
        cout<<"Yellow"<<endl;
    }
    
}