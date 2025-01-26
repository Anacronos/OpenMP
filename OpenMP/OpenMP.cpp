//#include <iostream>
//#include <omp.h>
////#include "pch.h"
//
//int main()
//{
//    std::cout << "Hello World!\n";
//    int threads, tid;
//    #pragma omp parallel private (tid)
//    {
//        tid = omp_get_thread_num();
//        std::cout << "Working on thread: " << tid << std::endl;
//        if (tid == 0)
//        {
//            threads = omp_get_num_threads();
//            std::cout << "Total threads: " << threads << std::endl;
//        }
//    }
//}

//#include "pch.h"
#include <iostream>
#include <omp.h>

#define N 1000
#define chunk 100
#define display 10

void printArray(float* d);

int main()
{
    std::cout << "Adding Arrays in Parallel!\n";
    float a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7;
    }
    int pieces = chunk;

#pragma omp parallel for \
        shared(a, b, c, pieces) private(i) \
        schedule(static, pieces)

    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    std::cout << "Printing the first " << display << " values of array a: " << std::endl;
    printArray(a);
    std::cout << "Printing the first " << display << " values of array b: " << std::endl;
    printArray(b);
    std::cout << "Printing the first " << display << " values of array c: " << std::endl;
    printArray(c);
}

void printArray(float* d)
{
    for (int x = 0; x < display; x++)
    {
        std::cout << d[x] << " - ";
    }
    std::cout << std::endl;
}
