#include <iostream>
using namespace std;
int main() {
    char car[4] = {'h', 'a', 'l', 'o'};
    for( int i = 0 ; i < 4 ; i++ ){
        cout<<car[i];
    }
    cout<<endl;
    cout<<car<<endl;

    car[3] = '\0';
    cout<<car<<endl;

    char b[5] = {'b', 'a', 'r', 's', '\0'};
    cout<<b<<endl;

    char a[] = "apple";
    cout<<a<<endl;
    cout<<sizeof(a)/sizeof(char) <<endl; // 6
    // a = {'a', 'p', 'p', 'l', 'e', '\0'}
}
