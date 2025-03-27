#include <stdio.h>
#include <stdlib.h>

/*
    calculate dot product b.c=a
*/
void mxv(int m, int n, double *a, double *b, double *c) {
  int i, j;

#pragma omp parallel for default(none) shared(m, n, a, b, c) private(i, j)
  for (i = 0; i < m; i++)

  {
    a[i] = 0.0;
    for (j = 0; j < n; j++)
      a[i] += b[i * n + j] * c[j];

  } /*-- End of omp parallel for --*/
}

void serial_mxv(int m, int n, double *a, double *b, double *c) {
  int i, j;

#pragma omp parallel for default(none) shared(m, n, a, b, c) private(i, j)
  for (i = 0; i < m; i++)

  {
    a[i] = 0.0;
    for (j = 0; j < n; j++)
      a[i] += b[i * n + j] * c[j];

  } /*-- End of omp parallel for --*/
}

int main(int argc, char *argv[]) {
  double *a, *b, *c, *d;
  int i, j, m, n;

  printf("Please give m and n: ");
  scanf("%d %d", &m, &n);

  if ((a = (double *)malloc(m * sizeof(double))) == NULL)
    perror("memory allocation for a");
  if ((d = (double *)malloc(m * sizeof(double))) == NULL)
    perror("memory allocation for d");
  if ((b = (double *)malloc(m * n * sizeof(double))) == NULL)
    perror("memory allocation for b");
  if ((c = (double *)malloc(n * sizeof(double))) == NULL)
    perror("memory allocation for c");

  printf("Initializing matrix B and vector c\n");
  for (j = 0; j < n; j++)
    c[j] = 2.0;
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      b[i * n + j] = i + 1;

  /*    for (i = 0; i < n; i++)
          printf("c[%d]=%f, ", i, c[i]);
      for (i = 0; i < n*m; i++)
          printf("b[%d]=%d, ", i, b[i]);*/
  printf("Executing mxv function for m = %d n = %d\n", m, n);
  (void)mxv(m, n, a, b, c);

  printf("Executing mxv function for m = %d n = %d\n", m, n);
  (void)mxv(m, n, d, b, c);

  for (i = 0; i < m; i++)
    printf("a[%d] - d[%d] = %.2f, \n", i, i, a[i] - d[i]);
  free(a);
  free(b);
  free(c);
  return (0);
}
