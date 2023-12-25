#include <stdio.h>
#define Number 10


void heapify(int arr[]){
    int root = 1;

    while(arr[root] < arr[root*2] || arr[root] < arr[root*2+1]){
        int left = root *2;
        int right = root*2+1;
        int temp;
        if(arr[root] < arr[left]){
            temp = arr[root];
            arr[root] = arr[left];
            arr[left] = temp;
            root = left;
        }
        else if(arr[root] < arr[right]){
            temp = arr[root];
            arr[root] = arr[right];
            arr[right] = temp;
            root = right;
        }
        else{
            if(arr[left] > arr[right]){
                temp = arr[root];
                arr[root] = arr[left];
                arr[left] = temp;
                root = left;
            }
            else{
                temp = arr[root];
                arr[root] = arr[right];
                arr[right] = temp;
                root = right;
            }
        }
    }
}

void insert(int arr[],int value,int lastIndex){
    arr[lastIndex] = value;
    heapify(arr);
}



int removeMax(int arr[],int lastIndex){
    lastIndex--;
    int result = arr[0];
    arr[0] = arr[lastIndex];
    arr[lastIndex] = 0;
    lastIndex--;
    heapify(arr);
    return result;
}









int main() {

    int heapArr[Number];
    for (int i = 0; i < Number; i++){
        heapArr[i] = 0;
    }
    int lastIndex = 1;
    insert(heapArr,10,lastIndex);
    lastIndex++;


    insert(heapArr,12,lastIndex);
    lastIndex++;



    insert(heapArr,14,lastIndex);
    lastIndex++;


    insert(heapArr,8,lastIndex);
    lastIndex++;

    insert(heapArr,3,lastIndex);
    lastIndex++;

    //removeMax(heapArr,lastIndex);
    lastIndex--;



    printf("Hello, World!\n");
    return 0;
}
