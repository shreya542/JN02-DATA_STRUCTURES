#include <iostream>

int main() {
    int arr[]={2,5,4,7,9,10};
    int x=7;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        if(arr[i]==x){
            std::cout<<"\nElement Found at Index: "<<i;
        }
    }
   
    return 0;
}



//Code by: Shreyasi Bagul