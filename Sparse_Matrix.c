// Sparse Matrix and its operations

#include <stdio.h>

void Mat_accept(int Mat[20][20], int r, int c);
void Mat_display(int Mat[20][20], int r, int c);
void compact_gen(int Mat[20][20], int r, int c, int cp[20][3]);
void simple_transpose(int Mat[20][20], int r, int c, int cp[20][3], int tp[20][3]);

int main() {
   int Mat[20][20];
   int r,c;
   int cp[20][3];
   int tp[20][3];
   
  printf("Enter rows and cols: ");
  scanf("%d %d", &r, &c);
  Mat_accept(Mat, r, c);
  printf("\nMatrix: \n");
  Mat_display(Mat, r, c);
  printf("Compact Matrix: \n");
  compact_gen(Mat, r, c, cp);
  Mat_display(cp, cp[0][2] + 1, 3);
  printf("Transpose of Compact Matrix: ");
  simple_transpose(Mat, r, c, cp, tp);
  Mat_display(tp, tp[0][2] + 1, 3);

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
				
void simple_transpose(int Mat[20][20], int r, int c, int cp[20][3], int tp[20][3]) {
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