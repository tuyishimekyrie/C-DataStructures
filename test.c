#include <stdio.h>


void printDataFromArray(int arr[],int size){

for(int i=0;i<size;i++){
    printf("%d",arr[i]);
}
}

int main(){
    int size=5;
    int arr[5] ={1,2,3,4,5};

    printDataFromArray(arr,size);
    return 0;
}