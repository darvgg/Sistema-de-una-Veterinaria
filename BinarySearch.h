#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BinarySearch {
public:
    // Constructor
    BinarySearch(const vector<T>& sortedArray);

    // Método para buscar un elemento en el array
    int search(const T& target);

private:
    // Array ordenado
    vector<T> sortedArray;

    // Función auxiliar para realizar la búsqueda binaria
    int binarySearch(const T& target, int low, int high);
};

// Implementación del constructor
template <typename T>
BinarySearch<T>::BinarySearch(const vector<T>& sortedArray) : sortedArray(sortedArray) {}

// Implementación del método de búsqueda
template <typename T>
int BinarySearch<T>::search(const T& target) {
    return binarySearch(target, 0, sortedArray.size() - 1);
}

// Implementación de la búsqueda binaria
template <typename T>
int BinarySearch<T>::binarySearch(const T& target, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Si el elemento en la posición media es igual al objetivo, se encontró el elemento
        if (sortedArray[mid] == target) {
            return mid;
        }

        // Si el objetivo es mayor, ignoramos la mitad izquierda
        if (sortedArray[mid] < target) {
            low = mid + 1;
        }
        // Si el objetivo es menor, ignoramos la mitad derecha
        else {
            high = mid - 1;
        }
    }

    // Si llegamos aquí, el elemento no está en el array
    return -1;
}
