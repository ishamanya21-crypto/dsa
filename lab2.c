#include <stdio.h>
struct Sparse {
int row, col, value;
};
void main()
{
struct Sparse A[20], B[20], C[40], T[20];
int n1, n2, i, j, k = 0, t = 0;
int rows, cols;

printf("Enter number of rows and columns: ");
scanf("%d%d", &rows, &cols);

printf("Enter number of non-zero elements in A: ");
scanf("%d", &n1);

printf("Enter Matrix A in sorted order (row column value):\n");
for (i = 0; i < n1; i++)
scanf("%d%d%d", &A[i].row, &A[i].col,&A[i].value);

printf("Enter number of non-zero elements in B: ");
scanf("%d", &n2);

printf("Enter Matrix B in sorted order(row column value):\n");
for (i = 0; i < n2; i++)
scanf("%d%d%d", &B[i].row, &B[i].col,&B[i].value);

// Addition of sparse matrices
i = 0;
j = 0;

while (i < n1 && j < n2) {
if (A[i].row == B[j].row &&
A[i].col == B[j].col) {

int sum = A[i].value + B[j].value;

if (sum != 0) {
C[k] = A[i];
C[k].value = sum;
k++;
}
i++;
j++;
}
else if (A[i].row < B[j].row ||
(A[i].row == B[j].row &&
A[i].col < B[j].col)) {
C[k++] = A[i++];
}
else {
C[k++] = B[j++];
}
}

while (i < n1)
C[k++] = A[i++];

while (j < n2)
C[k++] = B[j++];

printf("\nAddition:\nRow Col Value\n");
for (i = 0; i < k; i++)
printf("%d %d %d\n",
C[i].row, C[i].col, C[i].value);

// Transpose of Matrix A
for (j = 0; j < cols; j++) {
for (i = 0; i < n1; i++) {
if (A[i].col == j) {
T[t].row = A[i].col;
T[t].col = A[i].row;
T[t].value = A[i].value;
t++;
}
}
}

printf("\nTranspose of Matrix A:\n");
printf("Row Col Value\n");

for (i = 0; i < t; i++)
printf("%d %d %d\n",
T[i].row, T[i].col, T[i].value);

}
