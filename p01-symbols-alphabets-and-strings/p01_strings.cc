// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 04/10/2022
// Archivo  p01_strings.cc: programa cliente.
//    Contiene la función main del proyecto, además de otras funciones para 
//    el procesamiento de los datos de entrada y salida, además de otras 
//    comprobaciones.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "simbolos.h"
#include "alfabetos.h"
#include "cadenas.h"

const char SPACE = ' ';

// Metodo que comprueba que los argumentos introducidos son correctos, además de
// que el fichero de entrada existe. Muestra también información sobre el uso
// del programa.
bool ComprobacionEntrada(int& argc, char* argv[]) {
  std::string help = "-h";
  std::string help_ = "--help";
  if (argc == 4) { 
    std::string fichero_entrada = argv[1];
    std::string fichero_salida  = argv[2];
    int opcode = std::atoi(argv[3]);
    
    std::ifstream archivo_entrada(fichero_entrada);
    std::ofstream archivo_salida(fichero_salida);

    if (archivo_entrada.is_open() && archivo_entrada.is_open() && opcode >= 1 && opcode <= 6) {
      return true;
    } else {
      std::cout << "El número o los parámetros de entrada no son correctos." << std::endl;
    return false;
    }
   } else if(argc == 2 && (argv[1] == help || argv[1] == help_)) {
      std::cout << "Dado un fichero de entrada, un fichero de salida y un opcode, correspondiente a una operación, este programa leerá el alfabeto y la cadena proporcionada para luego almacenar el resultado de una de las operaciones en el fichero de salida. Las operaciones implementadas son:\n\tOpcode = 1: Calcula la longuitud de las cadenas en base a su alfabeto.\n\tOpcode = 2: Calcula la inversa de la cadena de entrada.\n\tOpcode = 3: Calcula los prefijos de la cadena de entrada.\n\tOpcode = 4: Calcula los sufijos de la cadena de entrada.\n\tOpcode = 5: Calcula las subcadenas de la cadena de entrada." << std::endl;
      std::cout << "Modo de ejecución: ./p01_strings filein.txt fileout.txt opcode" << std::endl;
  } else {
    std::cout << "El número o los parámetros de entrada no son correctos." << std::endl;
    return false;
  }
  return false;
}

// Metodo que dada una linea de entrada que no contiene el alfabeto de la cadena
// separa la cadena en simbolos únicos para crear el alfabeto y la propia 
// cadena.
Cadena EntradaSinAlfabeto(std::string& linea) {
  Cadena Cadena;
  Alfabeto Alfabeto;
  for (unsigned int index = 0; index < linea.size(); index++) {
    std::string simbolo_entrada = linea.substr(index, 1);
    Simbolo Simbolo(simbolo_entrada);
    Cadena.InsertarSimbolo(Simbolo);
    Alfabeto.InsertarSimbolo(Simbolo);
  }
  Cadena.SetAlfabeto(Alfabeto);
  std::cout << "Alfabeto: " << Alfabeto << std::endl;
  return Cadena;
}

// Metodo que dada una linea de entrada que contiene el alfabeto y la cadena,
// procesa los primeros simbolos para crear el alfabeto.
void ExtraerAlfabeto(Alfabeto& Alfabeto, std::string& linea, std::size_t posicion_espacio) {
  std::string simbolo_entrada = linea.substr(0, posicion_espacio);
  Simbolo Simbolo(simbolo_entrada);
  Alfabeto.InsertarSimbolo(Simbolo);
  linea.erase(0, linea.find(SPACE) + 1);
}

// Metodo que dada una linea de entrada que contiene el alfabeto de la cadena,
// tras extraer el alfabeto, comprueba si los simbolos de la cadena pertenecen
// al alfabeto
void ExtraerCadena(Alfabeto& Alfabeto, Cadena& Cadena, std::string& linea) {
  int iterador = 1;
  while(linea != "") {
    std::string simbolo_entrada = linea.substr(0, iterador);
    Simbolo Simbolo(simbolo_entrada);
    if (Alfabeto.BuscarSimbolo(Simbolo)) {
      Cadena.InsertarSimbolo(Simbolo);
      linea.erase(0, iterador);
      iterador = 1;
    } else {
      iterador++;
    }
  }
}

