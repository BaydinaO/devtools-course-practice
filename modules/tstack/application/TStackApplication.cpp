// Copyright 2016 Baydina Olya


#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/TStackApp.h"

int main(int argc, const char** argv) {
    TStackApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());

    return 0;
}

