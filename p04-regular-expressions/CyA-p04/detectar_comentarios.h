// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 25/10/2022
// Archivo  detectar_comentarios.h
//    Clase que almacena los comentarios del fichero de entrada.

#include <iostream>

class Detectarcomentario {
 public:
  Detectarcomentario(const std::string& tipo, const std::string& comentario, const unsigned int& linea_ini, const unsigned int& linea_fin);

  std::string GetTipo();
  std::string GetComentario();
  unsigned int GetLineaIni();
  unsigned int GetLineaFin();

  private:
    std::string tipo_;
    std::string comentario_;
    unsigned int numero_linea_ini_;
    unsigned int numero_linea_fin_;
    bool descripcion_;
};