#include <iostream>
#include "bigint.h"
#include <string>
#include <vector>
#include <chrono>

std::string GenerateRandom(int &size) {
  std::string number;
  for (int index = 0; index < size; index++) {
    number += std::to_string(rand() % 10);
  }
  return number;
}

void EjecuteKartasuba(BigInt &muliplier, BigInt &multiplicand, BigInt &result) {
  std::cout << " * Algoritmo de Karatsuba" << std::endl;
  auto begin = std::chrono::high_resolution_clock::now();
  result = result.Karatsuba(muliplier, multiplicand);
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "Resultado: " << result << std::endl;
  std::cout << "Número de llamadas recursivas: " << result.GetCounter() << std::endl;
  std::cout << "Tiempo de ejecucion = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << "ns" << std::endl;
}

void EjecuteOverload(BigInt &muliplier, BigInt &multiplicand) {
  std::cout << " * Operador sobrecargado" << std::endl;
  auto begin = std::chrono::high_resolution_clock::now();
  BigInt result = muliplier * multiplicand;
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "Resultado: " << result << std::endl;
  std::cout << "Tiempo de ejecucion = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << "ns" << std::endl;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> parameters;
  for (int index = 0; index < argc; index++) {
    std::string parameter = argv[index];
    parameters.push_back(parameter);
  }
  parameters.erase(parameters.begin());
  int parameters_size = parameters.size();

  std::string multiplier;
  std::string multiplicand;
  BigInt result;
  bool random = false, level = false;
  for (int index = 0; index <parameters_size; index++) {
    if (parameters[index] == "-r" && index + 1 <parameters_size && !random) {
      if (std::stoi(parameters[index + 1]) > 0) {
        int size = std::stoi(parameters[index + 1]);
        multiplier = GenerateRandom(size);
        std::cout << "Multiplicador: " << multiplier << std::endl;
        multiplicand = GenerateRandom(size);
        std::cout << "Multiplicando: " << multiplicand << std::endl;
        random = true;
      } else {
        std::cout << "El tamaño debe ser mayor que 0" << std::endl;
        return 0;
      }
    } else if (parameters[index] == "-n" && index + 1 <parameters_size && !level) {
      if (std::stoi(parameters[index + 1]) > 0) {
        int level = std::stoi(parameters[index + 1]);
        result.SetLevel(level);
        level = true;
      } else {
        std::cout << "El nivel debe ser mayor que 0" << std::endl;
        return 0;
      }
    }
  }
  if (!random) {
    std::cout << "Multiplicador: ";
    std::cin >> multiplier;
    std::cout << "Multiplicando: ";
    std::cin >> multiplicand;
  }

  BigInt a(multiplier);
  BigInt b(multiplicand);
  bool execute = false;
  for (int index = 0; index <parameters_size; index++) {
    if (parameters[index] == "-m") {
      EjecuteOverload(a, b);
      execute = true;
    } else if (parameters[index] == "-k") {
      EjecuteKartasuba(a, b, result);
      execute = true;
    }
  }
  if (!execute) {
    EjecuteKartasuba(a, b, result);
  }
  return 0;
}