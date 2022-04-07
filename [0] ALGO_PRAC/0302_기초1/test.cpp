#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> v1;
    vector<int> v2(3);

    for(int i=0; i<5; i++){
        v1[i] = i+1;
    }


    for(int i=0; i<v2.size(); i++){
        cout << v2[i] << endl;
    }

    return 0;
}