#include <iostream>
using namespace std;
int main(){
    int marks;
    char grade;
    cin>>marks;
    // if( marks >= 90 ){
    //     grade = 'A';
    // }
    // if( marks >= 75 and marks < 90) {
    //     grade = 'B';
    // }
    // if( marks >= 60 and marks < 75){
    //     grade = 'C';
    // }
    // if( marks < 60){
    //     grade = 'D';
    // }

    if( marks >= 90){
        grade = 'A'; 
    }
    else if ( marks >= 75){
        grade = 'B'; 
    }
    else if ( marks >= 60 ){
        grade = 'C'; 
    }
    else{
        grade = 'D';
    }
    cout<<grade<<endl;
}