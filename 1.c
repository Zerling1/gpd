// Mno¿enie macierzy przez skalar

// Data: 6.01.2010
// wiecej commitow

// dodam cos tutaj
// Data: 6.01.2010

// (C)2012 mgr Jerzy Wa³aszek
//-----------------------------
//fffffff
// huhhhh8jjhjhugtu
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
  int ** A,c,n,m,iw,ik;

  srand((unsigned)time(NULL));

  // losujemy wymiary macierzy

  m = rand() % 8 + 2;
  n = rand() % 8 + 2;

  // tworzymy tablicê wskaŸników

   A = new int * [m];

  // tworzymy tablice wierszy

  for(iw = 0; iw < m; iw++) A[iw] = new int[n];

  // wype³niamy macierz losowymi liczbami

  for(iw = 0; iw < m; iw++)
    for(ik = 0; ik < n; ik++) A[iw][ik] = rand() % 100;

  // losujemy skalar c

  c = rand() % 21 - 10;

  // wyœwietlamy macierz

  cout << "m = " << m << endl
       << "n = " << n << endl << endl;

  for(iw = 0; iw < m; iw++)
  {
    for(ik = 0; ik < n; ik++)
      cout << setw(5) << A[iw][ik];
    cout << endl;
  }

  // wyœwietlamy skalar

  cout << endl << "c = " << c << endl << endl;

  // mno¿ymy macierz przez skalar

  for(iw = 0; iw < m; iw++)
    for(ik = 0; ik < n; ik++) A[iw][ik] *= c;

  // wyœwietlamy macierz wynikow¹

  for(iw = 0; iw < m; iw++)
  {
    for(ik = 0; ik < n; ik++)
      cout << setw(5) << A[iw][ik];
    cout << endl;
  }

  // koniec, zwalniamy pamiêæ zajêt¹ przez macierz

  for(iw = 0; iw < m; iw++) delete [] A[iw];
  delete [] A;

  return 0;
} 
