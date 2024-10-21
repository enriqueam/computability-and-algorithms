// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 25/10/2022
// Archivo  analisis_ficheros.h
//    Clase que analiza el fichero de entrada.

#include <iostream>
#include <vector>
#include <string>
#include <regex>

#include "detectar_bucles.h"
#include "detectar_variables.h"
#include "detectar_comentarios.h"
#include "detectar_main.h"


class AnalisisFichero {
 public:
  AnalisisFichero(std::vector<std::string>& entrada);
  void SetNombreFichero(std::string nombre_fichero);

  void CazarMain();
  void CazarVariables();
  void CazarBucles();
  void CazarComentarios();

  std::string GetNombreFichero();
  std::vector<DetectarVariable> GetVariables();
  std::vector<DetectarBucle> GetBucles();
  std::vector<Detectarcomentario> GetComentarios();
  bool GetMain();

  friend std::ostream& operator<<(std::ostream& os, AnalisisFichero& entrada);

 private:
  std::vector<std::string> entrada_;

  std::string nombre_fichero_;
  std::vector<DetectarBucle> bucles_;
  std::vector<DetectarVariable> variables_;
  std::vector<Detectarcomentario> comentarios_;
  DetectarMain main_;
};