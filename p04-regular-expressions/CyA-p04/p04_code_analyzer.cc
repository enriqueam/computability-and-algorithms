// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 4: Expresiones regulares
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 25/10/2022
// Archivo  p04_code_analyzer.cc
//    Programa principal.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "analisis_ficheros.h"

// Metodo que comprueba que los argumentos introducidos son correctos, además de
// que el fichero de entrada existe. Muestra también información sobre el uso
// del programa.
bool ComprobacionEntrada(int& argc, char* argv[]) {
  std::string help = "-h";
  std::string help_ = "--help";
  if (argc == 3) { 
    std::string fichero_entrada1 = argv[1];
    std::ifstream archivo_entrada1(fichero_entrada1);
    std::string fichero_salida = argv[2];

    if (archivo_entrada1.is_open() && !fichero_salida.empty()) {
      return true;
    } else {
      std::cout << "No es posible abrir el fichero de entrada o salida." << std::endl;
      std::cout << "Ejecute para más información: ./p04_code_analyzer --help || ./p04_code_analyzer -h" << std::endl;
    return false;
    }
   } else if(argc == 2 && (argv[1] == help || argv[1] == help_)) {
      std::cout << "Modo de ejecución: ./p04_code_analyzer filein.cc fileout.txt" << std::endl;
  } else {
    std::cout << "El número o los parámetros de entrada no son correctos." << std::endl;
    return false;
  }
  return false;
}

std::vector<std::string> LeerFichero(std::string fichero_entrada1) {
  std::vector<std::string> lenguaje;
  std::ifstream archivo_entrada1(fichero_entrada1);
  std::string linea = "";
  if (archivo_entrada1.is_open()) {
    while (getline(archivo_entrada1, linea)) {
      lenguaje.push_back(linea);
    }
  }
  return lenguaje;
}

// Escribe en el fichero de salida el nombre del fichero de entrada.
void EscribirNombrePrograma(std::ofstream& archivo_salida, AnalisisFichero& entrada) {
  archivo_salida << "PROGRAM: " << entrada.GetNombreFichero() << std::endl << std::endl;
}

// Escribe en el fichero de salida la descrición del fichero de entrada.
void EscribirDescripcion(std::ofstream& archivo_salida, AnalisisFichero& entrada) {
  archivo_salida << "DESCRIPTION:" << std::endl;
  for (unsigned int i = 0; i < entrada.GetComentarios().size(); i++) {
    if (entrada.GetComentarios()[i].GetTipo() == "/* */" && entrada.GetComentarios()[i].GetLineaIni() == 1) {
      archivo_salida << entrada.GetComentarios()[i].GetComentario() << std::endl;
    }
  }
}

// Escribe en el fichero de salida las variables del fichero de entrada.
void EscribirVariables(std::ofstream& archivo_salida, AnalisisFichero& entrada) {
  archivo_salida << "VARIABLES: " << std::endl;
  for (unsigned int i = 0; i < entrada.GetVariables().size(); i++) {
    archivo_salida << "[LINE " << entrada.GetVariables()[i].GetLinea() << "] ";
    if (entrada.GetVariables()[i].GetTipo() == "int") {
      archivo_salida << "INT: ";
    } else {
      archivo_salida << "DOUBLE: ";
    }
    archivo_salida << entrada.GetVariables()[i].GetNombre() << entrada.GetVariables()[i].GetValor() << std::endl;
  }
  archivo_salida << std::endl;
}

// Escribe en el fichero de salida el main del fichero de entrada.
void EscribirMain(std::ofstream& archivo_salida, AnalisisFichero& entrada) {
  archivo_salida << "MAIN:" << std::endl;
  if (entrada.GetMain()) {
    archivo_salida << "True" << std::endl;
  } else {
    archivo_salida << "False" << std::endl;
  }
  archivo_salida << std::endl;
}

// Escribe en el fichero de salida los bucles del fichero de entrada.
void EscribirBucles(std::ofstream& archivo_salida, AnalisisFichero& entrada) {
  archivo_salida << "STATEMENTS:" << std::endl;
    for (unsigned int i = 0; i < entrada.GetBucles().size(); i++) {
      archivo_salida << "[LINE " << entrada.GetBucles()[i].GetLinea() << "] ";
      archivo_salida << "LOOP: " << entrada.GetBucles()[i].GetTipo() << std::endl;
    }
    archivo_salida << std::endl;
}

// Escribe en el fichero de salida los comentarios del fichero de entrada.
void EscribirComentarios(std::ofstream& archivo_salida, AnalisisFichero& entrada) {
  archivo_salida << "COMMENTS:" << std::endl;
  for (unsigned int i = 0; i < entrada.GetComentarios().size(); i++) {
    if (entrada.GetComentarios()[i].GetTipo() == "//") {
      archivo_salida << "[LINE " << entrada.GetComentarios()[i].GetLineaIni() << "] ";
      archivo_salida << entrada.GetComentarios()[i].GetComentario() << std::endl;
    } else if (entrada.GetComentarios()[i].GetTipo() == "/* */" && entrada.GetComentarios()[i].GetLineaIni() == 1) {
      archivo_salida << "[LINE " << entrada.GetComentarios()[i].GetLineaIni() << " - " << entrada.GetComentarios()[i].GetLineaFin() << "] ";
      archivo_salida << "DESCRIPTION" << std::endl;
    } else {
      archivo_salida << "[LINE " << entrada.GetComentarios()[i].GetLineaIni() << " - " << entrada.GetComentarios()[i].GetLineaFin() << "] ";
      archivo_salida << entrada.GetComentarios()[i].GetComentario() << std::endl;
    }
  }
}

// Metodo que escribe en el fichero de salida
void EscribirFichero(std::string fichero_salida, AnalisisFichero& entrada) {
  std::ofstream archivo_salida(fichero_salida);
  if (archivo_salida.is_open()) {
    EscribirNombrePrograma(archivo_salida, entrada);
    EscribirDescripcion(archivo_salida, entrada);
    EscribirVariables(archivo_salida, entrada);
    EscribirBucles(archivo_salida, entrada);
    EscribirMain(archivo_salida, entrada);
    EscribirComentarios(archivo_salida, entrada);
  }
}

// Metodo principal
int main (int argc, char* argv[]) {
  if(ComprobacionEntrada(argc, argv)) {
    std::vector<std::string> entrada = LeerFichero(argv[1]);
    AnalisisFichero AnalisisFichero(entrada);
    AnalisisFichero.SetNombreFichero(argv[1]);
    EscribirFichero(argv[2], AnalisisFichero);
  }
  return 0;
}