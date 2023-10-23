#include <iostream>
#include <chrono>
#include "DyV.h"

int main(){

  // ************************************
  // SE PONE A PRUEBA LA BUSQUEDA BINARIA
  // ************************************

  std::cout << "*** BÚSQUEDA BINARIA\n";
  std::vector<int> a{-3, -1, 0, 1, 1, 4, 5, 7, 12, 16, 19};
  int aTam = a.size();
  std::cout << "*******************************************\n";
  std::cout << "Vector a original: ";
  for(int i = 0; i < aTam; i++){
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "*******************************************\n";
  // se obtiene la longitud del vector
  std::cout << "Número a buscar: ";
  int x;
  std::cin >> x;
  // se define el elemento a buscar
  int pos;

  // SE MIDE EL TIEMPO QUE CUESTA ENCONTRAR EL NÚMERO
  auto startB = std::chrono::system_clock::now();
  pos = busquedaBinaria(x, a, 0, aTam);
  // proceso a medir
  auto endB = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> durationB = endB - startB;
  // se calcula el tiempo

  std::cout << "Pos: " << pos << std::endl;
  std::cout << "Time: " << durationB.count() << "s" << std::endl;

  // *****************************************
  // SE PONE A PRUEBA LOS DIFERENTES QUICKSORT
  // *****************************************

  std::cout << "\n*** QUICKSORT";
  std::vector<int> b{3, 5, -1, 2, 7, 6, 1, 5, 7, -9, -2};
  std::vector<int> bOriginal;
  bOriginal = b;
  int bTam = b.size();
  std::cout << std::endl;
  std::cout << "*******************************************\n";
  std::cout << "Vector b original: ";
  for(int i = 0; i < bTam; i++){
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "*******************************************\n";
  // se muestra el vector original

  // ***************************
  // QUICKSORT CON PIVOTE FINAL
  // ***************************
  
  auto startQ1 = std::chrono::system_clock::now();
  quickSortFinal(b, 0, bTam-1);
  // proceso a medir
  auto endQ1 = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> durationQ1 = endQ1 - startQ1;
  // se calcula el tiempo

  std::cout << "\n1 - El vector b ha sido ordenado con pivote final\n";
  std::cout << "Vector ordenado: ";
  for(int i = 0; i < bTam; i++){
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Time: " << durationQ1.count() << "s" << std::endl;

  b = bOriginal;
  // se devuelven los valores originales del vector

  // ***************************
  // QUICKSORT CON PIVOTE INICIAL
  // ***************************

  auto startQ2 = std::chrono::system_clock::now();
  quickSortInicial(b, 0, bTam-1);
  //  proceso a medir
  auto endQ2 = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> durationQ2 = endQ2 - startQ2;
  // se calcula el tiempo

  std::cout << "\n2 - El vector b ha sido ordenado con pivote inicial\n";
  std::cout << "Vector ordenado: ";
  for(int i = 0; i < bTam; i++){
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Time: " << durationQ2.count() << "s" << std::endl;
  
  b = bOriginal;
  
  // se devuelven los valores originales del vector

  // ***************************
  // QUICKSORT CON PIVOTE CENTRAL
  // ***************************

  auto startQ3 = std::chrono::system_clock::now();
  quickSortCentral(b, 0, bTam-1);
  //  proceso a medir
  auto endQ3 = std::chrono::system_clock::now();
  std::chrono::duration<float, std::milli> durationQ3 = endQ3 - startQ3;
  // se calcula el tiempo

  std::cout << "\n3 - El vector b ha sido ordenado con pivote central\n";
  std::cout << "Vector ordenado: ";
  for(int i = 0; i < bTam; i++){
    std::cout << b[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "Time: " << durationQ3.count() << "s" << std::endl;

  return 0;
}
