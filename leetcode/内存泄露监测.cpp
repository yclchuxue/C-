#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <mcheck.h>
#include <malloc.h>

using namespace std;

int main()
{
    char *s = NULL;

    mtrace();

    s = (char *)malloc(sizeof(char));

    free(s);

    s = (char *)malloc(sizeof(char)*10);


    muntrace();

    return 0;
}