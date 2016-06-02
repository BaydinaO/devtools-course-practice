// Copyright 2016 Baydina Olya

#ifndef MODULES_TSTACKAPPLICATION_INCLUDE_TSTACKAPP_H_
#define MODULES_TSTACKAPPLICATION_INCLUDE_TSTACKAPP_H_

#include <string>

class TStackApp {
public:
    TStackApp();
    std::string operator()(int argc, const char** argv);

private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int element;
        int operation;
    } Arguments;
};

#endif  // MODULES_TSTACKAPPLICATION_INCLUDE_TSTACKAPP_H_



