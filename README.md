# UdonArduinoSTL

[EASTL](https://github.com/electronicarts/EASTL), [LLVM libc++](https://github.com/llvm/llvm-project/tree/main/libcxx/include) から移植された Arduino 用 C++ STL

## Usage

-   追加

    ライブラリを保存するディレクトリを調べライブラリを追加します。

    > 既定値: `~/Documents/Arduino/libraries`
    >
    > 変更している場合: `ファイル > 環境設定 > スケッチブックの保存場所欄` + `/libraries`

    > ```sh
    > # 調べたディレクトリに移動
    > cd ~/Documents/Arduino/libraries
    >
    > # ライブラリクローン
    > git clone https://github.com/udonrobo/UdonArduinoSTL.git
    > ```

-   更新

    > ```sh
    > # 追加する時に調べたlibrariesディレクトリに移動
    > cd ~/Documents/Arduino/libraries/UdonArduinoSTL
    >
    > # ライブラリを更新
    > git pull
    > ```

-   STL 使用方法

    ArduinoIDE では `vector` のような拡張子がないファイルを直接インクルードすることができません。(Arduino 1.8.19 現在)

    インクルードできるようにするには、ライブラリと同じ階層にあるファイルをインクルードしておく必要があり、 `UdonArduinoSTL.hpp` を最初にインクルードします。

    使用方法は C++ のリファレンス等を参照ください。[cpprefjp](https://cpprefjp.github.io/reference.html) [cppreference](https://en.cppreference.com/w/)

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

## 使用可能なヘッダー

現在移植中です。

マルチスレッド、非同期処理、RTTI、例外を扱うファイルは使用できません。

```cpp
// 言語サポート
#include <limits>
#include <new>
#include <source_location>
#include <initializer_list>
// #include <typeinfo>   // unsupported RTTI
// #include <exception>   // unsupported exception
// #include <version>
// #include <compare>
// #include <coroutine>


// コンセプト
// #include <concepts>


// 診断
// #include <stdexcept>   // unsupported exception
// #include <system_error>   // unsupported os error


//ユーティリティ
#include <utility>
#include <bitset>
#include <ratio>
#include <tuple>
#include <optional>
#include <variant>
#include <any>
#include <type_traits>
#include <functional>
#include <memory>
#include <scoped_allocator>
#include <memory_resource>
#include <chrono>
#include <execution>
#include <format>
// #include <stacktrace>
// #include <charconv>
// #include <typeindex>   // unsupported RTTI


// 文字列
#include <string>
#include <string_view>


// ローカライズ
#include <locale>


// コンテナ
#include <array>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <span>
// #include <forward_list>


// イテレーター
#include <iterator>


// レンジ
#include <ranges>


// アルゴリズム
#include <algorithm>


// 数値
#include <complex>
#include <bit>
#include <random>
#include <valarray>
#include <numeric>
#include <numbers>


// 入出力ストリーム
#include <iosfwd>
#include <iostream>
#include <ios>
#include <streambuf>
#include <istream>
#include <ostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <filesystem>
// #include <syncstream>
// #include <spanstream>

// 正規表現
#include <regex>


// アトミック
#include <atomic>


// スレッド (unsupported)
// #include <thread>
// #include <mutex>
// #include <future>
// #include <condition_variable>
// #include <stop_token>
// #include <semaphore>
// #include <shared_mutex>
// #include <barrier>
// #include <latch>

// C言語互換
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <cinttypes>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cuchar>
#include <cwchar>
#include <cwctype>
```

## 変更

-   プラットフォームに各種マイコンを追加

-   C++11 のコンパイラを使用するマイコンがあるため変更

    -   変数テンプレート

        > 例
        >
        > ```cpp
        > std::is_array_v<T>  // ~C++14
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
        > decltype(auto) hoge()  // ~C++14
        > {
        >     return hoge_impl();
        > }
        > ```
        >
        > ↓
        >
        > ```cpp
        > auto hoge() -> decltype(hoge_impl())
        > {
        >     return hoge_impl();
        > }
        > ```

-   chrono を使用して時間を取得できるよう変更

    [./src/EASTL/chrono.h](./src/EASTL/chrono.h) L567 GetTicks メンバに `micros()` を使用した時間取得処理を追加
