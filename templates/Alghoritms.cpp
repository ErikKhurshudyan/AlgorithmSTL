#include "../headers/Alghoritms.hpp"
#include <iterator>
#include <algorithm>
#include <utility>
#include <vector>
#include <cstdlib>
#include <cassert>

namespace My {

template <typename InputIterator, typename EqualityComparable>
InputIterator
find(InputIterator first, InputIterator last, const EqualityComparable& value)
{
    for (InputIterator it = first; it != last; ++it) {
        if (value == *it) return it;
    }
    return last;
}

template <typename ForwardIterator>
ForwardIterator
adjacent_find(ForwardIterator first, ForwardIterator last)
{
    if (first == last) return last;
    ForwardIterator prev = first;
    ForwardIterator next = first;
    ++next;

    while (next != last) {
        if (*prev++ == *next++) return prev;
    }
    return last;
}

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator
adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate binary_pred)
{
    if (first == last) return last;
    ForwardIterator prev = first;
    ForwardIterator next = first;
    ++next;

    while (next != last) {
        if (binary_pred(*prev++, *next++)) return prev;
    }
    return last;
}

template <typename InputIterator, typename ForwardIterator>
InputIterator
find_first_of(InputIterator first1, InputIterator last1,
              ForwardIterator first2, ForwardIterator last2)
{
    for (InputIterator it = first1; it != last1; ++it) {
        for (ForwardIterator it2 = first2; it2 != last2; ++it2) {
            if (*it == *it2) return it;
        }
    }
    return last1;
}

template <typename InputIterator, typename ForwardIterator, typename BinaryPredicate>
InputIterator
find_first_of(InputIterator first1, InputIterator last1,
              ForwardIterator first2, ForwardIterator last2, BinaryPredicate comp)
{
    for (InputIterator it = first1; it != last1; ++it) {
        for (ForwardIterator it2 = first2; it2 != last2; ++it2) {
            if (comp(*it, *it2)) return it;
        }
    }
    return last1;
}

template <typename InputIterator, typename EqualityComparable>
typename std::iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, const EqualityComparable& value)
{
    typename std::iterator_traits<InputIterator>::difference_type count1 = 0;
    for (InputIterator it = first; it != last; ++it) {
        if (value == *it) ++count1;
    }
    return count1;
}

template <typename InputIterator, typename EqualityComparable, typename Size>
void
count(InputIterator first, InputIterator last, const EqualityComparable& value, Size& n)
{
    for (InputIterator it = first; it != last; ++it) {
        if (value == *it) ++n;
    }
}

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1
search(ForwardIterator1 first1, ForwardIterator1 last1,
        ForwardIterator2 first2, ForwardIterator2 last2)
{
    for (ForwardIterator1 it = first1; it != last1; ++it) {
        ForwardIterator1 temp = it;
        for (ForwardIterator2 it2 = first2; ; ++it2) {
            if (last2 == it2) return it;
            if (*temp++ != *it2) break;
        }
    }
    return last1;
}


template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1
search(ForwardIterator1 first1, ForwardIterator1 last1,
        ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate binary_pred)
{
    for (ForwardIterator1 it = first1; it != last1; ++it) {
        ForwardIterator1 temp = it;
        for (ForwardIterator2 it2 = first2; ; ++it2) {
            if (last2 == it2) return it;
            if (!binary_pred(*temp++, *it2)) break;
        }
    }
    return last1;
}

template <typename ForwardIterator, typename Integer, typename T>
ForwardIterator
search_n(ForwardIterator first, ForwardIterator last,
                         Integer count, const T& value)
{
    for (ForwardIterator it = first; it != last; ++it) {
        ForwardIterator temp = it;
        for (int i = 1; ; ++i) {
            if (*temp++ != value) break;
            if (i == count) return it;
        }
    }
    return last;
}

