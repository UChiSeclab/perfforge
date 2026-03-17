#include <bits/stdc++.h>
using namespace std;
long long cuadros(int n, int x, int y, int nivel) {
  int aux = x;
  x = y;
  y = aux;
  y = (n + 1) - y;
  long long sumaArr = 0;
  long long sumaAb = 0;
  int distIzq = x - 1;
  int distDer = n - x;
  int distArr = n - y;
  int distAb = y - 1;
  int cuadrosIzq = nivel;
  int cuadrosDer = nivel;
  if (distIzq < cuadrosIzq) cuadrosIzq = distIzq;
  if (distDer < cuadrosDer) cuadrosDer = distDer;
  for (int i = 0; i < cuadrosDer + 1; i++) {
    int c = nivel - i;
    if (distArr < c)
      sumaArr += 1 + distArr;
    else
      sumaArr += 1 + c;
    if (distAb < c)
      sumaAb += distAb;
    else {
      sumaAb += c;
    }
  }
  for (int i = 1; i < cuadrosIzq + 1; i++) {
    int c = nivel - i;
    if (distArr < c)
      sumaArr += 1 + distArr;
    else
      sumaArr += 1 + c;
    if (distAb < c)
      sumaAb += distAb;
    else {
      sumaAb += c;
    }
  }
  return sumaArr + sumaAb;
}
int main() {
  int n, x, y, limite;
  cin >> n >> x >> y >> limite;
  int izq = 0, der = 10000000, mid;
  while (izq < der) {
    mid = (izq + der) / 2;
    if (limite <= cuadros(n, x, y, mid))
      der = mid;
    else
      izq = mid + 1;
  }
  cout << der << endl;
  return 0;
}
