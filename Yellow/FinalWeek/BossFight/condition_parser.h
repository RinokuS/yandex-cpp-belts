#include <iostream>
#include <memory>
#include <sstream>

#include "node.h"

#pragma once

using namespace std;

shared_ptr<Node> ParseCondition(istream &is);
