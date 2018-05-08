#include <iostream>
#include <vector>
#include <random>

using namespace std;

void printMatrix(vector<vector<int> > matrix){
  for(int i=0; i < matrix.size(); i++){
    for(int j=0; j < matrix[i].size(); j++){
      printf(" %d", matrix[i][j]);
    }
    cout << endl;
  }
}

template <typename T>
void printVector(vector<T> v){

  cout << "[";
  for(int i =0; i < v.size()-1; i++){
    cout << v[i] << ",";
  }

  cout << v[v.size()-1];

  cout << "]";
}


int calcularAfinidad(vector<int> &solucion, vector<vector<int>> &afinidades){
  int afinidad = 0;
  for(int i = 1; i < solucion.size()-1; i++){
    afinidad += afinidades[i][i+1];
    afinidad += afinidades[i][i-1];
  }

  afinidad += afinidades[0][solucion.size()];
  return afinidad;
}

bool sentado(int pos, vector<int> &solucion){
  for(int i = 0; i < pos; i++){
    if (solucion[i] == solucion[pos]){
      return true;
    }
  }

  return false;
}

void posicionar(int pos, vector<int> &solucion, vector<vector<int>> &afinidades, int &mejor, vector<int> &mejorSolucion){
  for(int i = 1; i < afinidades.size(); i++){
    
    solucion[pos] = i;
    
    if(!sentado(pos, solucion)){
      if (i < afinidades.size()-1)
	posicionar(pos+1, solucion, afinidades, mejor, mejorSolucion);
      else{
	int peso = calcularAfinidad(solucion, afinidades);

	cout << "afinidad de la solución ";
	printVector(solucion);
	cout << " " << peso << endl;
	
	if(peso > mejor){
	  mejor = peso;
	  mejorSolucion = solucion;
	}
      }
    }
    
  }
}

int main(){

  int pSize = 5;
  vector<vector<int>> afinidades(pSize, vector<int>(pSize));
  vector<int> solucion(pSize, -1); //Vector que contiene el indice de los comensales
  int mejorAfinidad = -1;

  
  mt19937 rng;
  rng.seed(std::random_device()());
  uniform_int_distribution<uint32_t> afinidad(0,100);

  for(int i = 0; i < pSize; i++){
    for(int j = 0; j < pSize; j++){
      if(i == j)
	afinidades[i][j] = 100;
      else
	afinidades[i][j] = afinidad(rng);
      
      afinidades[j][i] = afinidades[i][j];
    }
  }

  
  printMatrix(afinidades);
  solucion[0] = 0;
  posicionar(1, solucion, afinidades, mejorAfinidad, solucion);
  cout << "Mejor solución: ";
  printVector(solucion);
  cout << endl;
}
