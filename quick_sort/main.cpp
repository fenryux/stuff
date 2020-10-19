#include <iostream>
#include <vector>
#include <time.h>

void quicksort(int* array, int begin, int end);

int main() {
    srand(time(NULL));

    int size;
    std::cout << "Enter size: ";
    std::cin >> size;

    int* array = new int[size];
    for(int i=0;i<size;i++)
        array[i] = std::rand()%100+1;
    
    for(int i=0;i<size;i++)
        std::cout << array[i] << ' ';
    std::cout << std::endl;


    clock_t start = clock();
    quicksort(array,0,size-1);
    clock_t end = clock();

    for(int i=0;i<size;i++)
        std::cout << array[i] << ' ';
    std::cout << std::endl;

    printf("Time: %f seconds\n", (double)(end-start));

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
