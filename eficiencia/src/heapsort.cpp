/**
   @file Ordenaci�n por montones
*/

   
#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>






/* ************************************************************ */ 
/*  M�todo de ordenaci�n por montones  */

/**
   @brief Ordena un vector por el m�todo de montones.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: n�mero de elementos. num_elem > 0.

   Cambia el orden de los elementos de T de forma que los dispone
   en sentido creciente de menor a mayor.
   Aplica el algoritmo de ordenaci�n por montones.
*/
inline static 
void heapsort(int T[], int num_elem);



/**
   @brief Reajusta parte de un vector para que sea un mont�n.

   @param T: vector de elementos. Debe tener num_elem elementos.
             Es MODIFICADO.
   @param num_elem: n�mero de elementos. num_elem > 0.
   @param k: �ndice del elemento que se toma com ra�z
   
   Reajusta los elementos entre las posiciones k y num_elem - 1 
   de T para que cumpla la propiedad de un mont�n (APO), 
   considerando al elemento en la posici�n k como la ra�z.
*/
static void reajustar(int T[], int num_elem, int k);




/**
   Implementaci�n de las funciones
**/


static void heapsort(int T[], int num_elem)
{
  int i;
  for (i = num_elem/2; i >= 0; i--)
    reajustar(T, num_elem, i);
  for (i = num_elem - 1; i >= 1; i--)
    {
      int aux = T[0];
      T[0] = T[i];
      T[i] = aux;
      reajustar(T, i, 0);
    }
}
  

static void reajustar(int T[], int num_elem, int k)
{
  int j;
  int v;
  v = T[k];
  bool esAPO = false;
  while ((k < num_elem/2) && !esAPO)
    {
      j = k + k + 1;
      if ((j < (num_elem - 1)) && (T[j] < T[j+1]))
	j++;
      if (v >= T[j])
	esAPO = true;
      T[k] = T[j];
      k = j;
    }
  T[k] = v;
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

  // escribe_vector(T, n);

  
  clock_t tantes = clock();
  heapsort(T, n);
  clock_t tdespues = clock();

  // escribe_vector(T, n);

  cout << n << "\t" << (double)(tdespues - tantes) / CLOCKS_PER_SEC << endl;
  
  delete [] T;

  return 0;
};
