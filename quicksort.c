#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "quicksort.h"

void Swap(int* array, int first, int second) {
  int temp = array[first];
  array[first] = array[second];
  array[second] = temp;
}
int Partition_regular(int* data, int low, int high) {
  int pivot = data[low];
  int leftwall = low;
  int i;
  for (i = low + 1; i <= high; i ++) {
    if (data[i] < pivot) {
      leftwall ++;
      Swap(data, i, leftwall);
      }
    }
  Swap(data, low, leftwall);
  return leftwall;
  
}
void Quicksort(int* data, int low, int high) {
  if (low < high) {
  int pivot_location = Partition_regular(data, low, high);
  Quicksort(data, low, pivot_location);
  Quicksort(data, pivot_location+1, high); }
}

int Partition_middle(int* data, int low, int high) { 
  int midpoint = low + (high - low) / 2;
  int pivot = data[midpoint];

  int l = low;
  int h = high;

  int done = false;

  while (!done) {
    while (data[l] < pivot) {
    	++l;
    }
    while (pivot < data[h]) {
      --h;
    }

    if (l >= h) {
      done = true;
    } else {
      Swap (data, data[l], data[h]);
       ++l;
      --h;
         }
       }
       return h;
       }

void Quicksort_midle(int* data, int low, int high) {
  if (low < high) {
  int pivot_location = Partition_regular(data, low, high);
  Quicksort_midle(data, low, pivot_location);
  Quicksort_midle(data, pivot_location+1, high); }
}

void InsertionSort(int* data, int size) {
  int i;
  int j;
  for (i=1; i<size; ++i) {
    j = i;
  
  while(j > 0 && data[j] < data[j-1]) {
    Swap(data, data[j], data[j-1]);
    --j;
    }
  }
}
void quick_insert_sort(int* data, int low, int high) {
  if (low < high) {
    int pivot_location = Partition_regular(data, low, high);
    Quicksort_midle(data, low, pivot_location);
    Quicksort_midle(data, pivot_location+1, high);}
  if ((int)sizeof(data) < 16) {
    InsertionSort(data, (int)sizeof(data));
  }
}
