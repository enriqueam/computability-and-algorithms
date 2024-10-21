#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "change_making.h"
/**
 * @brief Comprueba que los parametros de entrada sean correctos
 * @param argc Numero de parametros de entrada
 * @param argv Vector de parametros de entrada
 * @return true si los parametros son correctos, false en caso contrario
 */
bool CheckInput(int& argc, char* argv[]) {
  std::string help = "-h";
  std::string help_ = "--help";
  if(argc == 2 && (argv[1] == help || argv[1] == help_)) {
      std::cout << "Modo de ejecución: ./change_making 'cuantity'" << std::endl;
      std::cout << "'cuantity' es un número real positivo y representa la cantidad de dinero a devolver." << std::endl;
      std::cout << "Ejemplo: ./change_making 1.23" << std::endl;
  } else if (argc == 2) { 
    float cuantity = std::stof(argv[1]);
    if (cuantity < 0) {
      std::cout << "Ejecute para más información: ./change_making --help || ./change_making -h" << std::endl;
      return false;
    } else {
      return true;
    }
  } else if (argc == 3) { 
    float cuantity = std::stof(argv[2]);
    if (cuantity < 0) {
      std::cout << "Ejecute para más información: ./change_making --help || ./change_making -h" << std::endl;
      return false;
    } else {
      return true;
    }
  } else {
    std::cout << "Los parámetros de entrada no son correctos." << std::endl;
    std::cout << "Ejecute para más información: ./change_making --help || ./change_making -h" << std::endl;
    return false;
  }
  return false;
}

void Menu(int argc, char *argv[]) {
  std::cout << std::endl << "---------------------" << std::endl;
  std::cout << "Change Making problem" << std::endl;
  std::cout << "---------------------" << std::endl;
  if (argc == 2) {
    float cuantity = std::stof(argv[1]);
    ChangeMaking change_making(cuantity);
    change_making.GreedyAlgorithm();
    std::cout << change_making;
  } else if (argc == 3) {
    std::string option = argv[1];
    float cuantity = std::stof(argv[2]);
    ChangeMaking change_making(cuantity);
    if (option == "-o") {
      change_making.ImprovedGreedyAlgorithm();
      std::cout << change_making;
    }
    if (option == "-b") {
      change_making.GreedyAlgorithmWithBanknotes();
      std::cout << change_making;    
    }
  }
}

/**
 * @brief Entry point of the program
 * @param argc Number of arguments
 * @param argv Vector of arguments
*/
int main(int argc, char *argv[]) {
  if (!CheckInput(argc, argv)) {
    return 1;
  } 
  Menu(argc, argv);
  return 0;
}