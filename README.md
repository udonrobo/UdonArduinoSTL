# UdonArduinoSTL

GNU libstdc++ から移植された Arduino 用 C++ STL

## Usage

```cpp
#include <UdonArduinoSTL.hpp>
#include <vector>

void setup()
{
	std::vector<int> vector;
	vector.push_back(123);
	vector.push_back(456);
	for (auto&& it : vector)
	{
		Serial.print(it), Serial.print('\t');
	}
}

void loop() {}
```

## 現在開発中

-   使用可能なヘッダー

    algorithm

    array

    bitset

    chrono (挙動不明)

    deque

    functional

    initializer_list

    limits

    list

    map

    memory

    numeric

    queue

    ratio

    scoped_allocator

    set

    stack

    string

    tuple

    type_traits

    unordered_map

    unordered_set

    utility

-   現在使用できないヘッダー(todo)

    iostream

    fstream

    iomanip

    ios

    iosfwd

    iterator

    ostream

    random

    regex

    sstream

    streambuf

    locale

    valarray

-   アーキテクチャがサポートしていないため使用できないヘッダー

    -   スレッド、非同期処理

        thread

        future

        mutex

        condition_variable

    -   ラインタイム型情報

        typeindex

    -   例外

        exception

        stdexcept

        system_error
