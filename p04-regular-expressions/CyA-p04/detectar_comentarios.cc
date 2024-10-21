// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 25/10/2022
// Archivo  detectar_comentarios.cc
//    Archivo que contiene la implementación de la clase Detectarcomentario.

#include "detectar_comentarios.h"

// Construcctor
Detectarcomentario::Detectarcomentario(const std::string& tipo, const std::string& comentario, const unsigned int& linea_ini, const unsigned int& linea_fin) {
  tipo_ = tipo;
  comentario_ = comentario;
  numero_linea_ini_ = linea_ini;
  numero_linea_fin_ = linea_fin;
  descripcion_ = false;
}

// Metodo que devuelve el tipo de comentario
std::string Detectarcomentario::GetTipo() {
  return tipo_;
}

// Metodo que devuelve el comentario
std::string Detectarcomentario::GetComentario() {
  return comentario_;
}

// Metodo que devuelve el número de la linea de inicio
unsigned int Detectarcomentario::GetLineaIni() {
  return numero_linea_ini_;
}

// Metodo que devuelve el número de la linea de fin
unsigned int Detectarcomentario::GetLineaFin() {
  return numero_linea_fin_;
}
