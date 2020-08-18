#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include "quicksort.h"
#include "quicksort.c"

void PrintArray(int* array, int size) {
  printf("     ");
  int i;
  for (i = 0; i < size; i ++) {
    printf("%d   ", array[i]);
    }
  printf("\n");
}

void printResult(double result[]) {
  int i;
  for (i = 0; i < 6; i ++) {
    printf("%.2lf   ", result[i]);
    }
  printf("\n");
}
int* make_elem() {
  int* num_elems = (int*)malloc(sizeof(int) * 6);
  num_elems[0] = 16384;
  num_elems[1] = 32768;
  num_elems[2] = 65536;
  num_elems[3] = 131072;
  num_elems[4] = 262144;
  num_elems[5] = 524288;
  return num_elems;
}
int main_fun() {
  double result_time[6]; 
  int j;
  int* num_elems = make_elem();
  for (j = 0; j < 6; j++) {

  int* integers = (int*)malloc(sizeof(int) * num_elems[j]);

  time_t t;
  srand((unsigned)time(&t));

  int i;
  for (i = 0; i < num_elems[j]; i ++) {
    integers[i] = (rand() % 90) + 10;
  }
  clock_t start, end;
  start = clock();
  Quicksort(integers, 0, num_elems[j]-1);
  end = clock();
  double time_taken = ((double) (end - start))/CLOCKS_PER_SEC;
  result_time[j] = time_taken;
}
printf("Alg A: ");
printResult(result_time);
}

int main_shuffle() {
  int* num_elems = make_elem();
  double result_time_shuffle[6]; 
  int j;
  for (j = 0; j <6; j++) {
    
    int* integers = (int*)malloc(sizeof(int) * num_elems[j]);
    
    time_t t;
    srand((unsigned)time(&t));

    int swapper = 0;
    int i;
    for (i =0; i<num_elems[j]; i++) {
      integers[i] = (rand() % 90) + 10;
    }
    int temp;
    for (i = 0 ; i < num_elems[j]; i++) {
      swapper = rand()% num_elems[j];
      temp = integers[i];
      integers[i] = integers[swapper];
      integers[swapper] = temp;
    }
   clock_t start, end;
  start = clock();
  Quicksort(integers, 0, num_elems[j]-1);
  end = clock();
  double time_taken = ((double) (end - start))/CLOCKS_PER_SEC;
  result_time_shuffle[j] = time_taken;
  }
  printf("Alg B: ");
  printResult(result_time_shuffle);
}

int main_midle() {
  int* num_elems = make_elem();
  double result_time_midle[6]; 

  int j;
  for (j = 0; j <6; j++) {

    int* integers = (int*)malloc(sizeof(int) * num_elems[j]);

    time_t t;
    srand((unsigned)time(&t));
    int i;
  for (i = 0; i < num_elems[j]; i ++) {
    integers[i] = (rand() % 90) + 10;
  }
  clock_t start, end;
  start = clock();
  Quicksort_midle(integers, 0, num_elems[j]-1);
  end = clock();
  double time_taken = ((double) (end - start))/CLOCKS_PER_SEC;
  result_time_midle[j] = time_taken;
  }
  printf("Alg C: ");
  printResult(result_time_midle);
}

int main_insert(){
  int* num_elems = make_elem();
  double result_time_insert[6];

  int j;
  for (j = 0; j <6; j++) {

    int* integers = (int*)malloc(sizeof(int) * num_elems[j]);

    time_t t;
    srand((unsigned)time(&t));
    int i;
  for (i = 0; i < num_elems[j]; i ++) {
    integers[i] = (rand() % 90) + 10;
  }
  clock_t start, end;
  start = clock();
  quick_insert_sort(integers, 0, num_elems[j]-1);
  end = clock();
  double time_taken = ((double) (end - start))/CLOCKS_PER_SEC;
  result_time_insert[j] = time_taken;
  }
  printf("Alg D: ");
  printResult(result_time_insert);
  }
int main(int argc, char* argv[]) {
  int* num_elems = make_elem();
  PrintArray(num_elems, 6);
  printf("-------------------------------------------------------\n");
  if (strcmp(argv[1], "sort-a") == 0) {
    main_fun();
  }
  else if (strcmp(argv[1], "sort-b") == 0) {
    main_shuffle();
  }
  else if (strcmp(argv[1], "sort-abd") == 0) {
    main_fun();
    main_shuffle();
    main_insert();
  }
   else if (strcmp(argv[1], "sort-all") == 0) {
    main_fun();
    main_shuffle();
    main_midle();
    main_insert();
  }
}

