#include "TestSuites.h"

int main() {
    TestMain tester;

    tester.testConstructors();
    tester.testAdd();
    tester.testFind();
    tester.testRemove();
    tester.testResize();

    return 0;
}