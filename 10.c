// Rozk³ad LU
// raz  dwa trzy
// Data: 30.04.2010
// (C)2012 mgr Jerzy Wa³aszek
//-----------------------------

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double eps = 1e-12;

// Funkcja realizuje algorytm rozk³adu LU
//---------------------------------------
bool lu(int n, double ** A)
{
  int i,j,k;

  for(k = 0; k < n - 1; k++)
  {
    if(fabs(A[k][k]) < eps) return false;
    for(i = k + 1; i < n; i++)
      A[i][k] /= A[k][k];
    for(i = k + 1; i < n; i++)
      for(j = k + 1; j < n; j++)
        A[i][j] -= A[i][k] * A[k][j];
  }
  return true;
}

// Program g³ówny

int main()
{
  double **A;
  int n,i,j;
  
  cout << setprecision(3) << fixed;
  
  // odczytujemy stopieñ macierzy A

  cin >> n;

  // tworzymy macierz A o odpowiednich rozmiarach

  A = new double * [n];
  for(i = 0; i < n; i++) A[i] = new double [n];

  // odczytujemy dane dla macierzy A

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) cin >> A[i][j];

  // wyznaczamy rozk³ad LU macierzy A

  if(lu(n,A))
    for(i = 0; i < n; i++)
    {
      for(j = 0; j < n; j++)
        cout << setw(8) << A[i][j] << " ";
      cout << endl;
    }
  else
    cout << "DZIELNIK ZERO\n";

  // usuwamy macierz z pamiêci

  for(i = 0; i < n; i++) delete [] A[i];
  delete [] A;

  return 0;
} 
