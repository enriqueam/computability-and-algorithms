// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 11/10/2022
// Archivo  p02_languages.cc: programa cliente.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "simbolos.h"
#include "alfabetos.h"
#include "cadenas.h"
#include "lenguajes.h"

const char SPACE = ' ';
const char LLAVE_IZQ = '{';
const char LLAVE_DER = '}';

// Metodo que comprueba que los argumentos introducidos son correctos, además de
// que el fichero de entrada existe. Muestra también información sobre el uso
// del programa.
bool ComprobacionEntrada(int& argc, char* argv[]) {
  std::string help = "-h";
  std::string help_ = "--help";
  if (argc == 5) { 
    std::string fichero_entrada1 = argv[1];
    std::string fichero_entrada2 = argv[2];
    std::string fichero_salida  = argv[3];
    int opcode = std::atoi(argv[4]);
    
    std::ifstream archivo_entrada1(fichero_entrada1);
    std::ifstream archivo_entrada2(fichero_entrada2);
    std::ofstream archivo_salida(fichero_salida);

    if (archivo_entrada1.is_open() && archivo_entrada2.is_open() &&  archivo_salida.is_open() && opcode >= 1 && opcode <= 7) {
      return true;
    } else {
      std::cout << "No es posible abrir los ficheros o el opcode no es correcto." << std::endl;
      std::cout << "Ejecute para más información: ./p01_strings --help || ./p01_strings -h" << std::endl;
    return false;
    }
   } else if(argc == 2 && (argv[1] == help || argv[1] == help_)) {
      std::cout << "Modo de ejecución: ./p01_strings filein1.txt filein2.txt fileout.txt opcode" << std::endl;
  } else {
    std::cout << "El número o los parámetros de entrada no son correctos." << std::endl;
    return false;
  }
  return false;
}

// Metodo que dada una linea de entrada que contiene el alfabeto y la cadena,
// procesa los primeros simbolos para crear el alfabeto.
void ExtraerAlfabeto(Alfabeto& Alfabeto, std::string& linea) {
  while(linea != "") {
    std::string simbolo_entrada = linea.substr(0, linea.find(SPACE));
    Simbolo Simbolo(simbolo_entrada);
    Alfabeto.InsertarSimbolo(Simbolo);
    linea.erase(0, linea.find(SPACE) + 1);
  }
}

// Metodo que dada una linea de entrada que contiene el alfabeto de la cadena,
// tras extraer el alfabeto, comprueba si los simbolos de la cadena pertenecen
// al alfabeto
void ExtraerCadena(Alfabeto& Alfabeto, Cadena& Cadena, std::string& linea) {
  int iterador = 1;
  while(linea != "") {
    std::string simbolo_entrada = linea.substr(0, iterador);
    Simbolo Simbolo(simbolo_entrada);
    if (Simbolo == VACIA) {
      Cadena.InsertarSimbolo(Simbolo);
      linea.erase(0, iterador);
    } else if (Alfabeto.BuscarSimbolo(Simbolo)) {
      Cadena.InsertarSimbolo(Simbolo);
      linea.erase(0, iterador);
      iterador = 1;
    } else {
      iterador++;
    }
  }
}

// Metodo que dada parte de una linea de entrada, extrae el lenguaje.
void ExtraerLenguaje(Alfabeto& Alfabeto, Lenguaje& Lenguaje, std::string& linea) {
  while(linea != "") {
    std::string cadena_entrada = linea.substr(0, linea.find(SPACE));
    Cadena Cadena;
    ExtraerCadena(Alfabeto, Cadena, cadena_entrada);
    Lenguaje.InsertarCadena(Cadena);
    linea.erase(0, linea.find(SPACE) + 1);
  }
}

// Metodo que dada una linea de entrada que contiene un alfabeto y una
// cadena, procesa la linea para crear el alfabeto y la cadena.
Lenguaje EntradaConAlfabeto(std::string& linea) {
  Alfabeto Alfabeto;
  std::size_t posicion_corchete_1 = linea.find(LLAVE_IZQ);
  std::size_t posicion_corchete_2 = linea.find(LLAVE_DER);
  std::cout << "--------------------------" << std::endl;
  std::string alfabetos = linea.substr(posicion_corchete_1 + 2, posicion_corchete_2 - (posicion_corchete_1 + 2));
  std::size_t posicion_corchete_3 = linea.rfind(LLAVE_IZQ);
  std::size_t posicion_corchete_4 = linea.rfind(LLAVE_DER);
  std::string cadenas;
  if ((posicion_corchete_4 - posicion_corchete_3) == 2) {
    std::cout << "\t*** Lenguaje vacio" << std::endl;
  } else {
    cadenas = linea.substr(posicion_corchete_3 + 2, posicion_corchete_4 - (posicion_corchete_3 + 2));
  }
  ExtraerAlfabeto(Alfabeto, alfabetos);
  Lenguaje Lenguaje(Alfabeto);
  ExtraerLenguaje(Alfabeto, Lenguaje, cadenas);
  std::cout << "Alfabeto: " << Lenguaje.GetAlfabeto() << "--- Lenguaje: "<< Lenguaje << std::endl;
  return Lenguaje;
}

