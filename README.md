# UdonArduinoSTL

GNU libstdc++ から移植された Arduino 用 C++ STL

## 変更

-   プラットフォームに各種マイコンを追加

-   C++11 のコンパイラを使用するマイコンがあるため変更

    -   変数テンプレート

        > 例
        >
        > ```cpp
        > std::is_array_v<T>
        > ```
        >
        > ↓
        >
        > ```cpp
        > std::is_array<T>::value
        > ```

    -   戻り値型推論

        > 例
        >
        > ```cpp
        > template <typename F, typename... Args>
        > EA_CONSTEXPR decltype(auto) invoke(F&& func, Args&&... args) EA_NOEXCEPT_IF(EA_NOEXCEPT_EXPR(invoke_impl(std::forward<F>(func), std::forward<Args>(args)...)))
        > {
        >     return invoke_impl(std::forward<F>(func), std::forward<Args>(args)...);
        > }
        > ```
        >
        > ↓
        >
        > ```cpp
        > template <typename F, typename... Args>
        > EA_CONSTEXPR auto invoke(F&& func, Args&&... args) EA_NOEXCEPT_IF(EA_NOEXCEPT_EXPR(invoke_impl(std::forward<F>(func), std::forward<Args>(args)...)))
        >     -> decltype(invoke_impl(std::forward<F>(func), std::forward<Args>(args)...))
        > {
        >     return invoke_impl(std::forward<F>(func), std::forward<Args>(args)...);
        > }
        > ```

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
