# DREGX

## Overview

DREGX is a Regex Fuzzer and Analyzer for C++. There are little regex fuzzers and analyzers for C++ which allow the user to deeply understand relations between various regexes. DREGX makes it easy to understand and test regexes.

## How to install DREGX?

DREGX uses CMake for installation. Make sure you have the latest version of CMake installed. You can install it here: https://cmake.org/download/

```bash
git clone https://github.com/Deruago/DREGX
cd ./DREGX
mkdir build
cd build
cmake ..
cmake --build . --target install
```

## Examples

### Get minimal match

```C++
#include "Deamer/DREGX/Fuzzer.h"
#include <iostream>

int main()
{
    auto fuzzer = ::deamer::dregx::Fuzzer();
    fuzzer.SetRegex("[a-zA-Z]+");
    auto example = fuzzer.GetMinimalExample();
    
    // output: a
    std::cout << "output: " << example << "\n"; 
    
    return 0;
}
```

### Check if some regex is subset of other regex

```C++
#include "Deamer/DREGX/Analyzer.h"
#include <iostream>

int main()
{
    auto analyzer = ::deamer::dregx::Analyzer();
    analyzer.SetRegex("[a]+");
    bool isSubset = analyzer.IsRegexSubsetOf("[a-zA-Z]+");
    
    // output: true
    std::cout << std::boolalpha;
    std::cout << "output: " << isSubset << "\n"; 
    
    return 0;
}
```

### 