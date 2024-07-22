#include <stdio.h>

#include "mtbf.h"

void printPoF() {
  printf("--- MTBF Calculator ---\n");
  printf("t = ");
  double t;
  scanf("%lf", &t);
  printf("m = ");
  double m;
  scanf("%lf", &m);
  double p = pof2(t, m);
  printf("F(t) = %.3f%%", p * 100);
}


int main() {
  printPoF();

  return 0;
}