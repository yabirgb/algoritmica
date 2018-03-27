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
// posici�n. Para rellenar el vector de tama�o n, genera todos los
// enteros entre -(n-1) y (n-1) en un vector auxiliar; despu�s obtiene
// una permutaci�n aleatoria de ese vector, se queda con los n
// primeros elementos, y los ordena de forma creciente


double uniforme(){

  //Genera un n�mero uniformemente distribuido en el
  //intervalo [0,1) a partir de uno de los generadores
  //disponibles en C.
  
  int t = rand();
  double f = ((double)RAND_MAX+1.0);
  return (double)t/f;
  
}

int inpos(vector<int> &v){
  
  int min = 0;
  int max = v.size();
  int mid;

  while (min <= max){
    mid = (max+min)/2;
    
    if (v[mid] == mid)
      return mid;
    else if(v[mid] < mid)
      min = mid + 1;
    else if(v[mid] > mid)
      max = mid-1; 
  }

  return -1;
   
}

int conRepetidos(vector<int> &v, int top, int bot){

  
}

int inposOdd(vector<int> v){

  int i;

  for(i = 0; i < v.size(); i++)
    if(v[i] == i)
      return i;

  return -1;
}

int main(int argc, char * argv[]){

  clock_t before, after;

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

  //algoritmo de random shuffling the Knuth (permutaci�n aleatoria) 
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

  /*
  cout << "Vector aleatorio: " << endl;
  for (int j=0; j<n; j++)
    cout << T[j] << " ";

  cout << endl;

  int Q[10] = {2,3,5,22,5,6,1,2,8,1};

  
  cout << "Vector no aleatorio: " << endl;
  for (int j=0; j<n; j++)
    cout << Q[j] << " ";

  cout << endl;
  
  cout << "Resultado del punto fijo: " << inpos(T,0,n) << endl;
  cout << "Resultado del punto fijo: " << inposOdd(T,n) << endl;
  
  */

  //100 millones

  //Y ahora ordeno el vector T
  vector<int> myvector (T, T+n);
  vector<int>::iterator it;

  sort(myvector.begin(),myvector.end());

  before = clock();
  //cout << "DaC: " << inpos(T, 0, n) << endl;
  inpos(myvector);
  after = clock();
  double bueno =  ((double)(after-before))/CLOCKS_PER_SEC;

    
  before = clock();
  //cout << "Lineal: " << inposOdd(T,n) << endl;
  conRepetidos(myvector, myvector.size(), 0 );
  after = clock();
  
  cout << n << "\t" << bueno << "\t" << ((double)(after-before))/CLOCKS_PER_SEC
       << endl;
  
  delete [] aux;
  delete [] T;
  
}
