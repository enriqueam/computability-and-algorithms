// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 25/10/2022
// Archivo  detectar_main.cc
//    Archivo que contiene la implementación de la clase DetectarMain.

#include "detectar_main.h"

// Constructor
DetectarMain::DetectarMain() {
  main_ = false;
}

// Metodo que establece si hay main
void DetectarMain::SetMain() {
  main_ = true;
}

// Metodo que devuelve el valor de main
bool DetectarMain::GetMain() {
  return main_;
}