#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "memmory_pool.h"

using namespace std;

int main()
{
    memmory_pool MEM;
    
    char *p1 = MEM.m_malloc(1);

    *p1 = 'a';


/*
    cout << "p1 = " << (unsigned long long)p1<< endl;
    printf("p1 = %p\n", &p1);
*/
    MEM.m_free(p1);

    char *p2 = MEM.m_malloc(1);
    char *p3 = MEM.m_malloc(1);
    char *p4 = MEM.m_malloc(1);
    char *p5 = MEM.m_malloc(1);
    char *p6 = MEM.m_malloc(1);
    char *p7 = MEM.m_malloc(1);
    char *p8 = MEM.m_malloc(1);
    char *p9 = MEM.m_malloc(1);
    //char *p = MEM.m_malloc(1);

    return 0;
}