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
    afinidad += afinidades[solucion[i]][solucion[i+1]];
    afinidad += afinidades[solucion[i]][solucion[i-1]];
  }

  afinidad += afinidades[solucion[0]][solucion[solucion.size()]];
  return afinidad;
}

bool sentado(int pos, vector<int> &solucion){
  for(int i = 0; i < solucion.size(); i++){
    if (i != pos && solucion[i] == solucion[pos]){
      return true;
    }
  }

  return false;
}

void posicionar(int pos, vector<int> solucion, vector<vector<int>> &afinidades, int &mejor, vector<int> &mejorSolucion){
  for(int i = 1; i < afinidades.size(); i++){
    
    solucion[pos] = i;
    /*cout << "Value of [" << pos << "] set to " << i << endl;
    cout << "Vector: ";
    printVector(solucion);
    cout << endl;*/
    if(!sentado(pos, solucion)){
      if(pos+1 < afinidades.size()){
	posicionar(pos+1, solucion, afinidades, mejor, mejorSolucion);
      }
      else{
	if(calcularAfinidad(solucion, afinidades) > mejor){
	  mejor = calcularAfinidad(solucion, afinidades);
	  mejorSolucion = solucion;
	}

	
	cout << "afinidad de la solución ";
	printVector(solucion);
	cout << " " << calcularAfinidad(solucion, afinidades) << " vs " << mejor << endl;
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
      if(i == j){
	afinidades[i][j] = 100;
	afinidades[j][i] = afinidades[i][j];
      }
      else{
	afinidades[i][j] = afinidad(rng);
	afinidades[j][i] = afinidad(rng);
      }
      
    }
  }

  
  printMatrix(afinidades);
  solucion[0] = 0;
  posicionar(1, solucion, afinidades, mejorAfinidad, solucion);
  cout << "Mejor solución: ";
  printVector(solucion);
  cout << " con una afinidad de " << mejorAfinidad << endl;

  /*
  vector<int> s;
  s.push_back(0);
  s.push_back(1);
  s.push_back(2);
  cout << calcularAfinidad(s, afinidades) << endl;
  cout << calcularAfinidad(s, afinidades) << endl;*/
}
