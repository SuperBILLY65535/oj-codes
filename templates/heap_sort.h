#include <cstddef>

void make_maxheap(int arr[], const size_t &s) {
    size_t cur = 0, son = cur * 2 + 1;
    while(son < s) {
        if(son + 1 < s && arr[son+1] > arr[son]) son++;
        if(arr[cur] > arr[son]) break;
        
    }
}