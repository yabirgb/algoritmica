/**
   @file Ordenaci�n por burbuja
*/

   
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>






/* ************************************************************ */ 
/*  M�todo de ordenaci�n por burbuja  */

/**
   @brief Ordena un vector por el m�todo de la burbuja.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: n�mero de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de la burbuja.
*/
inline static 
void burbuja(int T[], int num_elem);



/**
   @brief Ordena parte de un vector por el m�todo de la burbuja.

   @param T: vector de elementos. Tiene un n�mero de elementos 
                   mayor o igual a final.Es MODIFICADO.

   @param inicial: Posici�n que marca el incio de la parte del
                   vector a ordenar.
   @param final: Posici�n detr�s de la �ltima de la parte del
                   vector a ordenar. 
		   inicial < final.

   Cambia el orden de los elementos de T entre las posiciones
   inicial y final - 1de forma que los dispone en sentido creciente
   de menor a mayor.
   Aplica el algoritmo de la burbuja.
*/
static void burbuja_lims(int T[], int inicial, int final);



/**
   Implementaci�n de las funciones
**/

inline void burbuja(int T[], int num_elem)
{
  burbuja_lims(T, 0, num_elem);
};


static void burbuja_lims(int T[], int inicial, int final)
{
  int i, j;
  int aux;
  for (i = inicial; i < final - 1; i++)
    for (j = final - 1; j > i; j--)
      if (T[j] < T[j-1])
	{
	  aux = T[j];
	  T[j] = T[j-1];
	  T[j-1] = aux;
	}
}




int main(int args, char* argv[])
{
  int n;
  //cout << "Introduce n�mero de elementos del vector: ";
  //cin >> n;
  // string to long(string, endptr, base)
  n = strtol(argv[1], NULL, 10);
  
  int * T = new int[n];
  assert(T);

  srandom(time(0));

  for (int i = 0; i < n; i++)
    {
      T[i] = random();
    };

  clock_t tantes = clock();
  burbuja(T, n);
  clock_t tdespues = clock();

  cout << n << "\t" << (double)(tdespues - tantes) / CLOCKS_PER_SEC << endl;
  
  delete [] T;

  return 0;
};
