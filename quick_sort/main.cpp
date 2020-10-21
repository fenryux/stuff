#include <iostream>
#include <vector>
#include <time.h>
#include <chrono>

void quicksort(int* array, int begin, int end);
int compare(const void* x1, const void* x2);

int main() {
    srand(time(NULL));

    int size;
    std::cout << "Enter size: ";
    std::cin >> size;

    int* array = new int[size];
    for(int i=0;i<size;i++){
        if(size <= 500)
            array[i] = std::rand()%1000+100;
        else 
            array[i] = std::rand()%10000+1000;
    }
    
    for(int i=0;i<size;i++)
        std::cout << array[i] << ' ';
    std::cout << std::endl;

    //std::qsort(array,size,sizeof(int),compare);
    const std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    quicksort(array,0,size-1);
    // std::qsort(array,size,sizeof(int),compare);
    const std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    
    for(int i=0;i<size;i++)
        std::cout << array[i] << ' ';
    std::cout << std::endl;

    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << std::endl;

    delete[] array;
    system("pause");
    return 0;
}

void quicksort(int* array, int begin, int end){
    int left = begin;
    int right = end;

    int pivot = array[(left + (right-1))/2];

    do {
        while(array[left] < pivot) // нахождение элемента больше среднего
            left++;
        while(array[right] > pivot) // нахождение элемента меньше среднего
            right--;
        if(left <= right){ // смена элементов массива местами
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    } while(left<=right);

    if(begin < right)
        quicksort(array,begin,right);
    if(left<end)
        quicksort(array, left, end);
}

int compare(const void* x1, const void* x2){
    return (*(int*)x1 - *(int*)x2);
}