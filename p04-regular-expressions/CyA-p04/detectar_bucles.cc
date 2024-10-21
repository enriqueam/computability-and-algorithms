// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 25/10/2022
// Archivo  detectar_bucles.cc
//    Archivo que contiene la implementación de la clase DetectarBucle.

#include "detectar_bucles.h"

// Constructor
DetectarBucle::DetectarBucle(const std::string& tipo, const std::string& parametro, const unsigned int& linea) {
  tipo_ = tipo;
  parametro_ = parametro;
  numero_linea_ = linea;
}

// Metodo que devuelve el tipo de bucle
std::string DetectarBucle::GetTipo() {
  return tipo_;
}

// Metodo que devuelve el parametro del bucle
std::string DetectarBucle::GetParametro() {
  return parametro_;
}

// Metodo que devuelve el número de la linea
unsigned int DetectarBucle::GetLinea() {
  return numero_linea_;
}
