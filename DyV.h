#include <vector>
#include <iostream>


// *********************************
// DEFINICIÓN DE LA BÚSQUEDA BINARIA
// *********************************

template <typename T> int busquedaBinaria(T x, std::vector<T> a, int ini, int fin){

  int centro = (ini + fin) / 2;
  //definimos el centro del vector
   
  // CASO BASE
  if(x == a[centro]){
    return centro;
    // si lo encuentra
  }
  // PEOR CASO
  if(centro > fin || centro < ini){
    std::cout << "No se ha encontrado el numero" << std::endl;
    return -1;
  }
  // CASO GENERAL
  else if(x > a[centro]){
    return busquedaBinaria(x, a, centro + 1, fin);
    // si el numero buscado es mayor
  }
  else{
    return busquedaBinaria(x, a, ini, centro - 1);
    // si el numero buscado es menor
  }
}

// *********************************************
// DEFINICIÓN DE LAS FUNCIONES PARA EL QUICKSORT
// *********************************************

// FUNCIÓN SWAP ÚNICA
template <typename T> void swap(int i, int j, std::vector<T> &V){
  T aux = V[i];
  V[i] = V[j];
  V[j] = aux;
}

// FUNCIÓN PARTITION FINAL
template <typename T> int PartitionFinal(std::vector<T> &V, int ini, int fin){
  T x = V[fin];
  // pivote final
  int i = ini;
  for(int j = ini; j < fin; j++){
    if(V[j] <= x){
      swap(i, j, V);
      i++;
    }
    /*for(int k = ini; k < fin; k++){
      std::cout << V[k] << " ";
    }
    std::cout << std::endl;
    */
  }
  swap(i, fin, V);
  return i;
}

// FUNCIÓN PARTITION INICIAL
template <typename T> int PartitionInicial(std::vector<T> &V, int ini, int fin){
  T x = V[ini];
  // pivote inicial
  int i = fin;
  for(int j = fin; j > ini; j--){
    if(V[j] >= x){
      swap(i, j, V);
      i--;
    }
  }
  swap(i, ini, V);
  return i;
}

// FUNCIÓN QUICKSORT FINAL
template <typename T> int quickSortFinal(std::vector<T> &V, int ini, int fin){
  if(ini < fin){
    int pivot = PartitionFinal(V, ini, fin);
    quickSortFinal(V, ini, pivot - 1);
    quickSortFinal(V, pivot + 1, fin);
  }
}

//FUNCIÓN QUICKSORT INICIAL
template <typename T> int quickSortInicial(std::vector<T> &V, int ini, int fin){
  if(ini < fin){
    int pivot = PartitionInicial(V, ini, fin);
    quickSortInicial(V, ini, pivot - 1);
    quickSortInicial(V, pivot + 1, fin);
  }
}

//FUNCIÓN QUICKSORT CENTRAL
template <typename T> int quickSortCentral(std::vector<T> &V, int ini, int fin){
  int centro = (ini + fin)/2;
  T x = V[centro];
  // pivote central
  int i = ini;
  int j = fin;
  do{
    while(V[i] < x) i++;
    while(V[j] > x) j--;
    if(i<=j){
      swap(i, j, V);
      i++;
      j--;
    }
  }while(i<=j);

  if(ini < j) quickSortCentral(V, ini, j);
  if(i < fin) quickSortCentral(V, i, fin);
}