// Metodo que dada una linea de entrada que contiene un alfabeto y una
// cadena, procesa la linea para crear el alfabeto y la cadena.
Cadena EntradaConAlfabeto(std::string& linea) {
  Cadena Cadena;
  Alfabeto Alfabeto;
  while (linea != "") {
    std::size_t posicion_espacio = linea.find(SPACE);
    if (posicion_espacio != std::string::npos) {
      ExtraerAlfabeto(Alfabeto, linea, posicion_espacio);
    } else {
      std::cout << "Alfabeto: " << Alfabeto << std::endl;
      Cadena.SetAlfabeto(Alfabeto);
      ExtraerCadena(Alfabeto, Cadena, linea);
    }
  }
  return Cadena;
}

// Metodo que dada una linea de entrada, comprueba si contiene el alfabeto o si
// no lo contiene y llama a los metodos correspondientes para crear el alfabeto
// y la cadena.
std::vector<Cadena> ProcesarEntradas(std::vector<std::string>& entradas) {;
  std::vector<Cadena> cadenas;
  for (unsigned int index = 0; index < entradas.size(); index++) {
    std::string linea = entradas[index];
    std::size_t found = linea.find(SPACE);
    if (found == std::string::npos) {
      cadenas.push_back(EntradaSinAlfabeto(linea));
    } else {
      cadenas.push_back(EntradaConAlfabeto(linea));
    }
  } 
  return cadenas;
}

// Metodo que extrae y retorna las lineas de entrada del fichero de entrada.
std::vector<std::string> LeerFichero(char* argv[]) {
  std::ifstream archivo_entrada(argv[1]);

  std::vector<std::string> lineas;
  std::string linea;
  while (std::getline(archivo_entrada, linea)) {
    lineas.push_back(linea);
  }
  return lineas;
}

// Metodo que escribe en un fichero un número entero
void ImprimirResultados(int longuitud_cadena, std::string fichero_salida) {
  std::ofstream archivo_salida(fichero_salida, std::ios::app);
  archivo_salida << longuitud_cadena << std::endl;
  archivo_salida.close();
}

// Metodo que escribe en un fichero una cadena de simbolos
void ImprimirResultados(Cadena CadenaInversa, std::string fichero_salida) {
  std::ofstream archivo_salida(fichero_salida, std::ios::app);
  archivo_salida << CadenaInversa << std::endl;
  archivo_salida.close();
}

// Metodo que escribe en un fichero un vector de cadenas
void ImprimirResultados(std::vector<Cadena> cadenas, std::string fichero_salida) {
  std::ofstream archivo_salida(fichero_salida, std::ios::app);
  for (unsigned int index = 0; index < cadenas.size(); index++) {
    archivo_salida << cadenas[index] << " ";
  }
  archivo_salida << std::endl;
  archivo_salida.close();
}

// Metodo que escribe en un fichero un vector de cadenas
void ImprimirResultados(bool es_palindromo, std::string fichero_salida) {
  std::ofstream archivo_salida(fichero_salida, std::ios::app);
  if (es_palindromo) {
    archivo_salida << "true" << std::endl;
  } else {
    archivo_salida << "false" << std::endl;
  }
  archivo_salida.close();
}

// Metodo que controla la ejecución del programa en función del opcode
// introducido por el usuario para luego almacenar los resultados en un
// fichero de salida.
void MenuOperaciones(std::string fichero_salida, int opcode, std::vector<Cadena>& cadena) {
  for (unsigned int index = 0; index < cadena.size(); index++) {
    switch (opcode) {
      case 1:
        ImprimirResultados(cadena[index].Longitud(), fichero_salida);
        break;
      case 2:
        ImprimirResultados(cadena[index].Inversa(), fichero_salida);
        break;
      case 3:
         ImprimirResultados(cadena[index].Prefijos(), fichero_salida);
        break;
      case 4:
        ImprimirResultados(cadena[index].Sufijos(), fichero_salida);
        break;
      case 5:
        ImprimirResultados(cadena[index].Subcadenas(), fichero_salida);
        break;
      case 6:
        ImprimirResultados(cadena[index].Palindromo(), fichero_salida);
        break;
      default:
        std::cout << "El número o los parámetros de entrada no son correctos." << std::endl;
        break;
    }
  }
}

// Metodo principal que controla la ejecución del programa
int main(int argc, char* argv[]) {
  if (ComprobacionEntrada(argc, argv)) {
    std::vector<std::string> entradas;
    entradas = LeerFichero(argv);

    std::vector<Cadena> cadenas = ProcesarEntradas(entradas);
    MenuOperaciones(std::string(argv[2]), std::atoi(argv[3]), cadenas);
  }
  return 0;
}