template <typename ForwardIterator, typename Integer, typename T, typename BinaryPredicate>
ForwardIterator
search_n(ForwardIterator first, ForwardIterator last,
                         Integer count, const T& value, BinaryPredicate binary_pred)
{
    for (ForwardIterator it = first; it != last; ++it) {
        ForwardIterator temp = it;
        for (int i = 1; ; ++i) {
            if (!binary_pred(*temp++, value)) break;
            if (i == count) return it;
        }
    }
    return last;
}

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1
find_end(ForwardIterator1 first1, ForwardIterator1 last1,
         ForwardIterator2 first2, ForwardIterator2 last2)
{
    if (first2 == last2) return last1;
    ForwardIterator1 result = last1;
    for (ForwardIterator1 it = first1; it != last1; ++it) {
        ForwardIterator1 temp = it;
        for (ForwardIterator2 it2 = first2; ; ++it2) {
            if (last2 == it2) { result = it; break; }
            if (*temp++ != *it2) break;
        }
    }
    return result;
}

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1
find_end(ForwardIterator1 first1, ForwardIterator1 last1,
         ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate binary_pred)
{
    if (first2 == last2) return last1;
    ForwardIterator1 result = last1;
    for (ForwardIterator1 it = first1; it != last1; ++it) {
        ForwardIterator1 temp = it;
        for (ForwardIterator2 it2 = first2; ; ++it2) {
            if (last2 == it2) { result = it; break; }
            if (!binary_pred(*temp++, *it2)) break;
        }
    }
    return result;
}


template <typename RandomAccessIterator>
RandomAccessIterator
partition(RandomAccessIterator first, RandomAccessIterator last)
{
    typedef typename RandomAccessIterator::value_type ValueType;

    ValueType pivot_value = *(last - 1);
    RandomAccessIterator i = first;

    for (RandomAccessIterator j = first; j != last - 1; ++j) {
        if (*j < pivot_value) {
            std::swap(*i, *j);
            ++i;
        }
    }

    std::swap(*i, *(last - 1));
    return i;
}

template <typename RandomAccessIterator>
void
sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first >= last) return;
    const RandomAccessIterator pivot = My::partition(first, last);
    My::sort(first, pivot);
    My::sort(pivot + 1, last);
}

template <typename RandomAccessIterator, typename StrictWeakOrdering>
RandomAccessIterator
partition(RandomAccessIterator first, RandomAccessIterator last, StrictWeakOrdering comp)
{
    typedef typename RandomAccessIterator::value_type ValueType;

    ValueType pivot_value = *(last - 1);
    RandomAccessIterator i = first;

    for (RandomAccessIterator j = first; j != last - 1; ++j) {
        if (comp(*j, pivot_value)) {
            std::swap(*i, *j);
            ++i;
        }
    }

    std::swap(*i, *(last - 1));
    return i;
}

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void
sort(RandomAccessIterator first, RandomAccessIterator last, StrictWeakOrdering comp)
{
    if (first >= last) return;
    const RandomAccessIterator pivot = My::partition(first, last, comp);
    My::sort(first, pivot, comp);
    My::sort(pivot + 1, last, comp);
}

template <typename RandomAccessIterator>
void
merge(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    std::vector<T> temp;

    RandomAccessIterator left  = first;
    RandomAccessIterator right = middle;

    while (left != middle && right != last) {
        if (*left <= *right) {
            temp.push_back(*left);
            ++left;
            continue;
        }
        temp.push_back(*right);
        ++right;
    }

    while (left != middle) {
        temp.push_back(*left);
        ++left;
    }

    while (right != last) {
        temp.push_back(*right);
        ++right;
    }
    RandomAccessIterator it = first;
    typename std::vector<T>::iterator vit = temp.begin();
    for (; it != last && vit != temp.end(); ++it, ++vit) {
        *it = *vit;
    }
}



template <typename RandomAccessIterator>
void
stable_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    const size_t n = std::distance(first, last);
    if (n <= 1) return;
    for (size_t step = 1; step < n; step *= 2) {
        RandomAccessIterator leftIt = first;
        size_t remaining = n;

        while (remaining > 0) {
            const size_t leftSize = std::min(step, remaining);
            RandomAccessIterator midIt = leftIt;
            std::advance(midIt, leftSize);

            const size_t rightSize = std::min(step, remaining - leftSize);
            RandomAccessIterator rightIt = midIt;
            std::advance(rightIt, rightSize);

            merge(leftIt, midIt, rightIt);

            leftIt = rightIt;
            remaining -= (leftSize + rightSize);
        }
    }

}

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void
merge(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, StrictWeakOrdering comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    std::vector<T> temp;

    RandomAccessIterator left  = first;
    RandomAccessIterator right = middle;

    while (left != middle && right != last) {
        if (comp(*left, *right)) {
            temp.push_back(*left);
            ++left;
            continue;
        }
        temp.push_back(*right);
        ++right;
    }

    while (left != middle) {
        temp.push_back(*left);
        ++left;
    }

    while (right != last) {
        temp.push_back(*right);
        ++right;
    }
    RandomAccessIterator it = first;
    typename std::vector<T>::iterator vit = temp.begin();
    for (; it != last && vit != temp.end(); ++it, ++vit) {
        *it = *vit;
    }
}


