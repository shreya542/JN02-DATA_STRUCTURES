#include <iostream>

int main() {
    int arr[] = {2, 5, 4, 7, 9, 10};
    int x = 7;
    int low = 0;
    int high = sizeof(arr) / sizeof(arr[0]);
    int mid = (low + high) / 2;
    
    while (low <= high) {
        if (arr[mid] < x) {
            low = mid + 1;
        } else if (arr[mid] == x) {
            std::cout << "Number found at index: " << mid << std::endl;
            break;
        } else {
            high = mid - 1;
            mid = (low + high) / 2;
            
            if (mid < 0) {
                mid = 0;
            } else if (mid >= sizeof(arr) / sizeof(arr[0])) {
                mid = sizeof(arr) / sizeof(arr[0]) - 1;
            }
        }
    }
    
    if (low > high) {
        std::cout << "Element not found" << std::endl;
    }
    
    return 0;
}


//Code by: Shreyasi Bagul