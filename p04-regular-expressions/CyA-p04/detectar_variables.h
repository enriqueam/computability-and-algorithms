// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 25/10/2022
// Archivo  detectar_variables.h
//    Clase que almacena las variables del fichero de entrada.

#include <iostream>

class DetectarVariable {
 public:
  DetectarVariable(const std::string& tipo, const std::string& nombre, const std::string& valor, const unsigned int& linea);

  std::string GetTipo();
  std::string GetNombre();
  std::string GetValor();
  unsigned int GetLinea();
 private:
  std::string tipo_;
  std::string nombre_;
  std::string valor_;
  unsigned int numero_linea_;
};