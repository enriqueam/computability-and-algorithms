// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  p06_automata_simulator.cc: programa principal.
//    Contiene el programa principal que ejecuta la simulación de un autómata
//    finito.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "symbols.h"
#include "alphabets.h"
#include "states.h"
#include "transitions.h"
#include "finite_automatas.h"
#include "strings.h"

const char SPACE = ' ';

/**
 * @brief Comprueba que los parametros de entrada sean correctos
 * @param argc Numero de parametros de entrada
 * @param argv Vector de parametros de entrada
 * @return true si los parametros son correctos, false en caso contrario
 */
bool CheckInput(int& argc, char* argv[]) {
  std::string help = "-h";
  std::string help_ = "--help";
  if (argc == 4) { 
    std::string fichero_entrada1 = argv[1];
    std::ifstream archivo_entrada1(fichero_entrada1);
    std::string fichero_salida = argv[2];

    if (archivo_entrada1.is_open() && !fichero_salida.empty()) {
      return true;
    } else {
      std::cout << "No es posible abrir el fichero de entrada o salida." << std::endl;
      std::cout << "Ejecute para más información: ./p06_automata_simulator --help || ./p06_automata_simulator -h" << std::endl;
    return false;
    }
   } else if(argc == 2 && (argv[1] == help || argv[1] == help_)) {
      std::cout << "Modo de ejecución: ./p06_automata_simulator filein.fa fileint.txt fileout.txt" << std::endl;
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
 * @brief Método que dada una linea de entrada que contiene el alfabeto y la
 * string, procesa los primeros simbolos para crear el alfabeto.
 * @param line Linea de entrada que contiene el alfabeto y la string.
 * @return Alfabeto.
 */
void ExtractAlphabet(Alphabet& alphabet, std::string& line, std::size_t space_position) {
  std::string input_symbol = line.substr(0, space_position);
  Symbol symbol(input_symbol);
  alphabet.InsertSymbol(symbol);
  line.erase(0, line.find(SPACE) + 1);
}

Alphabet ObtainAlphabet(std::string linea_alfabeto) {
  Alphabet alphabet;
  while (linea_alfabeto != "") {
    std::size_t space_position = linea_alfabeto.find(SPACE);
    if (space_position != std::string::npos) {
      ExtractAlphabet(alphabet, linea_alfabeto, space_position);
    } else {
      Symbol symbol(linea_alfabeto);
      alphabet.InsertSymbol(symbol);
      linea_alfabeto.erase(0, linea_alfabeto.length());
    }
  }
  return alphabet;
}

/**
 * @brief Método que busca un etado en un vector de estados.
 * @param vector_estados Vector de estados.
 * @param id_state Estado a buscar.
 * @return int Posición del estado en el vector.
 */
int SearchState(std::vector<State> vector_states, std::string id_state) {
  for (unsigned int index = 0; index < vector_states.size(); index++) {
    if (vector_states[index].GetId() == id_state) {
      return index;
    }
  }
  std::cout << "State " << id_state << " not found." << std::endl;
  exit(1);
}

/**
 * @brief Método que dada la entrada y el vector de estados, obiene los estados 
 * finales.
 * @param fa_input Entrada del autómata.
 * @param vector_states Vector de estados.
 */
void ExtractFinalStates(std::vector<std::string> fa_input, std::vector<State>& states) {
  for (unsigned int index = 3; index < fa_input.size(); index++) {
    std::string line = fa_input[index];

    std::string id_state = std::string(1, line[0]);
    int index_state = SearchState(states, id_state);

    int is_final = std::stoi(std::string(1, line[2]));
    if (is_final == 1) {
      states[index_state].SetIsFinal(true);
    }
  }
}

/**
 * @brief Método que dada la entrada y el vector de estados y el alfabeto,
 * obtiene las transiciones.
 * @param fa_input Entrada del autómata.
 * @param states Vector de estados.
 * @param alphabet Alfabeto.
 * @return Vector de transiciones.
 */
std::vector<Transition> ExtractTransitions(std::vector<std::string> fa_input, std::vector<State>& states, Alphabet& alphabet) {

  ExtractFinalStates(fa_input, states);
  std::vector<Transition> transitions;
  for (unsigned int index = 3; index < fa_input.size(); index++) {
    std::string line = fa_input[index];
    std::string id_state = std::string(1, line[0]);
    int index_state = SearchState(states, id_state);

    // int number_transitions = std::stoi(std::string(1, line[4]));

    for (int iterator = 0; iterator < 3; iterator++) {
      line.erase(0, line.find(SPACE) + 1);
    }
      
    while (line != "") {
      std::size_t space_position = line.find(SPACE);
      if (space_position != std::string::npos) {
        Symbol symbol(line.substr(0, space_position));
        if (alphabet.SearchSymbol(symbol)) {
          line.erase(0, line.find(SPACE) + 1);
          std::size_t space_position = line.find(SPACE);
          std::string id_transition = line.substr(0, space_position);
          line.erase(0, line.find(SPACE) + 1);
          int index_transition = SearchState(states, id_transition);
          Transition transition(states[index_state], symbol, states[index_transition]);
          transitions.push_back(transition);
        } else {
          std::cout << "Symbol " << symbol << " of the line " << line << " is not in the alphabet." << std::endl;
        }
      } else {
        line.erase(0, line.length());
      }
    }
  }
  return transitions;
}

/**
 * @brief Método que escribirá en un fichero de salida el resultado de la
 * ejecución del programa.
 * @param fichero_salida Fichero de salida.
 * @param cadenas_entra Cadena de entrada.
 */
void WriteFile(std::string fichero_salida, std::vector<String> cadenas_entrada, FiniteAutomata& automata) {
  std::ofstream archivo_salida(fichero_salida);
  for (unsigned int index = 0; index < cadenas_entrada.size(); index++) {
    if (automata.Resolve(cadenas_entrada[index])) {
      archivo_salida << cadenas_entrada[index] << " --- Acepted" << std::endl;
    } else {
      archivo_salida << cadenas_entrada[index] << " --- Rejected" << std::endl;
    }
    
  }
}

int main(int argc, char *argv[]) {
  if (CheckInput(argc, argv)) {
    std::string fichero_salida = argv[3];

    std::vector<std::string> fa_input = ReadInputFile(argv[1]);
    Alphabet alphabet = ObtainAlphabet(fa_input[0]);

    std::vector<String> cadenas;
    std::vector<std::string> cadenas_entrada = ReadInputFile(argv[2]);
    for (unsigned int index = 0; index < cadenas_entrada.size(); index++) {
      String string(alphabet, cadenas_entrada[index]);
      cadenas.push_back(string);
    }

    int number_states = stoi(fa_input[1]);
    if (int(fa_input.size() - 3) < number_states) {
      std::cout << "El número de transiciones no es correcto." << std::endl;
      exit(1);
    }
    int inicial_state = 0;
    if (fa_input[2].size() == 1) {
      inicial_state = stoi(fa_input[2]);
    } else {
      std::cout << "El número de states iniciales es mayor que uno." << std::endl;
      exit(1);
    }

    std::vector<State> states;
    for (int index = 0; index < number_states; index++) {
      std::string id_state = std::to_string(index);
      if (index == inicial_state) {
        State state(id_state, true, false);
        states.push_back(state);
      } else {
        State state(id_state, false, false);
        states.push_back(state);
      }
    }
    std::vector<Transition> transitions = ExtractTransitions(fa_input, states, alphabet);
    FiniteAutomata FiniteAutomata(states, transitions, alphabet);
    std::cout << "--- Finite Automata ---" << std::endl << FiniteAutomata << std::endl;

    WriteFile(fichero_salida, cadenas, FiniteAutomata);
  } else {
    std::cout << "Entrada incorrecta" << std::endl;
  }
  return 0;
}