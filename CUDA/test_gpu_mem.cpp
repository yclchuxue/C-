#include <iostream>
#include <vector>
#include <algorithm>
#include "cuda_runtime.h"

using namespace std;

int main()
{
    int *qbz;

    int *b = (int *)malloc(sizeof(int));

    *b = 0;

    int *a = (int *)malloc(sizeof(int));

    *a = 100;

    cout << "AAAAAAAAA" << endl;

    auto status = cudaMalloc(&qbz, sizeof(int) * 10);
    if (status != cudaSuccess)
    {
        if (status == cudaErrorInvalidValue)
        {
            cout << "2" << endl;
        }
        if (status == cudaErrorMemoryAllocation)
        {
            cout << "3" << endl;
        }
        fprintf(stderr, "cudaMalloc failed!");
    }

    cout << "BBBBBB" << status << endl;

    status = cudaMemcpy(&qbz[2], &a, sizeof(int), cudaMemcpyHostToDevice);
    if (status != cudaSuccess)
    {
        fprintf(stderr, "cudaMemcpy1 failed!");
        cout << status << endl;
    }

    cout << "DDDDD" << endl;

    // cout << qbz[2] << endl;

    status = cudaMemcpy(&b, &qbz[2], sizeof(int), cudaMemcpyDeviceToHost);
    if (status != cudaSuccess)
    {
        fprintf(stderr, "cudaMemcpy2 failed!");
        cout << status << endl;
    }

    cout << "b = " << *b << endl;

    // cout << qbz[2] << endl;

    // printf("qbz = %d\n", *qbz);

    cudaIpcMemHandle_t *ptr1;

    cout << "CCCC" << endl;

    // status = cudaIpcGetMemHandle(ptr1, (void *)qbz);
    // if (status != cudaSuccess)
    // {
    //     fprintf(stderr, "cudaIpcGetMemHandle failed!");
    //     cout << status << endl;
    // }

    // status = cudaIpcOpenMemHandle((void **)&qbz, *ptr1, cudaIpcMemLazyEnablePeerAccess);
    // if (status != cudaSuccess)
    // {
    //     fprintf(stderr, "cudaIpcOpenMemHandle failed!");
    //     cout << status << endl;
    // }

    // cout << *qbz << endl;

    cudaFree((void *)qbz);
}



//g++ test_gpu_mem.cpp -L /usr/local/cuda/lib64 -lcudart
