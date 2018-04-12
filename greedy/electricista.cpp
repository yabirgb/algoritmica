#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Electricista{

private:
  vector<int> tareas;
  vector<int> plan;

  double calcularSatisfaccion(int tiempo){
    //Tiempo es el que tardas en llegar a el
    return 1.0/(tiempo+1);
  }

  
public:

  Electricista(vector<int> v){
    tareas = vector<int>(v);
  }

  void asignarTarea(int segundos){
    tareas.push_back(segundos);
  }

  double calcularGanancia(){
    double ganancia = 0;
    int tiempo = 0;
    
    for(int i = 0; i < plan.size(); i++){
      tiempo += plan[i];
      ganancia += calcularSatisfaccion(tiempo);   
    }

    return ganancia;
  }

  void plan1(){
    //En esta versión ordenamos las tareas en función de cual es la
    //que menos tiempo requiere
    plan = tareas;
    int size = tareas.end() - tareas.begin();
    sort(plan.begin(), plan.begin()+size );
  }

  void imprimirPlan(){
    for(int n : plan) {
      cout << n << ' ';
    }
  }

  void status(){
    imprimirPlan();
    cout << "\nGanancia: " << calcularGanancia() << endl;
  }
  
};

int main(){

  //Vector que contiene los tiempos que se usan para
  //cada cliente
  vector<int> clientes = {45,10,24,56,5,32};
  Electricista machine(clientes);

  machine.plan1();
  machine.status();
  
  
  return 0;
}
