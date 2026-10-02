// Sparse Matrix and its operations

#include <stdio.h>

void Mat_accept(int Mat[20][20], int r, int c);
void Mat_display(int Mat[20][20], int r, int c);
void compact_gen(int Mat[20][20], int r, int c, int cp[20][3]);
void simple_transpose(int cp[20][3], int tp[20][3]);
void fast_transpose(int cp[20][3], int tp[20][3]);

int main() {
   int Mat[20][20];
   int r,c;
   int cp[20][3];
   int tp_simple[20][3];
   int tp_fast[20][3];
   
  printf("Enter rows and cols: ");
  scanf("%d %d", &r, &c);
  Mat_accept(Mat, r, c);
  printf("\nMatrix: \n");
  Mat_display(Mat, r, c);
  printf("\n");

  printf("Compact Matrix: \n");
  compact_gen(Mat, r, c, cp);
  Mat_display(cp, cp[0][2] + 1, 3);
  printf("\n");

  printf("Simple Transpose of Compact Matrix: \n");
  simple_transpose(cp, tp_simple);
  Mat_display(tp_simple, tp_simple[0][2] + 1, 3);
  printf("\n");

  printf("Fast Transpose of Compact Matrix: \n");
  fast_transpose(cp, tp_fast);
  Mat_display(tp_fast, tp_fast[0][2] + 1, 3);
  printf("\n");

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

void compact_gen(int Mat[20][20], int r, int c, int cp[20][3]) {
   	int k=1;
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++) {
			if (Mat[i][j] != 0) {
				cp[k][0] = i;
				cp[k][1] = j;
				cp[k][2] = Mat[i][j];
                k++;
			}
		}
	}
	cp[0][0] = r;
	cp[0][1] = c;
	cp[0][2] = k-1;
}
				
void simple_transpose(int cp[20][3], int tp[20][3]) {
	int k=1;
	for(int i=0; i<cp[0][1]; i++) {
		for(int j=1; j<=cp[0][2]; j++) {
			if(i == cp[j][1]) {
				tp[k][0] = cp[j][1];
				tp[k][1] = cp[j][0];
				tp[k][2] = cp[j][2];
                k++;
			}
		}
	}
    tp[0][0] = cp[0][1];
	tp[0][1] = cp[0][0];
	tp[0][2] = cp[0][2];
}

void fast_transpose(int cp[20][3], int tp[20][3]) {
    int rterm[20], rpos[20];
    int i, j;
    for(i=0; i<cp[0][1]; i++) {
        rterm[i] = 0;
    }
    for(i=1; i<cp[0][2]; i++) {
        rterm[cp[i][1]]++;
    }
    rpos[0] = 1;
    for(i=1; i<cp[0][1]; i++) {
        rpos[i] = rterm[i-1] + rpos[i-1];
    }
    for(i=1; i<=cp[0][2]; i++) {
        int loc = rpos[cp[i][1]];
        tp[loc][0] = cp[i][1];
        tp[loc][1] = cp[i][0];
        tp[loc][2] = cp[i][2];
        rpos[cp[i][1]]++;
    }
    tp[0][0] = cp[0][1];
    tp[0][1] = cp[0][0];
    tp[0][2] = cp[0][2];
}