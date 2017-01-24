// Simple test

#include <stdio.h>

#include "Task.hpp"

unsigned int test_function(int a)
{
    if (a < 0.0)
        return -a;

    return a;
}

int main ()
{
    Task<decltype(test_function)> test_task_1(&test_function);
    Task<unsigned int(int)> test_task_2 = &test_function;
    Task<unsigned int(int)> test_task_3;

    printf ("test_task( 1) = %2u\n", test_task_1(1));
    printf ("test_task( 0) = %2u\n", test_task_2(0));
    printf ("test_task(-1) = %2u\n", test_task_3(-1));

    return 0;
}
