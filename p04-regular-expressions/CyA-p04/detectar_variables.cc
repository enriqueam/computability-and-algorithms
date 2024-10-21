// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 25/10/2022
// Archivo  detectar_variables.cc
//    Archivo que contiene la implementación de la clase DetectarVariables.

#include "detectar_variables.h"

// Constructor
DetectarVariable::  DetectarVariable(const std::string& tipo, const std::string& nombre, const std::string& valor, const unsigned int& linea) {
  tipo_ = tipo;
  nombre_ = nombre;
  valor_ = valor;
  numero_linea_ = linea;
}

// Metodo que devuelve el tipo de variable
std::string DetectarVariable::GetTipo() {
  return tipo_;
}

// Metodo que devuelve el nombre de la variable
std::string DetectarVariable::GetNombre() {
  return nombre_;
}

// Metodo que devuelve el valor de la variable
std::string DetectarVariable::GetValor() {
  return valor_;
}

// Metodo que devuelve el número de la linea
unsigned int DetectarVariable::GetLinea() {
  return numero_linea_;
}