// Metodo que dada una linea de entrada, comprueba si contiene el alfabeto o si
// no lo contiene y llama a los metodos correspondientes para crear el alfabeto
// y la cadena.
std::vector<Lenguaje> ProcesarEntradas(std::vector<std::string>& entradas) {
  std::vector<Lenguaje> lenguajes;
  for (unsigned int index = 0; index < entradas.size(); index++) {
    std::string linea = entradas[index];
    lenguajes.push_back(EntradaConAlfabeto(linea));
  } 
  return lenguajes;
}

// Metodo que extrae y retorna las lineas de entrada del fichero de entrada.
std::vector<std::string> LeerFichero(std::string fichero_entrada) {
  std::ifstream archivo_entrada(fichero_entrada);

  std::vector<std::string> lineas;
  std::string linea;
  while (std::getline(archivo_entrada, linea)) {
    lineas.push_back(linea);
  }
  return lineas;
}

// Metodo que escribe en un fichero un vector de cadenas
void ImprimirResultados(Lenguaje Lenguaje, std::string fichero_salida) {
  std::ofstream archivo_salida(fichero_salida, std::ios::app);
  archivo_salida << "{ " << Lenguaje.GetAlfabeto() << "} " << "{ "<< Lenguaje << "}" << std::endl;
  archivo_salida.close();
}

// Metodo que controla la ejecución del programa en función del opcode
// introducido por el usuario para luego almacenar los resultados en un
// fichero de salida.
void MenuOperaciones(std::string fichero_salida, int opcode, std::vector<Lenguaje> lenguajes_fichero1, std::vector<Lenguaje> lenguajes_fichero2) {
  for (unsigned int index = 0; index < lenguajes_fichero1.size(); index++) {
    switch (opcode) {
      case 1:
        ImprimirResultados(lenguajes_fichero1[index].Concatenacion(lenguajes_fichero2[index]), fichero_salida);
        break;
      case 2:
        ImprimirResultados(lenguajes_fichero1[index].Union(lenguajes_fichero2[index]), fichero_salida);
        break;
      case 3:
        ImprimirResultados(lenguajes_fichero1[index].Interseccion(lenguajes_fichero2[index]), fichero_salida);
        break;
      case 4:
        ImprimirResultados(lenguajes_fichero1[index].Diferencia(lenguajes_fichero2[index]), fichero_salida);
        break;
      default:
        std::cout << "El número o los parámetros de entrada no son correctos." << std::endl;
        break;
    }
  }
}

// Metodo que controla la ejecución del programa en función del opcode
// introducido por el usuario para luego almacenar los resultados en un
// fichero de salida.
void MenuOperaciones(std::string fichero_salida, int opcode, std::vector<Lenguaje> lenguajes_fichero1) {
  for (unsigned int index = 0; index < lenguajes_fichero1.size(); index++) {
    switch (opcode) {
      case 5:
        ImprimirResultados(lenguajes_fichero1[index].Inversa(), fichero_salida);
        break;
      case 6:
        ImprimirResultados(lenguajes_fichero1[index].Potencia(), fichero_salida);
        break;
      case 7:
        ImprimirResultados(lenguajes_fichero1[index].ModiSubcadenas(), fichero_salida);
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
    std::vector<std::string> entradas_fichero1 = LeerFichero(argv[1]);
    std::vector<std::string> entradas_fichero2 = LeerFichero(argv[2]);
    if (std::atoi(argv[4]) >= 1 && std::atoi(argv[4]) <= 4) {
      std::vector<Lenguaje> lenguajes1 = ProcesarEntradas(entradas_fichero1);
      std::vector<Lenguaje> lenguajes2 = ProcesarEntradas(entradas_fichero2);
      MenuOperaciones(std::string(argv[3]), std::atoi(argv[4]), lenguajes1, lenguajes2);
    } else {
      std::vector<Lenguaje> lenguajes1 = ProcesarEntradas(entradas_fichero1);
      MenuOperaciones(std::string(argv[3]), std::atoi(argv[4]), lenguajes1);
    }
  }
  return 0;
}