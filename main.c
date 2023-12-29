#include <stdio.h>
#define Number 10

int lastIndex = 1;

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyDown(int arr[]){
    int currNode = 1;

    while(arr[currNode] < arr[currNode*2] || arr[currNode] < arr[currNode*2+1]){
        int left = currNode*2;
        int right = currNode*2+1;
        if(arr[left] > arr[right]){
            swap(&arr[currNode],&arr[left]);
            currNode = left;
        } else{
            swap(&arr[currNode],&arr[right]);
            currNode = right;
        }
    }
}

void heapifyUp(int arr[]){
    int last = lastIndex;
    int root = last/2;

    while(arr[root] < arr[last] && root >= 1){
        swap(&arr[root],&arr[last]);
        last = root;
        root = last/2;
    }
}

//ekleme işleminde bottom-up kullanılmalı.
void insert(int arr[],int value){
    arr[lastIndex] = value;
    heapifyUp(arr);
}

//silme isleminde heapify top-down
int removeMax(int arr[]){
    int result = arr[1];
    arr[1] = arr[lastIndex];
    arr[lastIndex] = 0;
    lastIndex--;
    heapifyDown(arr);
    return result;
}

void printArray(int arr[]){
    for (int i = 0; i < lastIndex+1; i++) {
        printf("[%d]-",arr[i]);
    }
    printf("\n");
}

int main() {

    int heapArr[Number];
    for (int i = 0; i < Number; i++){
        heapArr[i] = 0;
    }
    insert(heapArr,10);
    lastIndex++;
    insert(heapArr,12);
    lastIndex++;
    insert(heapArr,14);
    lastIndex++;
    insert(heapArr,8);
    lastIndex++;
    insert(heapArr,3);
    lastIndex++;
    insert(heapArr,15);
    lastIndex++;
    insert(heapArr,20);

    printArray(heapArr);
    int a = removeMax(heapArr);
    a = removeMax(heapArr);
    a = removeMax(heapArr);

    printArray(heapArr);


    return 0;
}
