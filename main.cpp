/*
  Rodrigo Reyes - Ayudante de Estructura de datos
  1er semestre - 2022
  Listas Enlazadas en C++
*/

#include <iostream>
using namespace std;
struct nodo{
  int info;
  struct nodo *sgte;
};
typedef nodo *Lista;
void iniciar_lista(Lista &p);
void insertar_nodo(Lista &p,int dato);
void ver_lista(Lista &p);
bool buscar(Lista &p,int busqueda);
void borrar_nodo(Lista &p,int dato);
int contar_nodo(Lista &p);
int suma_nodos(Lista &p);
float promedio_nodos(Lista &p);
void menu();

int main(int argc, char* argv[]) {
  menu();
  return 0;
}

void iniciar_lista(Lista &p){
  p = NULL;
}
void insertar_nodo(Lista &p,int dato){
  if(p==NULL){
    p = new(nodo);
    p->info = dato;
    p->sgte = NULL;
  }else{
    Lista tmp = NULL;
    tmp = new(nodo);
    tmp->info = dato;
    tmp->sgte = p;
    p=tmp;
  }
}
void ver_lista(Lista &p){
  Lista tmp = p;
  if(tmp==NULL){
    cout << "Lista vacia" <<endl;
  }else{
    int i=1;
    while(tmp!=NULL){
      cout <<"["<<i << "] : " << tmp->info << endl; 
      tmp=tmp->sgte;
      i++;
    }
  }
}
bool buscar(Lista &p,int busqueda){
  cout << endl;
  Lista tmp = p;
  bool band=false;
  while(tmp!=NULL){
    if(tmp->info == busqueda){
      band = true;
    }
    tmp = tmp -> sgte;
  }
  if(band == true){
    return true;
  }else{
    return false;
  }
}
void borrar_nodo(Lista &p,int dato){
  Lista tmp;
  if(p!=NULL){
    if(p->info == dato){
      tmp=p;
      p=p->sgte;
      delete tmp;
    }else{
      borrar_nodo(p->sgte,dato);
    }
  }
}
int contar_nodo(Lista &p){
  Lista tmp = p;
  int contador=0;
  while(tmp!=NULL){
    contador++;
    tmp=tmp->sgte;
  }
  return contador;
}
int suma_nodos(Lista &p){
  int contador = 0;
  Lista tmp = p;
  while(tmp!=NULL){
    contador += tmp->info;
    tmp=tmp->sgte;
  }
  return contador;
}
float promedio_nodos(Lista &p){
  float sum = suma_nodos(p);
  float cant = contar_nodo(p);
  return sum/cant;
}
void menu(){
  cout << endl << "Lista Lineal Simple en C++ " << endl << endl;
  int op=0;
  Lista LLS;
  do{
    cout << "1.Iniciar Lista"<<endl;
    cout << "2.Insertar Nodo"<<endl;
    cout << "3.Ver Lista"<<endl;
    cout << "4.Buscar"<<endl;
    cout << "5.Borrar Nodo"<<endl;
    cout << "6.Contar Nodos"<<endl;
    cout << "7.Suma Nodos"<<endl;
    cout << "8.Promedio Nodos"<<endl;
    cout << "0.Salir"<<endl;
    cout << "Su opcion: ";
    cin>>op;
    int valor = 0;
    switch(op){
      case 0: cout << endl << "Gracias por usas el programa" << endl << endl;
              exit(1);
              break;
      case 1: iniciar_lista(LLS);
              cout << endl << "Lista iniciada " << endl << endl;
              break;
      case 2: cout << endl << "Ingrese el dato que desea insertar: ";
              cin>>valor;
              insertar_nodo(LLS,valor);
              break;
      case 3: cout << endl;
              ver_lista(LLS);
              cout << endl;
              break;
      case 4: cout << "Ingrese el valor que desea buscar: ";
              cin>>valor;
              if(buscar(LLS,valor)){
                cout << "El nodo se encuentra en la lista" << endl << endl;
              }else{
                cout << "El nodo NO se encuentra en la lista"<< endl << endl;
              }
              break;
      case 5: cout << "Ingrese el nodo a borrar: ";
              cin>>valor;
              cout << endl;
              borrar_nodo(LLS,valor);
              cout << endl;
              break;
      case 6: cout << endl <<"La cantidad de nodos es: " << contar_nodo(LLS) << endl << endl;
              break;
      case 7: cout << endl << "La suma de nodos es: " << suma_nodos(LLS) << endl << endl;
              break;
      case 8: cout << endl << "El promedio de nodos es: " << promedio_nodos(LLS)<< endl <<endl;
              break;
    }
  }while(op!=0);
}