#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int Partition_regular(int* data, int low, int high);

void Quicksort(int* data, int low, int high);

int Partition_middle(int* data, int low, int high);

void Quicksort_midle(int* data, int low, int high);

void InsertionSort(int* data, int size);

void quick_insert_sort(int* data, int low, int high);
