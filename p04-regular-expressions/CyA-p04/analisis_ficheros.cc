// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 25/10/2022
// Archivo  analisis_ficheros.cc
//    Archivo que contiene la implementación de la clase AnalisisFichero.

#include "analisis_ficheros.h"

// Constructor de la clase AnalisisFichero
AnalisisFichero::AnalisisFichero(std::vector<std::string>& entrada) {
  entrada_ = entrada;
  CazarMain();
  CazarVariables();
  CazarBucles();
  CazarComentarios();
}

// Metodo que asigna el nombre del fichero
void AnalisisFichero::SetNombreFichero(std::string nombre_fichero) {
  nombre_fichero_ = nombre_fichero;
}

// Funcion que detecta el main
void AnalisisFichero::CazarMain() {
  std::regex main_regex("int main\\(\\)");
  std::smatch main_match;
  for (unsigned int i = 0; i < entrada_.size(); i++) {
    if (std::regex_search(entrada_[i], main_match, main_regex)) {
      main_.SetMain();
    }
  }
}

// Metodo que detecta las variables
void AnalisisFichero::CazarVariables() {
  std::regex variable(
      "[^(](int|double)\\s+([a-zA-Z0-9]+)(\\s*=\\s*[0-9]+.{0,1}[0-9]*;|;)");
  std::smatch variable_match;
  for (unsigned int index = 0; index < entrada_.size(); index++) {
    if (std::regex_search(entrada_[index], variable_match, variable)) {
      if (variable_match[3] == ";") {
        DetectarVariable variable(variable_match[1], variable_match[2], "",
                                  index + 1);
        variables_.push_back(variable);
      } else {
        DetectarVariable variable(variable_match[1], variable_match[2],
                                  variable_match[3], index + 1);
        variables_.push_back(variable);
      }
    }
  }
}

// Metodo que detecta los bucles
void AnalisisFichero::CazarBucles() {
  std::regex bucle("^\\s*(for|while)\\s*\\((.*)\\)");
  std::smatch bucle_match;
  for (unsigned int index = 0; index < entrada_.size(); index++) {
    if (std::regex_search(entrada_[index], bucle_match, bucle)) {
      if (bucle_match[1] == "for") {
        DetectarBucle bucle(bucle_match[1], "", index + 1);
        bucles_.push_back(bucle);
      } else if (bucle_match[1] == "while") {
        DetectarBucle bucle(bucle_match[1], bucle_match[2], index + 1);
        bucles_.push_back(bucle);
      }
    }
  }
}

// Metodo que detecta los comentarios
void AnalisisFichero::CazarComentarios() {
  std::regex multiple_init("\\/\\*");
  std::regex multiple_end("\\*\\/");
  std::regex single("^ *\\/\\/");
  std::smatch comentario_match;
  std::string comentario;
  bool multiple = false;
  unsigned int linea_ini = 0;
  for (unsigned int index = 0; index < entrada_.size(); index++) {
    if (std::regex_search(entrada_[index], comentario_match, multiple_init)) {
      multiple = true;
      linea_ini = index + 1;
    } else if (multiple && !std::regex_search(entrada_[index], comentario_match,
                                      multiple_end)) {
      comentario += entrada_[index] + "\n";
    } else if (multiple && std::regex_search(entrada_[index], comentario_match,
                                      multiple_end)) {
      comentario += entrada_[index] + "\n";
      Detectarcomentario ComentarioToken("/* */", comentario, linea_ini,
                                    index + 1);
      comentarios_.push_back(ComentarioToken);
      multiple = false;
      comentario.clear();
    } else if (std::regex_search(entrada_[index], comentario_match, single)) {
      Detectarcomentario ComentarioToken("//", entrada_[index], index + 1, index + 1);
      comentarios_.push_back(ComentarioToken);
    }
  }
}

// Metodo que devuelve el nombre del fichero
std::string AnalisisFichero::GetNombreFichero() {
  return nombre_fichero_;
}

// Metodo que devuelve el main
bool AnalisisFichero::GetMain() {
  if (main_.GetMain()) {
    return true;
  }
  return false;
}

// Metodo que devuelve las variables
std::vector<DetectarVariable> AnalisisFichero::GetVariables() {
  return variables_;
}

// Metodo que devuelve los bucles
std::vector<DetectarBucle> AnalisisFichero::GetBucles() {
  return bucles_;
}

// Metodo que devuelve los comentarios
std::vector<Detectarcomentario> AnalisisFichero::GetComentarios() {
  return comentarios_;
}