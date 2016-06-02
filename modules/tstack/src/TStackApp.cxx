// Copyright 2016 Baydina Olya

#include "include/TStackApp.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/tstack.h"

TStackApp::TStackApp() : message_("") {}

void TStackApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a stack application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <operation> <element if push>\n\n " +

        "Where element is int-precision number, " +
        "and <operation> is one of 'push', 'pop', 'length'.\n";
}

bool TStackApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc > 3) {
        help(argv[0], "ERROR: Should be 2 or 3 arguments.\n\n");
        return false;
    }
    return true;
}

double parseInt(const char* arg) {
    char* end;
    int value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int parseOperation(const char* arg) {
    int op = 0;
    if (strcmp(arg, "push") == 0) {
        op = 1;
    } else if (strcmp(arg, "pop") == 0) {
        op = 2;
    } else if (strcmp(arg, "length") == 0) {
        op = 3;
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string TStackApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.operation = parseOperation(argv[1]);
        if (args.operation == 1) {
            args.element = parseInt(argv[2]);
        }
    }
    catch (std::string str) {
        return str;
    }

    Stack<int> stack;

    std::ostringstream stream;
    switch (args.operation) {
    case 1:
        stack.push(args.element);
        stream << "element pushed";
        break;
    case 2:
        int result;
        result = stack.top();
        stack.pop();
        stream << "element = " << result << " ";
        break;
    case 3:
        stream << "length = " << stack.getSize() << " ";
        break;
    }

    message_ = stream.str();

    return message_;
}