template <typename RandomAccessIterator, typename StrictWeakOrdering>
void
stable_sort(RandomAccessIterator first, RandomAccessIterator last, 
            StrictWeakOrdering comp)
{
    const size_t n = std::distance(first, last);
    if (n <= 1) return;
    for (size_t step = 1; step < n; step *= 2) {
        RandomAccessIterator leftIt = first;
        size_t remaining = n;

        while (remaining > 0) {
            const size_t leftSize = std::min(step, remaining);
            RandomAccessIterator midIt = leftIt;
            std::advance(midIt, leftSize);

            const size_t rightSize = std::min(step, remaining - leftSize);
            RandomAccessIterator rightIt = midIt;
            std::advance(rightIt, rightSize);

            My::merge(leftIt, midIt, rightIt, comp);

            leftIt = rightIt;
            remaining -= (leftSize + rightSize);
        }
    }

}

template <typename RandomAccessIterator>
void 
partial_sort(RandomAccessIterator first,
             RandomAccessIterator middle,
             RandomAccessIterator last)
{
    if (first == last || first == middle) return;
    std::nth_element(first, middle, last);
    My::sort(first, middle);
}

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void
partial_sort(RandomAccessIterator first,
             RandomAccessIterator middle,
             RandomAccessIterator last, 
             StrictWeakOrdering comp)
{
    if (first == last || first == middle) return;
    std::nth_element(first, middle, last, comp);
    My::sort(first, middle, comp);
}

template <typename InputIterator, typename RandomAccessIterator>
RandomAccessIterator
partial_sort_copy(InputIterator first, InputIterator last,
                  RandomAccessIterator result_first,
                  RandomAccessIterator result_last)
{
    typedef typename std::iterator_traits<InputIterator>::value_type value_type;
    typedef typename std::vector<value_type> buffer_type;

    buffer_type temp(first, last);
    typename buffer_type::iterator middle = temp.begin() + 
        std::min(static_cast<typename buffer_type::difference_type>(result_last - result_first),
                 static_cast<typename buffer_type::difference_type>(temp.size()));

    if (temp.begin() == temp.end() || middle == temp.begin()) return result_first;

    std::partial_sort(temp.begin(), middle, temp.end());
    return std::copy(temp.begin(), middle, result_first);
}

template <typename InputIterator, typename RandomAccessIterator, typename Compare>
RandomAccessIterator
partial_sort_copy(InputIterator first, InputIterator last,
                  RandomAccessIterator result_first,
                  RandomAccessIterator result_last, Compare comp)
{
    typedef typename std::iterator_traits<InputIterator>::value_type value_type;
    typedef typename std::vector<value_type> buffer_type;

    buffer_type temp(first, last);
    typename buffer_type::iterator middle = temp.begin() + 
        std::min(static_cast<typename buffer_type::difference_type>(result_last - result_first),
                 static_cast<typename buffer_type::difference_type>(temp.size()));

    if (temp.begin() == temp.end() || middle == temp.begin())
        return result_first;

    std::partial_sort(temp.begin(), middle, temp.end(), comp);
    return std::copy(temp.begin(), middle, result_first);
}

template <typename ForwardIterator>
bool
is_sorted(ForwardIterator first, ForwardIterator last)
{
    if (first == last) return true;
    ForwardIterator next = first;
    ++next;
    while (next != last) {
        if (*next < *first) {
            return false;
        }
        ++first;
        ++next;
    }
    return true;
}

