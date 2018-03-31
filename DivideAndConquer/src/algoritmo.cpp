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

  if (bot > top)
    return -1;

  int mid = (top+bot)/2;
  int midv = v[mid];

  if (midv == mid)
    return mid;

  int lefti = min(mid-1, midv);
  int left  = conRepetidos(v, lefti, bot);

  if (left != -1)
    return left;

  int righti = max(mid+1, midv);
  int right = conRepetidos(v, bot, top);

  return right;
      
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
  int n = 5;

  vector<int> Q ({2,0,3,5,7});
  sort(Q.begin(),Q.end());
  cout << "Vector no aleatorio: " << endl;
  for (int j=0; j<Q.size(); j++)
    cout << Q[j] << " ";

  cout << endl;
  
  cout << "Resultado del punto fijo: " << inpos(Q) << endl;
  cout << "Resultado del punto fijo: " << inposOdd(Q) << endl;

  vector<int> P ({6,8,3,5,7});
  sort(P.begin(),P.end());
  cout << "Vector no aleatorio: " << endl;
  for (int j=0; j<P.size(); j++)
    cout << P[j] << " ";

  cout << endl;
  
  cout << "Resultado del punto fijo: " << inpos(P) << endl;
  cout << "Resultado del punto fijo: " << inposOdd(P) << endl;


  vector<int> R ({0,1,3,5,7});
  sort(R.begin(),R.end());
  cout << "Vector no aleatorio: " << endl;
  for (int j=0; j<R.size(); j++)
    cout << R[j] << " ";

  cout << endl;
  
  cout << "Resultado del punto fijo: " << inpos(R) << endl;
  cout << "Resultado del punto fijo: " << inposOdd(R) << endl;


  vector<int> S ({0,0,1,3,5,7});
  sort(S.begin(),S.end());
  cout << "Vector no aleatorio: " << endl;
  for (int j=0; j<S.size(); j++)
    cout << S[j] << " ";

  cout << endl;
  
  cout << "Resultado del punto fijo: " << inpos(S) << endl;
  cout << "Resultado del punto fijo: " << inposOdd(S) << endl;

  vector<int> Ss ({-1,-2,3,3,5,5,7});
  sort(Ss.begin(),Ss.end());
  cout << "Vector no aleatorio: " << endl;
  for (int j=0; j<Ss.size(); j++)
    cout << Ss[j] << " ";

  cout << endl;
  
  cout << "Resultado del punto fijo: " << inpos(Ss) << endl;
  cout << "Resultado del punto fijo: " << inposOdd(Ss) << endl;

  vector<int> M ({0,0,1,4,5});
  sort(M.begin(),M.end());
  cout << "Vector no aleatorio: " << endl;
  for (int j=0; j<M.size(); j++)
    cout << M[j] << " ";

  cout << endl;
  
  cout << "Resultado del punto fijo: " << inpos(M) << endl;
  cout << "Resultado del punto fijo(TOCHO): " << conRepetidos(M, M.size(), 0) << endl;
  cout << "Resultado del punto fijo: " << inposOdd(M) << endl;


  vector<int> B ({0,6,1,4,5});
  sort(B.begin(),B.end());
  cout << "Vector no aleatorio: " << endl;
  for (int j=0; j<B.size(); j++)
    cout << B[j] << " ";

  cout << endl;
  
  cout << "Resultado del punto fijo: " << inpos(B) << endl;
  cout << "Resultado del punto fijo(TOCHO): " << conRepetidos(B, B.size(), 0) << endl;
  cout << "Resultado del punto fijo: " << inposOdd(B) << endl;

  
}
