#include <vector>
#include <functional>

template <typename T>
class QuickSort {
public:
    static void sort(std::vector<T>& arr, std::function<bool(T, T)> compare) {
        quickSort(arr, 0, arr.size() - 1, compare);
    }

private:
    static void quickSort(std::vector<T>& arr, int low, int high, std::function<bool(T, T)> compare) {
        if (low < high) {
            int pi = partition(arr, low, high, compare);

            quickSort(arr, low, pi - 1, compare);
            quickSort(arr, pi + 1, high, compare);
        }
    }

    static int partition(std::vector<T>& arr, int low, int high, std::function<bool(T, T)> compare) {
        T pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (!compare(arr[j], pivot)) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }

        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
};
