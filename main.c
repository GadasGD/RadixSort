// Radix Sort in C

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h> 

int getMax(int array[], int n)
{
    int max = array[0];
    for (int i = 1; i < n; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

void countingSort(int array[], int size, int place)
{
    int output[size + 1];
    int max = (array[0] / place) % 10;

    for (int i = 1; i < size; i++)
    {
        if (((array[i] / place) % 10) > max)
            max = array[i];
    }
    int count[max + 1];

    for (int i = 0; i < max; ++i)
        count[i] = 0;

    for (int i = 0; i < size; i++)
        count[(array[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
        array[i] = output[i];
}

void radixsort(int array[], int size)
{
    int max = getMax(array, size);

    for (int place = 1; max / place > 0; place *= 10)
        countingSort(array, size, place);
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}
void RandomArr(int arr[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100000;
    }
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{   
    double start_time = wtime();
    int n = 1000000;
    printf("size = %d\n", n);
    int array[n];
    RandomArr(array, n);
    radixsort(array, n);
    double end_time = wtime();
    printf("%f\n", end_time - start_time);
    // printArray(array, n);
}