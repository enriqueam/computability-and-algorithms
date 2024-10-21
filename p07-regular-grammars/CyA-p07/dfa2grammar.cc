#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include "finite_automata.h"

/**
 * @brief Comprueba que los parametros de entrada sean correctos
 * @param argc Numero de parametros de entrada
 * @param argv Vector de parametros de entrada
 * @return true si los parametros son correctos, false en caso contrario
 */
bool CheckInput(int& argc, char* argv[]) {
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
      std::cout << "Ejecute para más información: ./dfa2grammar --help || ./dfa2grammar -h" << std::endl;
    return false;
    }
   } else if(argc == 2 && (argv[1] == help || argv[1] == help_)) {
      std::cout << "Modo de ejecución: ./dfa2grammar filein.fa fileout.gra" << std::endl;
  } else {
    std::cout << "El número o los parámetros de entrada no son correctos." << std::endl;
    return false;
  }
  return false;
}

/**
 * @brief Dado un fichero de entrada, lee las entradas y las almacena en un 
 * vector.
 * @param fichero_entrada1 Fichero de entrada.
 * @return Vector con las entradas.
 */
std::vector<std::string> ReadInputFile(std::string fichero_entrada) {
  std::ifstream input_file(fichero_entrada);
  std::string line;
  std::vector<std::string> vector_entrada;
  while (std::getline(input_file, line)) {
    vector_entrada.push_back(line);
  }
  return vector_entrada;
}

/**
 * @brief Método que escribirá en un fichero de salida el resultado de la
 * ejecución del programa.
 * @param fichero_salida Fichero de salida.
 * @param grammar Gramática generada.
 */
void WriteFile(std::string fichero_salida, Grammar& grammar) {
  std::ofstream output_file(fichero_salida);
  output_file << grammar;
  output_file.close();
}

/**
 * @brief Entry point of the program
 * @param argc Number of arguments
 * @param argv Vector of arguments
*/
int main(int argc, char *argv[]) {
  CheckInput(argc, argv);

  std::string file_input = argv[1];
  std::string fichero_salida = argv[2];

  FiniteAutomata automata(file_input);
  std::cout << "Automata: " << std::endl;
  std::cout << automata << std::endl;
  Grammar grammar = automata.ConvertToGrammar();
  std::cout << "Grammar: " << std::endl;
  std::cout << grammar << std::endl;
  WriteFile(fichero_salida, grammar);

  /* std::vector<String> cadenas;
  Alphabet alfabeto = automata.GetAlphabet();
  std::vector<std::string> cadenas_entrada = ReadInputFile(argv[2]);
  for (unsigned int index = 0; index < cadenas_entrada.size(); index++) {
    String string(alfabeto, cadenas_entrada[index]);
    cadenas.push_back(string);
  }
  WriteFile(argv[3], cadenas, automata); */


  return 0;
}