// Basic operations of Matrices.
#include <stdio.h>

void Mat_accept(int Mat[20][20], int r, int c);
void Mat_display(int Mat[20][20], int r, int c);
void Mat_add(int Mat1[20][20], int Mat2[20][20], int Result[20][20], int r, int c);
void Mat_sub(int Mat1[20][20], int Mat2[20][20], int Result[20][20], int r, int c);
void Mat_mul(int Mat1[20][20], int Mat2[20][20], int Result[20][20], int r1, int r2, int c1, int c2);
void Mat_Transpose(int Mat[20][20], int Result[20][20], int r, int c);

int main() {
    int Mat1[20][20], Mat2[20][20];
    int Result[20][20];
    int r1, c1, r2, c2;
    int choice;
    
    printf("1. Matrix Addition\n");
    printf("2. Matrix Subtraction\n");
    printf("3. Matrix Multiplication\n");
    printf("4. Matrix Transpose\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 4) {
        printf("\nInvalid Choice!\n");
        return 1;
    }
    
    printf("Enter rows and columns of Matrix 1: ");
    scanf("%d %d", &r1, &c1);
    Mat_accept(Mat1, r1, c1);
    printf("\nMatrix 1: \n");
    Mat_display(Mat1, r1, c1);

    printf("Enter rows and columns of Matrix 2: ");
    scanf("%d %d", &r2, &c2);
    Mat_accept(Mat2, r2, c2);
    printf("\nMatrix 2: \n");
    Mat_display(Mat2, r2, c2);
    
    switch (choice) {
        case 1:
            if (r1 == r2 && c1 == c2) {
                Mat_add(Mat1, Mat2, Result, r1, c1);
                printf("\nResult of Matrix Addition:\n");
                Mat_display(Result, r1, c1);
            }
            else {
                printf("\nError, Matrix Addition not possible.\n");
            }
            break;
            
        case 2:
            if (r1 == r2 && c1 == c2) {
                Mat_sub(Mat1, Mat2, Result, r1, c1);
                printf("\nResult of Matrix Subtraction:\n");
                Mat_display(Result, r1, c1);
            }
            else {
                printf("\nError: Matrix Subtraction impossible!\n");
            }
            break;
            
        case 3:
            if (c1 == r2) {
                Mat_mul(Mat1, Mat2, Result, r1, r2, c1, c2);
                printf("\nResult of Matrix Multiplication:\n");
                Mat_display(Result, r1, c2);
            }
            else {
                printf("\nError: Matrix multiplication impossible!\n");
            }
            break;

        case 4:
            Mat_Transpose(Mat1, Result, r1, c1);
            printf("\nTranspose of Matrix 1:\n");
            Mat_display(Result, c1, r1);
            break;
    }
    
    return 0;
}

void Mat_accept(int Mat[20][20], int r, int c) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++){
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &Mat[i][j]);
        }
    }
}

void Mat_display(int Mat[20][20], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", Mat[i][j]);
        }
        printf("\n");
    }
}

void Mat_add(int Mat1[20][20], int Mat2[20][20], int Result[20][20], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            Result[i][j] = Mat1[i][j] + Mat2[i][j];
        }
    }
}

void Mat_sub(int Mat1[20][20], int Mat2[20][20], int Result[20][20], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            Result[i][j] = Mat1[i][j] - Mat2[i][j];
        }
    }
}

void Mat_mul(int Mat1[20][20], int Mat2[20][20], int Result[20][20], int r1, int r2, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            Result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                Result[i][j] += Mat1[i][k] * Mat2[k][j];
            }
        }
    }
}

void Mat_Transpose(int Mat[20][20], int Result[20][20], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            Result[j][i] = Mat[i][j];
        }
    }
}