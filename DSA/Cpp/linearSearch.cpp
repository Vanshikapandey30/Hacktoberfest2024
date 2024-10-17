#include <iostream>
using namespace std;

int main(){
    int arr[5] = {19, 14, -5, 17, 21};
    int target;

    cin>>target;

    for (int i = 0; i < 5; i++){
        int element = arr[i];
        if (element == target){
            cout<<"Element is found at index: "<<i + 1;
        }
    }
    return -1;
}