// https://en.cppreference.com/w/cpp/algorithm

#include <algorithm>
#include <random>

inline void TestNonModifyingSequenceOperations()
{
    int array[100];
    auto begin = std::begin(array);
    auto end = std::end(array);

    // all_of https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
    std::all_of(begin, end, [](const int&){ return true; });
    std::any_of(begin, end, [](const int&){ return true; });
    std::none_of(begin, end, [](const int&){ return true; });

    // for_each https://en.cppreference.com/w/cpp/algorithm/for_each
    std::for_each(begin, end, [](const int&){});

    // count https://en.cppreference.com/w/cpp/algorithm/count
    std::count(begin, end, 0);

    // count_if https://en.cppreference.com/w/cpp/algorithm/count
    std::count_if(begin, end, [](const int&){ return true; });

    // mismatch https://en.cppreference.com/w/cpp/algorithm/mismatch
    std::mismatch(begin, end, begin);
    std::mismatch(begin, end, begin, [](const int&, const int&) { return true; });

    // equal https://en.cppreference.com/w/cpp/algorithm/equal
    std::equal(begin, end, begin);
    std::equal(begin, end, begin, [](const int&, const int&) { return true; });

    // find https://en.cppreference.com/w/cpp/algorithm/find
    std::find(begin, end, 0);

    // find_if https://en.cppreference.com/w/cpp/algorithm/find
    std::find_if(begin, end, [](const int&){ return true; });

    // find_if_not https://en.cppreference.com/w/cpp/algorithm/find
    std::find_if_not(begin, end, [](const int&){ return true; });

    // find_end https://en.cppreference.com/w/cpp/algorithm/find_end
    std::find_end(begin, end, begin, end);

    // find_first_of https://en.cppreference.com/w/cpp/algorithm/find_first_of
    std::find_first_of(begin, end, begin, end);

    // adjacent_find https://en.cppreference.com/w/cpp/algorithm/adjacent_find
    std::adjacent_find(begin, end);

    // search https://en.cppreference.com/w/cpp/algorithm/search
    std::search(begin, end, begin, end);

    // search_n https://en.cppreference.com/w/cpp/algorithm/search_n
    std::search_n(begin, end, 0, 0);

    // copy https://en.cppreference.com/w/cpp/algorithm/copy
    std::copy(begin, end, begin);

    // copy_if https://en.cppreference.com/w/cpp/algorithm/copy
    std::copy_if(begin, end, begin, [](const int&){ return true; });

    // copy_n https://en.cppreference.com/w/cpp/algorithm/copy
    std::copy_n(begin, 0, begin);

    // copy_backward https://en.cppreference.com/w/cpp/algorithm/copy_backward
    std::copy_backward(begin, end, end);

    // move https://en.cppreference.com/w/cpp/algorithm/move
    std::move(begin, end, begin);

    // move_backward https://en.cppreference.com/w/cpp/algorithm/move_backward
    std::move_backward(begin, end, end);

    // fill https://en.cppreference.com/w/cpp/algorithm/fill
    std::fill(begin, end, 0);

    // fill_n https://en.cppreference.com/w/cpp/algorithm/fill_n
    std::fill_n(begin, 0, 0);

    // transform https://en.cppreference.com/w/cpp/algorithm/transform
    std::transform(begin, end, begin, [](const int&){ return 0; });

    // generate https://en.cppreference.com/w/cpp/algorithm/generate
    std::generate(begin, end, []{ return 0; });

    // generate_n https://en.cppreference.com/w/cpp/algorithm/generate_n
    std::generate_n(begin, 0, []{ return 0; });

    // remove https://en.cppreference.com/w/cpp/algorithm/remove
    std::remove(begin, end, 0);

    // remove_if https://en.cppreference.com/w/cpp/algorithm/remove
    std::remove_if(begin, end, [](const int&){ return true; });

    // remove_copy https://en.cppreference.com/w/cpp/algorithm/remove_copy
    std::remove_copy(begin, end, begin, 0);

    // remove_copy_if https://en.cppreference.com/w/cpp/algorithm/remove_copy
    std::remove_copy_if(begin, end, begin, [](const int&){ return true; });

    // replace https://en.cppreference.com/w/cpp/algorithm/replace
    std::replace(begin, end, 0, 0);

    // replace_if https://en.cppreference.com/w/cpp/algorithm/replace
    std::replace_if(begin, end, [](const int&){ return true; }, 0);

    // replace_copy https://en.cppreference.com/w/cpp/algorithm/replace_copy
    std::replace_copy(begin, end, begin, 0, 0);

    // replace_copy_if https://en.cppreference.com/w/cpp/algorithm/replace_copy
    std::replace_copy_if(begin, end, begin, [](const int&){ return true; }, 0);

    // swap https://en.cppreference.com/w/cpp/algorithm/swap
    std::swap(begin, end);

    // swap_ranges https://en.cppreference.com/w/cpp/algorithm/swap_ranges
    std::swap_ranges(begin, end, begin);

    // iter_swap https://en.cppreference.com/w/cpp/algorithm/iter_swap
    std::iter_swap(begin, begin);

    // reverse https://en.cppreference.com/w/cpp/algorithm/reverse
    std::reverse(begin, end);

    // reverse_copy https://en.cppreference.com/w/cpp/algorithm/reverse_copy
    std::reverse_copy(begin, end, begin);

    // rotate https://en.cppreference.com/w/cpp/algorithm/rotate
    std::rotate(begin, begin, end);

    // rotate_copy https://en.cppreference.com/w/cpp/algorithm/rotate_copy
    std::rotate_copy(begin, begin, end, begin);

    // random_shuffle https://en.cppreference.com/w/cpp/algorithm/random_shuffle
    // std::random_shuffle(begin, end, std::random_device()); todo: random_device not supported

    // shuffle https://en.cppreference.com/w/cpp/algorithm/shuffle
    // std::shuffle(begin, end, std::random_device());  todo: random_device not supported

    // unique https://en.cppreference.com/w/cpp/algorithm/unique
    std::unique(begin, end);

    // unique_copy https://en.cppreference.com/w/cpp/algorithm/unique_copy
    // std::unique_copy(begin, end, begin);

    // is_partitioned https://en.cppreference.com/w/cpp/algorithm/is_partitioned
    // std::is_partitioned(begin, end, [](const int&){ return true; });

    // partition https://en.cppreference.com/w/cpp/algorithm/partition
    // std::partition(begin, end, [](const int&){ return true; });

    // stable_partition https://en.cppreference.com/w/cpp/algorithm/stable_partition
    // std::stable_partition(begin, end, [](const int&){ return true; });

    // partition_copy https://en.cppreference.com/w/cpp/algorithm/partition_copy
    // std::partition_copy(begin, end, begin, begin, [](const int&){ return true; });

    // partition_point https://en.cppreference.com/w/cpp/algorithm/partition_point
    // std::partition_point(begin, end, [](const int&){ return true; });

    // is_sorted https://en.cppreference.com/w/cpp/algorithm/is_sorted
    // std::is_sorted(begin, end);

    // is_sorted_until https://en.cppreference.com/w/cpp/algorithm/is_sorted_until
    // std::is_sorted_until(begin, end);

    // sort https://en.cppreference.com/w/cpp/algorithm/sort
    // std::sort(begin, end);

    // partial_sort https://en.cppreference.com/w/cpp/algorithm/partial_sort
    // std::partial_sort(begin, end, end);

    // partial_sort_copy https://en.cppreference.com/w/cpp/algorithm/partial_sort_copy
    // std::partial_sort_copy(begin, end, begin, end);

    // stable_sort https://en.cppreference.com/w/cpp/algorithm/stable_sort
    // std::stable_sort(begin, end);

    // nth_element https://en.cppreference.com/w/cpp/algorithm/nth_element
    // std::nth_element(begin, begin, end);

    // lower_bound https://en.cppreference.com/w/cpp/algorithm/lower_bound
    std::lower_bound(begin, end, 0);

    // upper_bound https://en.cppreference.com/w/cpp/algorithm/upper_bound
    std::upper_bound(begin, end, 0);

    // binary_search https://en.cppreference.com/w/cpp/algorithm/binary_search
    std::binary_search(begin, end, 0);

    // equal_range https://en.cppreference.com/w/cpp/algorithm/equal_range
    std::equal_range(begin, end, 0);

    // merge https://en.cppreference.com/w/cpp/algorithm/merge
    // std::merge(begin, end, begin, end, begin);

    // inplace_merge https://en.cppreference.com/w/cpp/algorithm/inplace_merge
    // std::inplace_merge(begin, begin, end);

    // includes https://en.cppreference.com/w/cpp/algorithm/includes
    // std::includes(begin, end, begin, end);

    // set_difference https://en.cppreference.com/w/cpp/algorithm/set_difference
    std::set_difference(begin, end, begin, end, begin);

    // set_intersection https://en.cppreference.com/w/cpp/algorithm/set_intersection
    std::set_intersection(begin, end, begin, end, begin);

    // set_symmetric_difference https://en.cppreference.com/w/cpp/algorithm/set_symmetric_difference
    std::set_symmetric_difference(begin, end, begin, end, begin);

    // set_union https://en.cppreference.com/w/cpp/algorithm/set_union
    std::set_union(begin, end, begin, end, begin);

    // is_heap https://en.cppreference.com/w/cpp/algorithm/is_heap
    // std::is_heap(begin, end);

    // is_heap_until https://en.cppreference.com/w/cpp/algorithm/is_heap_until
    // std::is_heap_until(begin, end);

    // make_heap https://en.cppreference.com/w/cpp/algorithm/make_heap
    // std::make_heap(begin, end);

    // push_heap https://en.cppreference.com/w/cpp/algorithm/push_heap
    // std::push_heap(begin, end);

    // pop_heap https://en.cppreference.com/w/cpp/algorithm/pop_heap
    // std::pop_heap(begin, end);

    // sort_heap https://en.cppreference.com/w/cpp/algorithm/sort_heap
    // std::sort_heap(begin, end);

    // min https://en.cppreference.com/w/cpp/algorithm/min
    std::min(0, 0);
    std::min(0, 0, [](const int&, const int&){ return true; });
    std::min({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

    // max https://en.cppreference.com/w/cpp/algorithm/max
    std::max(0, 0);
    std::max(0, 0, [](const int&, const int&){ return true; });
    std::max({0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

    // minmax https://en.cppreference.com/w/cpp/algorithm/minmax
    std::minmax(0, 0);
    std::minmax(0, 0, [](const int&, const int&){ return true; });

    // min_element https://en.cppreference.com/w/cpp/algorithm/min_element
    std::min_element(begin, end);
    std::min_element(begin, end, [](const int&, const int&){ return true; });

    // max_element https://en.cppreference.com/w/cpp/algorithm/max_element
    std::max_element(begin, end);
    std::max_element(begin, end, [](const int&, const int&){ return true; });

    // minmax_element https://en.cppreference.com/w/cpp/algorithm/minmax_element
    std::minmax_element(begin, end);
    std::minmax_element(begin, end, [](const int&, const int&){ return true; });

    // lexicographical_compare https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare
    std::lexicographical_compare(begin, end, begin, end);
    std::lexicographical_compare(begin, end, begin, end, [](const int&, const int&){ return true; });

    // next_permutation https://en.cppreference.com/w/cpp/algorithm/next_permutation
    std::next_permutation(begin, end);

    // prev_permutation https://en.cppreference.com/w/cpp/algorithm/prev_permutation
    // std::prev_permutation(begin, end);

    // iota https://en.cppreference.com/w/cpp/algorithm/iota
    // std::iota(begin, end, 0);

    // accumulate https://en.cppreference.com/w/cpp/algorithm/accumulate
    // std::accumulate(begin, end, 0);
    // std::accumulate(begin, end, 0, [](const int&, const int&){ return true; });

    // inner_product https://en.cppreference.com/w/cpp/algorithm/inner_product
    // std::inner_product(begin, end, begin, 0);
    // std::inner_product(begin, end, begin, 0, [](const int&, const int&){ return true; }, [](const int&, const int&){ return true; });

    // adjacent_difference https://en.cppreference.com/w/cpp/algorithm/adjacent_difference
    // std::adjacent_difference(begin, end, begin);
    // std::adjacent_difference(begin, end, begin, [](const int&, const int&){ return true; });

    // partial_sum https://en.cppreference.com/w/cpp/algorithm/partial_sum
    // std::partial_sum(begin, end, begin);
    // std::partial_sum(begin, end, begin, [](const int&, const int&){ return true; });

    // reduce https://en.cppreference.com/w/cpp/algorithm/reduce
    // std::reduce(begin, end, 0);
    // std::reduce(begin, end, 0, [](const int&, const int&){ return true; });

    // transform_reduce https://en.cppreference.com/w/cpp/algorithm/transform_reduce
    // std::transform_reduce(begin, end, begin, 0);
    // std::transform_reduce(begin, end, begin, 0, [](const int&, const int&){ return true; });
    // std::transform_reduce(begin, end, begin, 0, [](const int&, const int&){ return true; }, [](const int&, const int&){ return true; });

    // exclusive_scan https://en.cppreference.com/w/cpp/algorithm/exclusive_scan
    // std::exclusive_scan(begin, end, begin, 0);
    // std::exclusive_scan(begin, end, begin, 0, [](const int&, const int&){ return true; });

    // inclusive_scan https://en.cppreference.com/w/cpp/algorithm/inclusive_scan
    // std::inclusive_scan(begin, end, begin);
    // std::inclusive_scan(begin, end, begin, [](const int&, const int&){ return true; });

    // transform_exclusive_scan https://en.cppreference.com/w/cpp/algorithm/transform_exclusive_scan
    // std::transform_exclusive_scan(begin, end, begin, 0, [](const int&, const int&){ return true; }, [](const int&, const int&){ return true; });
    // std::transform_inclusive_scan(begin, end, begin, [](const int&, const int&){ return true; }, [](const int&, const int&){ return true; });
}