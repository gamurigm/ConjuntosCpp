#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <list>
#include <iostream>

template<typename T>
class Conjunto {
private:
    std::list<T> elementos;

public:
    // Agrega un elemento al conjunto si no está presente
    void agregarElemento(const T& elemento);

    // Elimina un elemento del conjunto
    void eliminarElemento(const T& elemento);

    // Retorna un nuevo conjunto que es la unión de este conjunto con otro
    Conjunto<T> obtenerUnion(const Conjunto<T>& otro) const;

    // Retorna un nuevo conjunto que es la intersección de este conjunto con otro
    Conjunto<T> obtenerInterseccion(const Conjunto<T>& otro) const;
#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <list>
#include <iostream>
#include <algorithm>

    template<typename T>
    class Conjunto {
    private:
        std::list<T> elementos;

    public:
        // Agrega un elemento al conjunto si no está presente
        void agregarElemento(const T& elemento) {
            if (std::find(elementos.begin(), elementos.end(), elemento) == elementos.end()) {
                elementos.push_back(elemento);
            }
        }

        // Elimina un elemento del conjunto
        void eliminarElemento(const T& elemento) {
            elementos.remove(elemento);
        }

        // Retorna un nuevo conjunto que es la unión de este conjunto con otro
        Conjunto<T> obtenerUnion(const Conjunto<T>& otro) const {
            Conjunto<T> resultado = *this;
            for (const auto& elem : otro.elementos) {
                resultado.agregarElemento(elem);
            }
            return resultado;
        }

        // Retorna un nuevo conjunto que es la intersección de este conjunto con otro
        Conjunto<T> obtenerInterseccion(const Conjunto<T>& otro) const {
            Conjunto<T> resultado;
            for (const auto& elem : elementos) {
                if (std::find(otro.elementos.begin(), otro.elementos.end(), elem) != otro.elementos.end()) {
                    resultado.agregarElemento(elem);
                }
            }
            return resultado;
        }

        // Retorna un nuevo conjunto que es la diferencia de este conjunto con otro
        Conjunto<T> obtenerDiferencia(const Conjunto<T>& otro) const {
            Conjunto<T> resultado;
            for (const auto& elem : elementos) {
                if (std::find(otro.elementos.begin(), otro.elementos.end(), elem) == otro.elementos.end()) {
                    resultado.agregarElemento(elem);
                }
            }
            return resultado;
        }

        // Retorna un nuevo conjunto que es la diferencia simétrica de este conjunto con otro
        Conjunto<T> obtenerDiferenciaSimetrica(const Conjunto<T>& otro) const {
            Conjunto<T> unionConjunto = obtenerUnion(otro);
            Conjunto<T> interseccionConjunto = obtenerInterseccion(otro);
            return unionConjunto.obtenerDiferencia(interseccionConjunto);
        }

        // Retorna un nuevo conjunto que es el complemento de este conjunto con respecto a un universo dado
        Conjunto<T> obtenerComplemento(const Conjunto<T>& universo) const {
            return universo.obtenerDiferencia(*this);
        }

        // Verifica si este conjunto es un subconjunto de otro
        bool esSubconjunto(const Conjunto<T>& otro) const {
            for (const auto& elem : elementos) {
                if (std::find(otro.elementos.begin(), otro.elementos.end(), elem) == otro.elementos.end()) {
                    return false;
                }
            }
            return true;
        }

        // Verifica si este conjunto es igual a otro (tienen los mismos elementos)
        bool esIgual(const Conjunto<T>& otro) const {
            return esSubconjunto(otro) && otro.esSubconjunto(*this);
        }

        // Muestra todos los elementos del conjunto
        void mostrarElementos() const {
            for (const auto& elem : elementos) {
                std::cout << elem << " ";
            }
            std::cout << std::endl;
        }
    };

#endif // CONJUNTO_H

    // Retorna un nuevo conjunto que es la diferencia de este conjunto con otro
    Conjunto<T> obtenerDiferencia(const Conjunto<T>& otro) const;

    // Retorna un nuevo conjunto que es la diferencia simétrica de este conjunto con otro
    Conjunto<T> obtenerDiferenciaSimetrica(const Conjunto<T>& otro) const;

    // Retorna un nuevo conjunto que es el complemento de este conjunto con respecto a un universo dado
    Conjunto<T> obtenerComplemento(const Conjunto<T>& universo) const;

    // Verifica si este conjunto es un subconjunto de otro
    bool esSubconjunto(const Conjunto<T>& otro) const;

    // Verifica si este conjunto es igual a otro (tienen los mismos elementos)
    bool esIgual(const Conjunto<T>& otro) const;

    // Muestra todos los elementos del conjunto
    void mostrarElementos() const;
};

#endif // CONJUNTO_H
