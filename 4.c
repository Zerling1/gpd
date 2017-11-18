// Transponowanie macierzy kwadratowej
// Data: 11.01.2010
// (C)2012 mgr Jerzy Wa�aszek
//-----------------------------

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

main()
{
  int **A,n,i,j,t;

  srand((unsigned)time(NULL));

  // losujemy stopie� macierzy

  n = rand() % 7 + 2;

  // tworzymy tablic� wska�nik�w

   A = new int * [n];

  // tworzymy tablice wierszy

  for(i = 0; i < n; i++) A[i] = new int[n];

  // wype�niamy macierz A losowymi liczbami

  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++) A[i][j] = rand() % 199 - 99;

  // wy�wietlamy macierz A

  cout << "n = " << n << endl << endl
       << "Matrix A:" << endl;

  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++) cout << setw(5) << A[i][j];
    cout << endl;
  }
  
  // transponujemy macierz A
  
  for(i = 0; i < n - 1; i++)
    for(j = i + 1; j < n; j++)
    {
      t = A[i][j];
      A[i][j] = A[j][i];
      A[j][i] = t;
    }

  // wy�wietlamy macierz A

  cout << endl << "Matrix AT:" << endl;
  
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < n; j++) cout << setw(5) << A[i][j];
    cout << endl;
  }

  // koniec, zwalniamy pami�� zaj�t� przez macierz

  for(i = 0; i < n; i++) delete [] A[i];
  delete [] A;
} 