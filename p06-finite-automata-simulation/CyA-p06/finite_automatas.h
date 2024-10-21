// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  finite_automatas.h: funciones de la clase FiniteAutomata.
//    Contiene la declaración de la clase FiniteAutomata.

#include <iostream>
#include <string>
#include <vector>

#include "states.h"
#include "transitions.h"
#include "alphabets.h"
#include "strings.h"

/**
 * @brief Class FiniteAutomata. Represents a finite automata, with a set of 
 * states, a set of transitions, an alphabet. The automata can be determinist 
 * or not, and recive a string to check if it is accepted or not.
 */
class FiniteAutomata {
  public:
    /**
     * @brief Constructor por defecto de la clase.
     */
    FiniteAutomata();

    /**
     * @brief Constructor de la clase FiniteAutomata.
     * 
     * @param states Vector de estados del autómata.
     * @param alphabet Alfabeto del autómata.
     * @param transitions Vector de transiciones del autómata.
     * @param initial_state Estado inicial del autómata.
     */
    FiniteAutomata(std::vector<State>& states, std::vector<Transition>& transitions, Alphabet& alfabeto);
    
    /**
     * @brief Método que resuelve si una cadena es aceptada por el autómata.
     * @param string String a evaluar.
     * @return true si la cadena es aceptada, false en caso contrario.
     */
    bool Resolve(String& input_string);

    /**
     * @brief Método que devuelve un vector con los posibles estados siguientes.
     * @param stete Estado actual.
     * @param symbol Símbolo a evaluar.
     * 
     */
    std::vector<State> Posibilities(const State& state, Symbol& symbol);

    /**
     * @brief Método que comprueba si una cadena es aceptada por el autómata.
     * @param string String a evaluar.
     * @param index_cadena Índice de la cadena.
     * @param state Estado actual.
     */
    bool Comprobar(String& string, unsigned index_cadena, const State& state);

    /**
     * @brief Método que devuelve el resultado de la resolución.
     */
    friend std::ostream& operator<<(std::ostream& os, const FiniteAutomata& FiniteAutomata);
  private:
    /** @brief Vector de estados del autómata. */
    std::vector<State> states_;
    
    /** @brief Vector de transiciones del autómata. */
    std::vector<Transition> transitions_;

    /** @brief Alfabeto del autómata. */
    Alphabet alfabeto_;

    /** @brief Resultado de la resolución. */
    bool result_;
    
    /** @brief Ruta de la resolución. */
    std::string path_;
};