#include <stdio.h>
#include <stdlib.h>
#include "Integer.h"
int main(int argc, char*argv[]) {
    struct Integer integer = Integer.new(5);
    integer.print(&integer);
    return 0;
}