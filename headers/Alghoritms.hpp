#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iterator>

namespace My {

template <typename InputIterator, typename EqualityComparable>
InputIterator find(InputIterator first, InputIterator last, const EqualityComparable& value);

template <typename ForwardIterator>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last);

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate binary_pred);

template <typename InputIterator, typename ForwardIterator>
InputIterator find_first_of(InputIterator first1, InputIterator last1,
                            ForwardIterator first2, ForwardIterator last2);

template <typename InputIterator, typename ForwardIterator, typename BinaryPredicate>
InputIterator find_first_of(InputIterator first1, InputIterator last1,
                            ForwardIterator first2, ForwardIterator last2,
                            BinaryPredicate comp);


template <typename InputIterator, typename EqualityComparable>
typename std::iterator_traits<InputIterator>::difference_type
count(InputIterator first, InputIterator last, const EqualityComparable& value);

template <typename InputIterator, typename EqualityComparable, typename Size>
void count(InputIterator first, InputIterator last, const EqualityComparable& value, Size& n);

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                        ForwardIterator2 first2, ForwardIterator2 last2);

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
                        ForwardIterator2 first2, ForwardIterator2 last2,
                        BinaryPredicate binary_pred);



template <typename ForwardIterator, typename Integer, typename T>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last,
                         Integer count, const T& value);

template <typename ForwardIterator, typename Integer, 
          typename T, typename BinaryPredicate>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last,
                         Integer count, const T& value,
                         BinaryPredicate binary_pred);



template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1
find_end(ForwardIterator1 first1, ForwardIterator1 last1,
         ForwardIterator2 first2, ForwardIterator2 last2);

template <typename ForwardIterator1, typename ForwardIterator2,
          typename BinaryPredicate>
ForwardIterator1
find_end(ForwardIterator1 first1, ForwardIterator1 last1,
         ForwardIterator2 first2, ForwardIterator2 last2,
         BinaryPredicate comp);

template <typename RandomAccessIterator>
void sort(RandomAccessIterator first, RandomAccessIterator last);

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void sort(RandomAccessIterator first, RandomAccessIterator last,
          StrictWeakOrdering comp);

template <typename RandomAccessIterator>
void
stable_sort(RandomAccessIterator first, RandomAccessIterator last);

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void
stable_sort(RandomAccessIterator first, RandomAccessIterator last, 
                 StrictWeakOrdering comp);

template <typename RandomAccessIterator>
void partial_sort(RandomAccessIterator first,
                  RandomAccessIterator middle,
                  RandomAccessIterator last);

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void partial_sort(RandomAccessIterator first,
                  RandomAccessIterator middle,
                  RandomAccessIterator last, 
                  StrictWeakOrdering comp);

template <typename InputIterator, typename RandomAccessIterator>
RandomAccessIterator
partial_sort_copy(InputIterator first, InputIterator last,
                  RandomAccessIterator result_first,
                  RandomAccessIterator result_last);

template <typename InputIterator, typename RandomAccessIterator,
          typename StrictWeakOrdering>
RandomAccessIterator
partial_sort_copy(InputIterator first, InputIterator last,
                  RandomAccessIterator result_first,
                  RandomAccessIterator result_last, StrictWeakOrdering comp);

template <typename ForwardIterator>
bool is_sorted(ForwardIterator first, ForwardIterator last);

template <typename ForwardIterator, typename StrictWeakOrdering>
bool is_sorted(ForwardIterator first, ForwardIterator last,
               StrictWeakOrdering comp);

template <typename RandomAccessIterator>
void nth_element(RandomAccessIterator first, RandomAccessIterator nth,
                 RandomAccessIterator last);

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void nth_element(RandomAccessIterator first, RandomAccessIterator nth,
                 RandomAccessIterator last, StrictWeakOrdering comp);

template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last,
                            const LessThanComparable& value);

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last,
                            const T& value, StrictWeakOrdering comp);

template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last,
                            const LessThanComparable& value);

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last,
                            const T& value, StrictWeakOrdering comp);

template <typename ForwardIterator, typename LessThanComparable>
std::pair<ForwardIterator, ForwardIterator>
equal_range(ForwardIterator first, ForwardIterator last,
            const LessThanComparable& value);

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
std::pair<ForwardIterator, ForwardIterator>
equal_range(ForwardIterator first, ForwardIterator last, const T& value,
            StrictWeakOrdering comp);

template <typename ForwardIterator, typename LessThanComparable>
bool binary_search(ForwardIterator first, ForwardIterator last,
                   const LessThanComparable& value);

template <typename ForwardIterator, typename T, typename StrictWeakOrdering>
bool binary_search(ForwardIterator first, ForwardIterator last, const T& value,
                   StrictWeakOrdering comp);

}  ////end


#include "../templates/Alghoritms.cpp"
#endif /// SUDOKU_HPP

