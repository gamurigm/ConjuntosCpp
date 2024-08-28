#include <iostream>
#include "Conjunto.h"

int main() {
    // Crear dos conjuntos de enteros
    Conjunto<int> conjuntoA;
    Conjunto<int> conjuntoB;

    // Agregar elementos al conjunto A
    conjuntoA.agregarElemento(1);
    conjuntoA.agregarElemento(2);
    conjuntoA.agregarElemento(3);
    conjuntoA.agregarElemento(4);

    // Agregar elementos al conjunto B
    conjuntoB.agregarElemento(3);
    conjuntoB.agregarElemento(4);
    conjuntoB.agregarElemento(5);
    conjuntoB.agregarElemento(6);

    // Mostrar los elementos de A
    std::cout << "Conjunto A: ";
    conjuntoA.mostrarElementos();

    // Mostrar los elementos de B
    std::cout << "Conjunto B: ";
    conjuntoB.mostrarElementos();

    // Unión de A y B
    Conjunto<int> unionAB = conjuntoA.obtenerUnion(conjuntoB);
    std::cout << "Union de A y B: ";
    unionAB.mostrarElementos();

    // Intersección de A y B
    Conjunto<int> interseccionAB = conjuntoA.obtenerInterseccion(conjuntoB);
    std::cout << "Interseccion de A y B: ";
    interseccionAB.mostrarElementos();

    // Diferencia A - B
    Conjunto<int> diferenciaAB = conjuntoA.obtenerDiferencia(conjuntoB);
    std::cout << "Diferencia A - B: ";
    diferenciaAB.mostrarElementos();

    // Diferencia Simétrica de A y B
    Conjunto<int> diferenciaSimetricaAB = conjuntoA.obtenerDiferenciaSimetrica(conjuntoB);
    std::cout << "Diferencia Simetrica de A y B: ";
    diferenciaSimetricaAB.mostrarElementos();

    // Verificar si A es subconjunto de B
    bool esSubconjunto = conjuntoA.esSubconjunto(conjuntoB);
    std::cout << "A es subconjunto de B? " << (esSubconjunto ? "Si" : "No") << std::endl;

    // Verificar si A es igual a B
    bool sonIguales = conjuntoA.esIgual(conjuntoB);
    std::cout << "A es igual a B? " << (sonIguales ? "Si" : "No") << std::endl;

    return 0;
}