template <typename ForwardIterator, typename StrictWeakOrdering>
bool
is_sorted(ForwardIterator first, ForwardIterator last,
          StrictWeakOrdering comp)
{
    if (first == last) return true;
    ForwardIterator next = first;
    ++next;
    while (next != last) {
        if (comp(*next, *first)) return false;
        ++first;
        ++next;
    }
    return true;
}

template <typename RandomAccessIterator>
void
nth_element(RandomAccessIterator first, RandomAccessIterator nth,
            RandomAccessIterator last)
{
    My::nth_element(first, nth, last, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());   
}

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void
nth_element(RandomAccessIterator first, RandomAccessIterator nth,
            RandomAccessIterator last, StrictWeakOrdering comp)
{
    while (last - first > 1) {
        RandomAccessIterator pivot = first + std::rand() % (last - first);
        std::swap(*pivot, *(last - 1));
        RandomAccessIterator store = first;

        for (RandomAccessIterator it = first; it < last - 1; ++it) {
            if (comp(*it, *(last - 1))) {
                std::swap(*it, *store);
                ++store;
            }
        }
        std::swap(*(last - 1), *store);

        if (nth < store) {
            last = store;
        } else if (nth > store) {
            first = store + 1;
        } else {
            return;
        }
    }
}

template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator 
lower_bound(ForwardIterator first, ForwardIterator last,
            const LessThanComparable& value)
{
    assert(My::is_sorted(first, last));
    for (ForwardIterator it1 = first;  it1 != last; ++it1) {
        if ((*it1 >= value)) return it1;
    }
    return last;
}

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
ForwardIterator
lower_bound(ForwardIterator first, ForwardIterator last,
            const T& value, StrictWeakOrdering comp)
{
    assert(My::is_sorted(first, last, comp));
    for (ForwardIterator it1 = first; it1 != last; ++it1) {
        if (!comp(*it1, value))  return it1;
    }
    return last;
}

template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator
upper_bound(ForwardIterator first, ForwardIterator last,
            const LessThanComparable& value)
{
    assert(My::is_sorted(first, last));
    for (ForwardIterator it1 = first;  it1 != last; ++it1) {
        if ((*it1 > value)) return it1;
    }
    return last;
}

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
ForwardIterator
upper_bound(ForwardIterator first, ForwardIterator last,
            const T& value, StrictWeakOrdering comp)
{
    assert(My::is_sorted(first, last, comp));
    for (ForwardIterator it1 = first; it1 != last; ++it1) {
        if (comp(value, *it1))  return it1;
    }
    return last;
}

template <typename ForwardIterator, typename LessThanComparable>
std::pair<ForwardIterator, ForwardIterator>
equal_range(ForwardIterator first, ForwardIterator last,
            const LessThanComparable& value)
{
    return std::make_pair(My::lower_bound(first, last, value), My::upper_bound(first, last, value));
}

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
std::pair<ForwardIterator, ForwardIterator>
equal_range(ForwardIterator first, ForwardIterator last, const T& value,
            StrictWeakOrdering comp)
{
    return std::make_pair(My::lower_bound(first, last, value, comp),My::upper_bound(first, last, value, comp));
}

template <typename ForwardIterator, typename LessThanComparable>
bool
binary_search(ForwardIterator first, ForwardIterator last,
              const LessThanComparable& value)
{
    ForwardIterator newFirst = first;
    ForwardIterator newLast = last;
    while (newFirst != newLast) {
        ForwardIterator middle = newFirst;
        std::advance(middle, std::distance(newFirst, newLast) / 2);
        if (*middle < value) {
            newFirst = ++middle;
        } else if (value < *middle) {
            newLast = middle;
        } else {
            return true;
        }
    }
    return false;
}

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
bool
binary_search(ForwardIterator first, ForwardIterator last, const T& value,
              StrictWeakOrdering comp)
{
    ForwardIterator newFirst = first;
    ForwardIterator newLast = last;
    while (newFirst != newLast) {
        ForwardIterator middle = newFirst;
        std::advance(middle, std::distance(newFirst, newLast) / 2);
        if (comp(*middle, value)) {
            newFirst = ++middle;
        } else if (comp(value, *middle)) {
            newLast = middle;
        } else {
            return true;
        }
    }
    return false;
}



}////end
