// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 25/10/2022
// Archivo  detectar_main.h
//    Clase que almacena contiene información sobre la existencia de main.

#include <iostream>

class DetectarMain {
 public:
  DetectarMain();

  void SetMain();
  bool GetMain();
  private:
  bool main_ = false;
};