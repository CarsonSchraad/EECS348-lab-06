#include <stdio.h>
#include <stdlib.h> // For exit function in error handling

#define SIZE 5

// Function prototypes
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]);
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);

int main() {
    // Sample matrices can be changed for future tests
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    // Define the matricies that will be returned later
    int sum[SIZE][SIZE], product[SIZE][SIZE], transpose[SIZE][SIZE];

    // Perform operations
    addMatrices(m1, m2, sum);
    multiplyMatrices(m1, m2, product);
    transposeMatrix(m1, transpose);

    // Print results
    printf("Matrix 1:\n");
    printMatrix(m1);
    printf("Matrix 2:\n");
    printMatrix(m2);

    printf("\nSum of Matrices:\n");
    printMatrix(sum);

    printf("\nProduct of Matrices:\n");
    printMatrix(product);

    printf("\nTranspose of Matrix 1:\n");
    printMatrix(transpose);

    return 0;
}

// Function to add two matrices
void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE], int result[SIZE][SIZE]) {
    // Initialize the result matrix (filled with zeros)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
        }
    }

    // Function for matrix multiplication
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Function to transpose a matrix
void transposeMatrix(int matrix[SIZE][SIZE], int result[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}
