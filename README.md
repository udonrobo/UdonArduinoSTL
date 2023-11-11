# UdonArduinoSTL

[EASTL](https://github.com/electronicarts/EASTL) [LLVM libc++](https://github.com/llvm/llvm-project/tree/main/libcxx/include) [AVR STL](https://andybrown.me.uk/2011/01/15/the-standard-template-library-stl-for-avr-with-c-streams/) から移植した Arduino 用 C++ STL

## Install

ライブラリを保存するディレクトリを調べクローンします。

既定値: `~/Documents/Arduino/libraries`

見つからない場合: `ファイル > 環境設定 > スケッチブックの保存場所欄` + `/libraries`

> ```sh
> cd ~/Documents/Arduino/libraries
> git clone https://github.com/udonrobo/UdonArduinoSTL.git
> ```

## Update

> ```sh
> cd ~/Documents/Arduino/libraries/UdonArduinoSTL
> git pull
> ```

## Usage

ArduinoIDE で `vector` のような拡張子がない特殊ファイルをインクルードするには、特殊ファイルが含まれるライブラリにある通常ファイルをインクルードしておく必要があります。`UdonArduinoSTL.hpp` を最初にインクルードします。

STLの使用方法はリファレンス等を参照ください。[cpprefjp](https://cpprefjp.github.io/reference.html) [cppreference](https://en.cppreference.com/w/)

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

## Other

C++11~

マルチスレッド、非同期処理、RTTI、例外を扱うファイルは使用できません。