//This file was given to us by the professor of the subject

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <algorithm>
#include <vector>

using namespace std;

// generador de ejemplos para el problema del elemento en su
// posición. Para rellenar el vector de tamaño n, genera todos los
// enteros entre -(n-1) y (n-1) en un vector auxiliar; después obtiene
// una permutación aleatoria de ese vector, se queda con los n
// primeros elementos, y los ordena de forma creciente


double uniforme(){

  //Genera un número uniformemente distribuido en el
  //intervalo [0,1) a partir de uno de los generadores
  //disponibles en C.
  
  int t = rand();
  double f = ((double)RAND_MAX+1.0);
  return (double)t/f;
  
}

int inpos(int T[], int init, int len){
  int mid = len/2;
  
  if(len != 0){
    if (T[init + mid] == init+mid )
      return init+mid;
    else{
      int below = inpos(T, init, mid);
      int up = inpos(T, init + mid+1, len - mid-1);

      if(below != -1)
	return below;
      if (up != -1)
	return up;	  
    }
  }

  return -1;
}

int main(int argc, char * argv[]){

  if (argc != 2){
    cerr << "Formato " << argv[0] << " <num_elem>" << endl;
    return -1;
  }

  int n = atoi(argv[1]);
  int m=2*n-1;

  int * T = new int[n];
  assert(T);
  int * aux = new int[m];
  assert(aux);

  srand(time(0));
  //genero todos los enteros entre -(n-1) y n-1
  for (int j=0; j<m; j++)
    aux[j]=j-(n-1);

  //algoritmo de random shuffling the Knuth (permutación aleatoria) 
  for (int j=m-1; j>0; j--) {
    double u=uniforme();
    int k=(int)(j*u);
    int tmp=aux[j];
    aux[j]=aux[k];
    aux[k]=tmp;
  }

  //me quedo con los n primeros del vector
  for (int j=0; j<n; j++)
    T[j]=aux[j];

  
  cout << "Vector aleatorio: " << endl;
  for (int j=0; j<n; j++)
    cout << T[j] << " ";

  cout << endl;

  int Q[10] = {2,3,5,22,5,6,1,2,8,1};

  /*
  cout << "Vector no aleatorio: " << endl;
  for (int j=0; j<n; j++)
    cout << Q[j] << " ";

  cout << endl;
  */
  cout << "Resultado del punto fijo: " << inpos(T,0,n) << endl;
  delete [] aux;
  delete [] T;
  
}
