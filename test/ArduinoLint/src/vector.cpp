// https://en.cppreference.com/w/cpp/container/vector

#include <vector>

template <typename T>
void CheckType(){}

inline void TestMemberTypes()
{
    CheckType<typename std::vector<int>::value_type            >();
    CheckType<typename std::vector<int>::allocator_type        >();
    CheckType<typename std::vector<int>::size_type             >();
    CheckType<typename std::vector<int>::difference_type       >();
    CheckType<typename std::vector<int>::reference             >();
    CheckType<typename std::vector<int>::const_reference       >();
    CheckType<typename std::vector<int>::pointer               >();
    CheckType<typename std::vector<int>::const_pointer         >();
    CheckType<typename std::vector<int>::iterator              >();
    CheckType<typename std::vector<int>::const_iterator        >();
    CheckType<typename std::vector<int>::reverse_iterator      >();
    CheckType<typename std::vector<int>::const_reverse_iterator>();
}

inline void TestMemberFunctions()
{
    // constructor https://en.cppreference.com/w/cpp/container/vector/vector
    std::vector<int> v1;
    const std::vector<int> v2;        
    std::vector<int>(100);     
    std::vector<int>(100, 100);
    std::vector<int>{ v1 };
    std::vector<int>(v1.begin(), v1.end());
    std::vector<int> v3;    
    std::vector<int>(std::move(v3));
    std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // destructor https://en.cppreference.com/w/cpp/container/vector/~vector
    v1.~vector();

    // operator= https://en.cppreference.com/w/cpp/container/vector/operator%3D
    v1 = v2;
    v1 = std::move(v2);

    // assign https://en.cppreference.com/w/cpp/container/vector/assign
    v1.assign(100, 100);
    v1.assign(v2.begin(), v2.end());
    v1.assign({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    // get_allocator https://en.cppreference.com/w/cpp/container/vector/get_allocator
    v1.get_allocator();

    // at https://en.cppreference.com/w/cpp/container/vector/at
    v1.at(0);
    v2.at(0);

    // operator[] https://en.cppreference.com/w/cpp/container/vector/operator_at
    v1[0];
    v2[0];

    // front https://en.cppreference.com/w/cpp/container/vector/front
    v1.front();
    v2.front();

    // back https://en.cppreference.com/w/cpp/container/vector/back
    v1.back();
    v2.back();

    // data https://en.cppreference.com/w/cpp/container/vector/data
    v1.data();
    v2.data();

    // begin https://en.cppreference.com/w/cpp/container/vector/begin
    v1.begin();
    v2.begin();

    // cbegin https://en.cppreference.com/w/cpp/container/vector/cbegin
    v1.cbegin();
    v2.cbegin();

    // end https://en.cppreference.com/w/cpp/container/vector/end
    v1.end();
    v2.end();

    // cend https://en.cppreference.com/w/cpp/container/vector/cend
    v1.cend();
    v2.cend();

    // rbegin https://en.cppreference.com/w/cpp/container/vector/rbegin
    v1.rbegin();
    v2.rbegin();

    // crbegin https://en.cppreference.com/w/cpp/container/vector/crbegin
    v1.crbegin();
    v2.crbegin();

    // rend https://en.cppreference.com/w/cpp/container/vector/rend
    v1.rend();
    v2.rend();

    // crend https://en.cppreference.com/w/cpp/container/vector/crend
    v1.crend();
    v2.crend();

    // empty https://en.cppreference.com/w/cpp/container/vector/empty
    v1.empty();

    // size https://en.cppreference.com/w/cpp/container/vector/size
    v1.size();

    // max_size https://en.cppreference.com/w/cpp/container/vector/max_size
    // v1.max_size();  // todo

    // reserve https://en.cppreference.com/w/cpp/container/vector/reserve
    v1.reserve(100);

    // capacity https://en.cppreference.com/w/cpp/container/vector/capacity
    v1.capacity();

    // shrink_to_fit https://en.cppreference.com/w/cpp/container/vector/shrink_to_fit
    v1.shrink_to_fit();

    // clear https://en.cppreference.com/w/cpp/container/vector/clear
    v1.clear();

    // insert https://en.cppreference.com/w/cpp/container/vector/insert
    v1.insert(v1.begin(), 100);
    v1.insert(v1.begin(), 100, 100);
    v1.insert(v1.begin(), v2.begin(), v2.end());
    v1.insert(v1.begin(), {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

    // emplace https://en.cppreference.com/w/cpp/container/vector/emplace
    v1.emplace(v1.begin(), 100);

    // erase https://en.cppreference.com/w/cpp/container/vector/erase
    v1.erase(v1.begin());
    v1.erase(v1.begin(), v1.end());

    // push_back https://en.cppreference.com/w/cpp/container/vector/push_back
    v1.push_back(100);

    // emplace_back https://en.cppreference.com/w/cpp/container/vector/emplace_back
    v1.emplace_back(100);

    // pop_back https://en.cppreference.com/w/cpp/container/vector/pop_back
    v1.pop_back();

    // resize https://en.cppreference.com/w/cpp/container/vector/resize
    v1.resize(100);

    // swap https://en.cppreference.com/w/cpp/container/vector/swap
    v1.swap(v3);
}

inline void TestNonMemberFunctions()
{
    // operator== https://en.cppreference.com/w/cpp/container/vector/operator_cmp
    std::vector<int> v1;
    const std::vector<int> v2;
    v1 == v2;
    v1 == std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // operator!= https://en.cppreference.com/w/cpp/container/vector/operator_cmp
    v1 != v2;
    v1 != std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // operator< https://en.cppreference.com/w/cpp/container/vector/operator_cmp
    v1 < v2;
    v1 < std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // operator<= https://en.cppreference.com/w/cpp/container/vector/operator_cmp
    v1 <= v2;
    v1 <= std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // operator> https://en.cppreference.com/w/cpp/container/vector/operator_cmp
    v1 > v2;
    v1 > std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // operator>= https://en.cppreference.com/w/cpp/container/vector/operator_cmp
    v1 >= v2;
    v1 >= std::vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // swap https://en.cppreference.com/w/cpp/container/vector/swap2
    std::vector<int> v3;
    std::swap(v1, v3);
}