// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de Autómatas Finitos
// Autor: Enrique Álvarez Mesa
// Correo: alu0101142104@ull.es
// Fecha: 7/11/2022
// Archivo  states.h: funciones de la clase State.
//    Contiene la declaración de la clase State.

#include <iostream>
#include <string>
#include <vector>

# pragma once

/**
 * @brief Class State. Represents a state of a Finite Automata.
 */
class State {
  public:
    /**
     * @brief Constructor por defecto
     */
    State();

    /**
     * @brief Constructor de la clase State
     * @param id Identificador del estado.
     * @param is_initial Indica si el estado es inicial.
     * @param is_final Indica si el estado es final.
     */
    State(std::string& id, bool is_initial, bool is_final);

    /**
     * @brief Método que devuelve el identificador del estado.
     * @return Identificador del estado.
     */
    std::string GetId() const;
    
    /**
     * @brief Método que devuelve si el estado es inicial.
     * @return true si el estado es inicial, false en caso contrario.
     */
    bool GetIsInitial() const;
    
    /**
     * @brief Método que devuelve si el estado es final.
     * @return true si el estado es final, false en caso contrario.
     */
    bool GetIsFinal() const;

    /**
     * @brief Método que modifica el estado final.
     * @param is_final Nuevo estado final.
     */
    void SetIsFinal(bool is_final);
    friend std::ostream& operator<<(std::ostream& os, const State& state);

    /**
     * @brief Método que compara dos estados.
     * @param state Estado a comparar.
     * @return true si los estados son iguales, false en caso contrario.
     */
    bool operator==(const State& State) const;
  private:
    /** @brief Identificador del estado. */
    std::string id_;

    /** @brief Indica si el estado es inicial. */
    bool is_initial_;

    /** @brief Indica si el estado es final. */
    bool is_final_;
};