// Dodawanie macierzy
// Data: 7.01.2010
// uttautjsafjaojfijfiojafao
// (C)2012 mgr Jerzy Wa³aszek
//-----------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
  int **A,**B,**C,n,m,iw,ik;

  srand((unsigned)time(NULL));

  // losujemy wymiary macierzy

  m = rand() % 5 + 2;
  n = rand() % 5 + 2;

  // tworzymy tablicê wskaŸników

   A = new int * [m];
   B = new int * [m];
   C = new int * [m];

  // tworzymy tablice wierszy

  for(iw = 0; iw < m; iw++)
  {
    A[iw] = new int[n];
    B[iw] = new int[n];
    C[iw] = new int[n];
  }

  // wype³niamy macierze A i B losowymi liczbami

  for(iw = 0; iw < m; iw++)
    for(ik = 0; ik < n; ik++)
    {
      A[iw][ik] = rand() % 100;
      B[iw][ik] = rand() % 100;
    }

  // wyœwietlamy macierze A i B

  cout << "m = " << m << endl
       << "n = " << n << endl << endl
       << "Matrix A:" << endl;

  for(iw = 0; iw < m; iw++)
  {
    for(ik = 0; ik < n; ik++)
      cout << setw(5) << A[iw][ik];
    cout << endl;
  }
  
  cout << endl << "Matrix B:" << endl;

  for(iw = 0; iw < m; iw++)
  {
    for(ik = 0; ik < n; ik++)
      cout << setw(5) << B[iw][ik];
    cout << endl;
  }

  // sumujemy macierz A i B w C
  
  for(iw = 0; iw < m; iw++)
    for(ik = 0; ik < n; ik++)
      C[iw][ik] = A[iw][ik] + B[iw][ik];

  // wyœwietlamy macierz wynikow¹

  cout << endl << "Matrix C = A + B:" << endl;
  
  for(iw = 0; iw < m; iw++)
  {
    for(ik = 0; ik < n; ik++)
      cout << setw(5) << C[iw][ik];
    cout << endl;
  }

  // koniec, zwalniamy pamiêæ zajêt¹ przez macierze

  for(iw = 0; iw < m; iw++)
  {
    delete [] A[iw];
    delete [] B[iw];
    delete [] C[iw];
  }
  delete [] A;
  delete [] B;
  delete [] C;

  return 0;
} 
