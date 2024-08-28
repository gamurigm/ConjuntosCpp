#include "Conjunto.h"
#include <algorithm> // Para std::set_difference y otras funciones de conjunto
#include <iostream>   // Para std::cout

template<typename T>
void Conjunto<T>::agregarElemento(const T& elemento) {
    if (std::find(elementos.begin(), elementos.end(), elemento) == elementos.end()) {
        elementos.push_back(elemento);
    }
}

template<typename T>
void Conjunto<T>::eliminarElemento(const T& elemento) {
    elementos.remove(elemento);
}

template<typename T>
Conjunto<T> Conjunto<T>::obtenerUnion(const Conjunto<T>& otro) const {
    Conjunto<T> resultado = *this;
    for (const T& elem : otro.elementos) {
        resultado.agregarElemento(elem);
    }
    return resultado;
}

template<typename T>
Conjunto<T> Conjunto<T>::obtenerInterseccion(const Conjunto<T>& otro) const {
    Conjunto<T> resultado;
    for (const T& elem : elementos) {
        if (std::find(otro.elementos.begin(), otro.elementos.end(), elem) != otro.elementos.end()) {
            resultado.agregarElemento(elem);
        }
    }
    return resultado;
}

template<typename T>
Conjunto<T> Conjunto<T>::obtenerDiferencia(const Conjunto<T>& otro) const {
    Conjunto<T> resultado;
    for (const T& elem : elementos) {
        if (std::find(otro.elementos.begin(), otro.elementos.end(), elem) == otro.elementos.end()) {
            resultado.agregarElemento(elem);
        }
    }
    return resultado;
}

template<typename T>
Conjunto<T> Conjunto<T>::obtenerDiferenciaSimetrica(const Conjunto<T>& otro) const {
    Conjunto<T> diferenciaAB = this->obtenerDiferencia(otro);
    Conjunto<T> diferenciaBA = otro.obtenerDiferencia(*this);
    return diferenciaAB.obtenerUnion(diferenciaBA);
}

template<typename T>
Conjunto<T> Conjunto<T>::obtenerComplemento(const Conjunto<T>& universo) const {
    return universo.obtenerDiferencia(*this);
}

template<typename T>
bool Conjunto<T>::esSubconjunto(const Conjunto<T>& otro) const {
    for (const T& elem : elementos) {
        if (std::find(otro.elementos.begin(), otro.elementos.end(), elem) == otro.elementos.end()) {
            return false;
        }
    }
    return true;
}

template<typename T>
bool Conjunto<T>::esIgual(const Conjunto<T>& otro) const {
    return this->esSubconjunto(otro) && otro.esSubconjunto(*this);
}

template<typename T>
void Conjunto<T>::mostrarElementos() const {
    for (const T& elem : elementos) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Asegúrate de que la plantilla de función se instancie para los tipos necesarios
template class Conjunto<int>; // Instancia explícita para int
