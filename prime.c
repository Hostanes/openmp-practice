#include <stdio.h>

#define MAX_NUM 100000

int isPrime(int x) {
  for (int i = 2; i < x / 2; i++) {
    if (x % i == 0) {
      return 1;
    }
  }
  return 0;
}

void funcA() {

  int prime = 3;
  for (int i = 3; i < MAX_NUM; i++) {
    if (isPrime(i)) {
    }
  }
}


int main(){

  int x[MAX_NUM];

  
  
}
