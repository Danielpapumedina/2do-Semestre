// Proyecto2do_Algoritmo_de_Busqueda.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int arr[], int n, int exp) {
    int* output = new int[n];
    int count[10] = { 0 };

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        return binarySearch(arr, mid + 1, right, target);
    }

    return -1;
}

int main() {
    const int size = 100;
    int arr[size];
    int opcion;
    int busqueda;
    

    // Generar números aleatorios
    srand(time(NULL));
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 200;

    cout << "Arreglo original: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "¿Con que metodo quieres ordenar los numeros? \n 1-MergeSort \n 2-RadixSort \n 3-ShellSort \n";
    cin >> opcion;
    switch ( opcion)
    {

    case 1:
            // MergeSort
            mergeSort(arr, 0, size - 1);
        cout << "MergeSort: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
        break;

    case 2:
        // Radix Sort
        radixSort(arr, size);
        cout << "Radix Sort: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
        break;
    case 3:
        // ShellSort
        shellSort(arr, size);
        cout << "ShellSort: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
        break;

    default:
        break;

    } 

    cout << "Que tipo de busqueda quieres utilizar?\n 1-Secuencial\n 0-Binario\n";
        cin >> busqueda; 
        int target = arr[rand() % size];
        cout << "Que numero quieres encontrar?\n";
        cin >> target;


        if (busqueda == 1) {
            int sequentialIndex = sequentialSearch(arr, size, target);
            if (sequentialIndex != -1)
                cout << "Busqueda Secuencial: El elemento " << target << " se encuentra en el indice " << sequentialIndex << endl;
            else
                cout << "Busqueda Secuencial: El elemento " << target << " no se encontro en el arreglo" << endl;

        }
        else
        {
            int binaryIndex = binarySearch(arr, 0, size - 1, target);
            if (binaryIndex != -1)
                cout << "Busqueda Binaria: El elemento " << target << " se encuentra en el indice " << binaryIndex << endl;
            else
                cout << "Busqueda Binaria: El elemento " << target << " no se encontro en el arreglo" << endl;
        }

    // Búsqueda Secuencial
     // Seleccionar un elemento aleatorio del arreglo como objetivo
    

    // Búsqueda Binaria (requiere arreglo ordenado)
   

    return 0;
}
