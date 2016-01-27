#include <stdio.h>
#include "l20b.c"

#define ARRAY_HEIGHT 4
#define ARRAY_WIDTH 4
#define ARRAY_SUM_MAX 10

int sudoku[ARRAY_HEIGHT][ARRAY_WIDTH];

// Generate the array
void readArray() {
  for (int row = 0; row < ARRAY_HEIGHT; row++) {
    for (int column = 0; column < ARRAY_WIDTH; column++) {
      printf("Requesting element [%d][%d]:\n", row, column);
      printf("Enter an integer:\n");
      sudoku[row][column] = getInt();
    }
  }
}

// loop and print out each "cell"
void printArray() {
  for (int row = 0; row < ARRAY_HEIGHT; row++) {
    for (int column = 0; column < ARRAY_WIDTH; column++) {
      printf("%d\t", sudoku[row][column]);
    }
    printf("\n");
  }
}

// count each row, and then count each column and if they're not equal to 10, print error msg
void checkArray() {
  int sumRow;
  int sumColumn;
  
  for (int row = 0; row < ARRAY_HEIGHT; row++) {
    sumRow = 0;
    for (int column = 0; column < ARRAY_WIDTH; column++) {
      sumRow += sudoku[row][column];
    }
    if (sumRow != ARRAY_SUM_MAX) {
      printf("Row %d adds up to %d not %d\n", row, sumRow, ARRAY_SUM_MAX);
    }
  }

  for (int column = 0; column < ARRAY_HEIGHT; column++) {
    sumColumn = 0;
    for (int row = 0; row < ARRAY_WIDTH; row++) {
      sumColumn += sudoku[row][column];
    }
    if (sumColumn != ARRAY_SUM_MAX) {
      printf("Column %d adds up to %d not %d\n", column, sumColumn, ARRAY_SUM_MAX);
    }
  }
}

int main() {
  readArray();
  printArray();
  checkArray();
  return 0;
}