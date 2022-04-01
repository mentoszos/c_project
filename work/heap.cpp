#include<iostream>
using namespace std;

void shiftUp(int heap[],int count){
    while (count>0&&heap[(count-1)/2]<heap[count])
    {
        int temp = heap[(count-1)/2];
        heap[(count-1)/2] = heap[count];
        heap[count] = temp;
        count = (count-1)/2;
    }
    
}
void addElement(int heap[],int count, int element){
    heap[++count] = element;
    shiftUp(heap,count);
}


void shiftDown(int heap[],int count, int k){
    while (2*k+1<=count)
    {
        int j = 2*k+1;
        if (j+1<=count && heap[j+1]>heap[j])
        {
            /* code */j++;
        }
        if (heap[k]>=heap[j])
        {
            /* code */break;
        }
        else{
            int temp = heap[k]; heap[k] = heap[j]; heap[j] = temp;
            k=j;
        }
        
        
    }
    
}
void createHeap(int heap[], int len){
   int count = len-1;
   for(int i = (len-1-1)/2;i>=0;i--){
       shiftDown(heap,count,i);
   }
}

void sort(int heap[],int len){
    int count = len-1;
    while (count>0)
    {
        int temp = heap[0];
        heap[0] = heap[count];
        heap[count] = temp;
        count--;
        shiftDown(heap,count,0);
    }
    
}
