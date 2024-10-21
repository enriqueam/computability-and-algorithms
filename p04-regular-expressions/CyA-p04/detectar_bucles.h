// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 25/10/2022
// Archivo  detectar_bucles.h
//    Clase que almacena los bucles del fichero de entrada.

#include <iostream>

class DetectarBucle {
 public:
  DetectarBucle(const std::string& tipo, const std::string& parametro, const unsigned int& linea);
  std::string GetTipo();
  std::string GetParametro();
  unsigned int GetLinea();

 private:
  std::string tipo_;
  std::string parametro_;
  unsigned int numero_linea_;
};