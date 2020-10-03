#include "test_runner.h"

using namespace std;

void Assert(bool b, string msg) {
  AssertEqual(b, true, msg);
}
