// Copyright 2016 Baydina Olya


#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/TStackApp.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class TStackAppTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    TStackApp app_;
    string output_;
};

TEST_F(TStackAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a stack application\\..*");
}

TEST_F(TStackAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "push", "2", "3" };

    Act(args);

    Assert("ERROR: Should be 2 or 3 arguments\\..*");
}

TEST_F(TStackAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "push", "pi"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(TStackAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "kek" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(TStackAppTest, Can_Push) {
    vector<string> args = { "push", "3" };

    Act(args);

    Assert("element pushed");
}
