#include "headers/Alghoritms.hpp"
#include <gtest/gtest.h>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

template <class RandomAccessIterator>
bool is_sorted_c03(RandomAccessIterator first, RandomAccessIterator last) {
    if (first == last) return true;
    RandomAccessIterator next = first;
    ++next;
    for (; next != last; ++first, ++next) {
        if (*next < *first) return false;
    }
    return true;
}
template <class RandomAccessIterator>
bool is_sorted(RandomAccessIterator first, RandomAccessIterator last) {
    if (first == last) return true;
    RandomAccessIterator next = first;
    ++next;
    for (; next != last; ++first, ++next) {
        if (*next < *first) return false;
    }
    return true;
}


TEST(FindTest, FindsExistingElement)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    std::vector<int>::iterator it = My::find(v.begin(), v.end(), 3);
    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 3);
}

TEST(FindTest, ReturnsEndIfNotFound)
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    std::vector<int>::iterator it = My::find(v.begin(), v.end(), 99);
    EXPECT_EQ(it, v.end());
}

TEST(FindTest, WorksWithEmptyContainer)
{
    std::vector<int> v;
    std::vector<int>::iterator it = My::find(v.begin(), v.end(), 1);
    EXPECT_EQ(it, v.end());
}

struct Point
{
    int x;
    int y;
    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }
};

TEST(FindTest, WorksWithCustomStruct)
{
    std::list<Point> points;
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Point p3 = {5, 6};
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    Point target = {3, 4};
    std::list<Point>::iterator it = My::find(points.begin(), points.end(), target);
    ASSERT_NE(it, points.end());
    EXPECT_EQ(it->x, 3);
    EXPECT_EQ(it->y, 4);
}

TEST(FindTest, WorksWithConstContainer)
{
    const std::string arr[] = {"alpha", "beta", "gamma"};
    const std::vector<std::string> words(arr, arr + 3);
    std::vector<std::string>::const_iterator it = My::find(words.begin(), words.end(), std::string("beta"));
    ASSERT_NE(it, words.end());
    EXPECT_EQ(*it, "beta");
}

TEST(AdjacentFindTest, FindsEqualAdjacentInts)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    std::vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 2);
}

TEST(AdjacentFindTest, NoEqualAdjacentElements)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    std::vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    EXPECT_EQ(it, v.end());
}

TEST(AdjacentFindTest, WorksWithStrings)
{
    std::vector<std::string> v;
    v.push_back("a");
    v.push_back("b");
    v.push_back("b");
    v.push_back("c");
    std::vector<std::string>::iterator it = adjacent_find(v.begin(), v.end());
    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, "b");
}


TEST(AdjacentFindTest, WorksWithCustomStruct)
{
    std::list<Point> points;
    Point p1;
    p1.x = 1; p1.y = 2;
    Point p2;
    p2.x = 3; p2.y = 4;
    Point p3;
    p3.x = 3; p3.y = 4;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);

    std::list<Point>::iterator it = adjacent_find(points.begin(), points.end());
    ASSERT_NE(it, points.end());
    EXPECT_EQ(it->x, 3);
    EXPECT_EQ(it->y, 4);
}

TEST(AdjacentFindTest, WorksWithEmptyContainer)
{
    std::vector<int> v;
    std::vector<int>::iterator it = adjacent_find(v.begin(), v.end());
    EXPECT_EQ(it, v.end());
}

TEST(AdjacentFindPredicateTest, FindsAdjacentEqualInts)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);

    std::vector<int>::iterator it = adjacent_find(v.begin(), v.end(),
                                                  std::equal_to<int>());
    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 2);
}

TEST(AdjacentFindPredicateTest, CustomGreaterPredicate)
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(3);
    v.push_back(2);

    std::vector<int>::iterator it = adjacent_find(v.begin(), v.end(),
                                                  std::greater<int>());
    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 5);
}

TEST(AdjacentFindPredicateTest, NoAdjacentSatisfyPredicate)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    std::vector<int>::iterator it = adjacent_find(v.begin(), v.end(),
                                                  std::greater<int>());
    EXPECT_EQ(it, v.end());
}

struct SameX
{
    bool operator()(const Point& a, const Point& b) const
    {
        return a.x == b.x;
    }
};

TEST(AdjacentFindPredicateTest, WorksWithCustomStructPredicate)
{
    std::vector<Point> v;
    Point p1; p1.x = 1; p1.y = 2;
    Point p2; p2.x = 2; p2.y = 3;
    Point p3; p3.x = 2; p3.y = 5;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);

    std::vector<Point>::iterator it = adjacent_find(v.begin(), v.end(), SameX());
    ASSERT_NE(it, v.end());
    EXPECT_EQ(it->x, 2);
    EXPECT_EQ(it->y, 3);
}

TEST(AdjacentFindPredicateTest, WorksWithEmptyContainer)
{
    std::vector<int> v;
    std::vector<int>::iterator it = adjacent_find(v.begin(), v.end(),
                                                  std::equal_to<int>());
    EXPECT_EQ(it, v.end());
}

TEST(FindFirstOfTest, FindsFirstMatchingInt)
{
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    std::vector<int> v2;
    v2.push_back(5);
    v2.push_back(3);
    v2.push_back(6);

    std::vector<int>::iterator it = My::find_first_of(v1.begin(), v1.end(),
                                                     v2.begin(), v2.end());
    ASSERT_NE(it, v1.end());
    EXPECT_EQ(*it, 3);
}

TEST(FindFirstOfTest, ReturnsEndIfNoMatch)
{
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    std::vector<int> v2;
    v2.push_back(4);
    v2.push_back(5);

    std::vector<int>::iterator it = My::find_first_of(v1.begin(), v1.end(),
                                                     v2.begin(), v2.end());
    EXPECT_EQ(it, v1.end());
}

TEST(FindFirstOfTest, WorksWithStrings)
{
    std::vector<std::string> v1;
    v1.push_back("a");
    v1.push_back("b");
    v1.push_back("c");

    std::vector<std::string> v2;
    v2.push_back("x");
    v2.push_back("b");

    std::vector<std::string>::iterator it = My::find_first_of(v1.begin(), v1.end(),
                                                              v2.begin(), v2.end());
    ASSERT_NE(it, v1.end());
    EXPECT_EQ(*it, "b");
}

TEST(FindFirstOfPredicateTest, FindsFirstUsingPredicate)
{
    std::vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    std::vector<int> v2;
    v2.push_back(10);
    v2.push_back(15);
    v2.push_back(12);

    // Predicate: v1 element < v2 element
    std::vector<int>::iterator it = My::find_first_of(v1.begin(), v1.end(),
                                                      v2.begin(), v2.end(),
                                                      std::less<int>());
    ASSERT_NE(it, v1.end());
    EXPECT_EQ(*it, 1);
}

TEST(FindFirstOfPredicateTest, ReturnsEndIfNoPredicateMatch)
{
    std::vector<int> v1;
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(7);

    std::vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    std::vector<int>::iterator it = My::find_first_of(v1.begin(), v1.end(),
                                                      v2.begin(), v2.end(),
                                                      std::less<int>());
    EXPECT_EQ(it, v1.end());
}

TEST(FindFirstOfPredicateTest, WorksWithEmptyContainer)
{
    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int>::iterator it = My::find_first_of(v1.begin(), v1.end(),
                                                      v2.begin(), v2.end());
    EXPECT_EQ(it, v1.end());
}


TEST(CountTest, CountsInts)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);

    size_t c = My::count(v.begin(), v.end(), 1);
    EXPECT_EQ(c, 3);
}

TEST(CountTest, CountsWithEmptyContainer)
{
    std::vector<int> v;
    size_t c = My::count(v.begin(), v.end(), 1);
    EXPECT_EQ(c, 0);
}

TEST(CountTest, CountsStrings)
{
    std::vector<std::string> v;
    v.push_back("a");
    v.push_back("b");
    v.push_back("a");
    v.push_back("c");

    size_t c = My::count(v.begin(), v.end(), std::string("a"));
    EXPECT_EQ(c, 2);
}

TEST(CountTest, CountsUsingOldInterface)
{
    std::vector<int> v;
    v.push_back(5);
    v.push_back(0);
    v.push_back(5);

    int n = 1;
    My::count(v.begin(), v.end(), 5, n);
    EXPECT_EQ(n, 3); // 1 (start) + 2 occurrences
}

TEST(CountTest, WorksWithList)
{
    std::list<int> lst;
    lst.push_back(7);
    lst.push_back(7);
    lst.push_back(8);

    size_t c = My::count(lst.begin(), lst.end(), 7);
    EXPECT_EQ(c, 2);
}


TEST(SearchTest, FindsSubsequenceInVector)
{
    typedef std::vector<int> Vec;
    Vec v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    Vec v2;
    v2.push_back(2);
    v2.push_back(3);
    v2.push_back(4);

    Vec::iterator it = My::search(v1.begin(), v1.end(), v2.begin(), v2.end());
    EXPECT_EQ(*it, 2);
    EXPECT_EQ(it - v1.begin(), 1); // vector-ում ստացվում է distance
}

TEST(SearchTest, ReturnsEndIfNotFound)
{
    typedef std::vector<int> Vec;
    Vec v1;
    v1.push_back(1); v1.push_back(2); v1.push_back(3); v1.push_back(4); v1.push_back(5);

    Vec v2;
    v2.push_back(3); v2.push_back(2); v2.push_back(4);

    Vec::iterator it = My::search(v1.begin(), v1.end(), v2.begin(), v2.end());
    EXPECT_EQ(it, v1.end());
}

TEST(SearchTest, WorksWithStrings)
{
    typedef std::string Str;
    Str s1 = "Hello, world!";
    Str s2 = "world";

    Str::iterator it = My::search(s1.begin(), s1.end(), s2.begin(), s2.end());
    EXPECT_EQ(*it, 'w');
    EXPECT_EQ(it - s1.begin(), 7); // distance
}

TEST(SearchTest, WorksWithEmptyFirstContainer)
{
    typedef std::vector<int> Vec;
    Vec v1;
    Vec v2;
    v2.push_back(1); v2.push_back(2);

    Vec::iterator it = My::search(v1.begin(), v1.end(), v2.begin(), v2.end());
    EXPECT_EQ(it, v1.end());
}

TEST(SearchTest, WorksWithEmptySecondContainer)
{
    typedef std::vector<int> Vec;
    Vec v1;
    v1.push_back(1); v1.push_back(2); v1.push_back(3);

    Vec v2; // empty subsequence
    Vec::iterator it = My::search(v1.begin(), v1.end(), v2.begin(), v2.end());
    EXPECT_EQ(it, v1.begin()); // empty subsequence always matches at start
}

TEST(SearchTest, WorksWithList)
{
    typedef std::list<int> List;
    List l1;
    l1.push_back(1); l1.push_back(2); l1.push_back(3); l1.push_back(4);

    List l2;
    l2.push_back(2); l2.push_back(3);

    List::iterator it = My::search(l1.begin(), l1.end(), l2.begin(), l2.end());

    List::iterator expected = l1.begin();
    ++expected; // points to 2

    EXPECT_EQ(*it, *expected);
}





struct Equal {
    bool operator()(int a, int b) const { return a == b; }
};

struct EvenOddMatch {
    bool operator()(int a, int b) const { return (a % 2) == (b % 2); }
};

// ===== TESTS =====

TEST(SearchTest, BasicIntegerMatch) {
    std::vector<int> v1;
    v1.push_back(1); v1.push_back(2); v1.push_back(3); v1.push_back(4); v1.push_back(5);
    std::vector<int> v2;
    v2.push_back(3); v2.push_back(4);

    std::vector<int>::iterator it = My::search(v1.begin(), v1.end(),
                                                 v2.begin(), v2.end(), Equal());
    ASSERT_NE(it, v1.end());
    EXPECT_EQ(*it, 3);
}

TEST(SearchTest, NoMatch) {
    std::vector<int> v1;
    v1.push_back(1); v1.push_back(2); v1.push_back(3); v1.push_back(4); v1.push_back(5);
    std::vector<int> v2;
    v2.push_back(6); v2.push_back(7);

    std::vector<int>::iterator it = My::search(v1.begin(), v1.end(),
                                                 v2.begin(), v2.end(), Equal());
    EXPECT_EQ(it, v1.end());
}

TEST(SearchTest, MatchAtBeginning) {
    std::vector<int> v1; v1.push_back(1); v1.push_back(2); v1.push_back(3);
    std::vector<int> v2; v2.push_back(1); v2.push_back(2);

    std::vector<int>::iterator it = My::search(v1.begin(), v1.end(),
                                                 v2.begin(), v2.end(), Equal());
    ASSERT_NE(it, v1.end());
    EXPECT_EQ(*it, 1);
}

TEST(SearchTest, MatchAtEnd) {
    std::vector<int> v1; v1.push_back(5); v1.push_back(6); v1.push_back(7); v1.push_back(8);
    std::vector<int> v2; v2.push_back(7); v2.push_back(8);

    std::vector<int>::iterator it = My::search(v1.begin(), v1.end(),
                                                 v2.begin(), v2.end(), Equal());
    ASSERT_NE(it, v1.end());
    EXPECT_EQ(*it, 7);
}


TEST(SearchTest, EmptySecondRange) {
    std::vector<int> v1; v1.push_back(1); v1.push_back(2); v1.push_back(3);
    std::vector<int> v2; // empty

    std::vector<int>::iterator it = My::search(v1.begin(), v1.end(),
                                                 v2.begin(), v2.end(), Equal());
    EXPECT_EQ(it, v1.begin());
}

TEST(SearchTest, EmptyFirstRange) {
    std::vector<int> v1; // empty
    std::vector<int> v2; v2.push_back(1); v2.push_back(2);

    std::vector<int>::iterator it = My::search(v1.begin(), v1.end(),
                                                 v2.begin(), v2.end(), Equal());
    EXPECT_EQ(it, v1.end());
}

TEST(SearchNTest, BasicIntegerMatch) {
    std::vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3);
    v.push_back(3); v.push_back(3); v.push_back(4);

    std::vector<int>::iterator it = My::search_n(v.begin(), v.end(), 3, 3);

    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 3);
    EXPECT_EQ(it - v.begin(), 2); // starts at index 2
}

TEST(SearchNTest, MatchAtBeginning) {
    std::vector<int> v;
    v.push_back(5); v.push_back(5); v.push_back(5); v.push_back(7);

    std::vector<int>::iterator it = My::search_n(v.begin(), v.end(), 3, 5);

    ASSERT_NE(it, v.end());
    EXPECT_EQ(it, v.begin());
}

TEST(SearchNTest, MatchAtEnd) {
    std::vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(9); v.push_back(9); v.push_back(9);

    std::vector<int>::iterator it = My::search_n(v.begin(), v.end(), 3, 9);

    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 9);
    EXPECT_EQ(it - v.begin(), 2);
}

TEST(SearchNTest, NoMatch) {
    std::vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4);

    std::vector<int>::iterator it = My::search_n(v.begin(), v.end(), 2, 5);

    EXPECT_EQ(it, v.end());
}

TEST(SearchNTest, PartialMatchNotEnoughCount) {
    std::vector<int> v;
    v.push_back(2); v.push_back(2); v.push_back(3); v.push_back(2);

    std::vector<int>::iterator it = My::search_n(v.begin(), v.end(), 3, 2);

    EXPECT_EQ(it, v.end()); // Only two 2’s together, not three
}

TEST(SearchNTest, CountOneShouldFindFirstOccurrence) {
    std::vector<int> v;
    v.push_back(4); v.push_back(5); v.push_back(6);

    std::vector<int>::iterator it = My::search_n(v.begin(), v.end(), 1, 5);

    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 5);
    EXPECT_EQ(it - v.begin(), 1);
}

TEST(SearchNTest, EmptyContainer) {
    std::vector<int> v;

    std::vector<int>::iterator it = My::search_n(v.begin(), v.end(), 2, 1);

    EXPECT_EQ(it, v.end());
}

TEST(SearchNTest, StringVectorMatch) {
    std::vector<std::string> v;
    v.push_back("a");
    v.push_back("b");
    v.push_back("b");
    v.push_back("b");
    v.push_back("c");

    std::vector<std::string>::iterator it =
        My::search_n(v.begin(), v.end(), 3, std::string("b"));

    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, "b");
    EXPECT_EQ(it - v.begin(), 1);
}



TEST(FindEndTest, BasicMatchInMiddle) {
    std::vector<int> v1;
    v1.push_back(1); v1.push_back(2); v1.push_back(3);
    v1.push_back(4); v1.push_back(5);

    std::vector<int> v2;
    v2.push_back(3); v2.push_back(4);

    std::vector<int>::iterator it =
        My::find_end(v1.begin(), v1.end(), v2.begin(), v2.end());

    ASSERT_NE(it, v1.end());
    EXPECT_EQ(*it, 3);
    EXPECT_EQ(it - v1.begin(), 2);
}

TEST(FindEndTest, MatchAtBeginning) {
    std::vector<int> v1;
    v1.push_back(1); v1.push_back(2); v1.push_back(3);

    std::vector<int> v2;
    v2.push_back(1); v2.push_back(2);

    std::vector<int>::iterator it =
        My::find_end(v1.begin(), v1.end(), v2.begin(), v2.end());

    ASSERT_NE(it, v1.end());
    EXPECT_EQ(it, v1.begin());
}

TEST(FindEndTest, MatchAtEnd) {
    std::vector<int> v1;
    v1.push_back(4); v1.push_back(5); v1.push_back(6);
    v1.push_back(7); v1.push_back(8);

    std::vector<int> v2;
    v2.push_back(7); v2.push_back(8);

    std::vector<int>::iterator it =
        My::find_end(v1.begin(), v1.end(), v2.begin(), v2.end());

    ASSERT_NE(it, v1.end());
    EXPECT_EQ(*it, 7);
    EXPECT_EQ(it - v1.begin(), 3);
}

TEST(FindEndTest, MultipleOccurrencesReturnsLastOne) {
    std::vector<int> v1;
    v1.push_back(1); v1.push_back(2); v1.push_back(3);
    v1.push_back(1); v1.push_back(2); v1.push_back(3);

    std::vector<int> v2;
    v2.push_back(1); v2.push_back(2);

    std::vector<int>::iterator it =
        My::find_end(v1.begin(), v1.end(), v2.begin(), v2.end());

    ASSERT_NE(it, v1.end());
    EXPECT_EQ(*it, 1);
    EXPECT_EQ(it - v1.begin(), 3); // last occurrence
}

TEST(FindEndTest, NoMatch) {
    std::vector<int> v1;
    v1.push_back(1); v1.push_back(2); v1.push_back(3);

    std::vector<int> v2;
    v2.push_back(4); v2.push_back(5);

    std::vector<int>::iterator it =
        My::find_end(v1.begin(), v1.end(), v2.begin(), v2.end());

    EXPECT_EQ(it, v1.end());
}

TEST(FindEndTest, PartialButNotCompleteMatch) {
    std::vector<int> v1;
    v1.push_back(1); v1.push_back(2); v1.push_back(1);

    std::vector<int> v2;
    v2.push_back(1); v2.push_back(2); v2.push_back(3);

    std::vector<int>::iterator it =
        My::find_end(v1.begin(), v1.end(), v2.begin(), v2.end());

    EXPECT_EQ(it, v1.end());
}

TEST(FindEndTest, EmptySecondRangeReturnsLast1)
{
    std::vector<int> v1;
    v1.push_back(1); v1.push_back(2); v1.push_back(3);
    std::vector<int> v2; // empty

    std::vector<int>::iterator it =
        My::find_end(v1.begin(), v1.end(), v2.begin(), v2.end());

    EXPECT_EQ(it, v1.end()); // matches std::find_end behavior
}

TEST(FindEndTest, EmptyFirstRange) {
    std::vector<int> v1; // empty
    std::vector<int> v2;
    v2.push_back(1); v2.push_back(2);

    std::vector<int>::iterator it =
        My::find_end(v1.begin(), v1.end(), v2.begin(), v2.end());

    EXPECT_EQ(it, v1.end());
}

TEST(FindEndTest, WorksWithStrings) {
    std::vector<std::string> v1;
    v1.push_back("a"); v1.push_back("b"); v1.push_back("c");
    v1.push_back("a"); v1.push_back("b");

    std::vector<std::string> v2;
    v2.push_back("a"); v2.push_back("b");

    std::vector<std::string>::iterator it =
        My::find_end(v1.begin(), v1.end(), v2.begin(), v2.end());

    ASSERT_NE(it, v1.end());
    EXPECT_EQ(*it, "a");
    EXPECT_EQ(it - v1.begin(), 3); // last "a b" pair
}



TEST(SortTest, EmptyVector) {
    std::vector<int> v;
    My::sort(v.begin(), v.end());
    EXPECT_TRUE(v.empty());
}

TEST(SortTest, SingleElement) {
    std::vector<int> v;
    v.push_back(42);
    My::sort(v.begin(), v.end());
    ASSERT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 42);
}

TEST(SortTest, AlreadySorted) {
    std::vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4);
    My::sort(v.begin(), v.end());
    EXPECT_TRUE(is_sorted_c03(v.begin(), v.end()));
}

TEST(SortTest, ReverseSorted) {
    std::vector<int> v;
    v.push_back(5); v.push_back(4); v.push_back(3); v.push_back(2); v.push_back(1);
    My::sort(v.begin(), v.end());
    EXPECT_TRUE(is_sorted_c03(v.begin(), v.end()));
}

TEST(SortTest, RandomOrder) {
    std::vector<int> v;
    v.push_back(3); v.push_back(1); v.push_back(4); v.push_back(5); v.push_back(2);
    My::sort(v.begin(), v.end());
    EXPECT_TRUE(is_sorted_c03(v.begin(), v.end()));
}

TEST(SortTest, WithDuplicates) {
    std::vector<int> v;
    v.push_back(2); v.push_back(3); v.push_back(2); v.push_back(1); v.push_back(3);
    My::sort(v.begin(), v.end());
    EXPECT_TRUE(is_sorted_c03(v.begin(), v.end()));
}

TEST(SortTest, Strings) {
    std::vector<std::string> v;
    v.push_back("orange"); v.push_back("apple"); v.push_back("banana"); v.push_back("kiwi");
    My::sort(v.begin(), v.end());
    EXPECT_TRUE(is_sorted_c03(v.begin(), v.end()));
}

TEST(SortTest, Strings1) {
    std::vector<std::string> v;
    v.push_back("orange"); v.push_back("apple"); v.push_back("banana"); v.push_back("kiwi");
    My::sort(v.begin(), v.end(), std::less<std::string>());
    EXPECT_TRUE(is_sorted_c03(v.begin(), v.end()));
}



// ===== TESTS =====

TEST(StableSortTest, EmptyVector) {
    std::vector<int> v;
    My::stable_sort(v.begin(), v.end());
    EXPECT_TRUE(v.empty());
}

TEST(StableSortTest, SingleElement) {
    std::vector<int> v;
    v.push_back(42);
    My::stable_sort(v.begin(), v.end());
    ASSERT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], 42);
}

TEST(StableSortTest, AlreadySorted) {
    std::vector<int> v;
    v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(4);
    My::stable_sort(v.begin(), v.end());
    EXPECT_TRUE(is_sorted_c03(v.begin(), v.end()));
}

TEST(StableSortTest, ReverseSorted) {
    std::vector<int> v;
    v.push_back(5); v.push_back(4); v.push_back(3); v.push_back(2); v.push_back(1);
    My::stable_sort(v.begin(), v.end());
    EXPECT_TRUE(is_sorted_c03(v.begin(), v.end()));
}

TEST(StableSortTest, RandomOrderWithDuplicates) {
    std::vector<int> v;
    v.push_back(3); v.push_back(1); v.push_back(2); v.push_back(3); v.push_back(1);
    My::stable_sort(v.begin(), v.end());
    EXPECT_TRUE(is_sorted_c03(v.begin(), v.end()));
}

TEST(StableSortTest, StringsDefaultCompare) {
    std::vector<std::string> v;
    v.push_back("orange"); v.push_back("apple"); v.push_back("banana"); v.push_back("kiwi");
    My::stable_sort(v.begin(), v.end());
    EXPECT_TRUE(is_sorted_c03(v.begin(), v.end()));
}

TEST(PartialSortCopyTest, BasicAscending) {
    int input[] = {9, 2, 5, 1, 8, 3};
    int result[3];

    int* end = My::partial_sort_copy(input, input + 6, result, result + 3);

    EXPECT_EQ(end - result, 3);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 2);
    EXPECT_EQ(result[2], 3);
}

TEST(PartialSortCopyTest, BasicDescendingWithComparator) {
    int input[] = {4, 10, 6, 2, 8};
    int result[2];

    int* end = My::partial_sort_copy(input, input + 5, result, result + 2, std::greater<int>());

    EXPECT_EQ(end - result, 2);
    EXPECT_EQ(result[0], 10);
    EXPECT_EQ(result[1], 8);
}

TEST(PartialSortCopyTest, EmptyInput) {
    std::vector<int> input;
    std::vector<int> result(5);

    std::vector<int>::iterator end =
        My::partial_sort_copy(input.begin(), input.end(), result.begin(), result.end());

    EXPECT_EQ(end, result.begin());
}

TEST(PartialSortCopyTest, SmallerOutputThanInput) {
    std::vector<int> input;
    input.push_back(7);
    input.push_back(1);
    input.push_back(3);
    input.push_back(9);
    input.push_back(5);

    std::vector<int> result(3);
    std::vector<int>::iterator end =
        My::partial_sort_copy(input.begin(), input.end(), result.begin(), result.end());

    EXPECT_EQ(end - result.begin(), 3);
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], 3);
    EXPECT_EQ(result[2], 5);
}

TEST(PartialSortCopyTest, CustomStruct) {
    struct Point {
        int x;
        bool operator<(const Point& other) const { return x < other.x; }
    };

    Point input[] = {{5}, {2}, {9}, {1}};
    Point result[2];

    Point* end = My::partial_sort_copy(input, input + 4, result, result + 2);

    EXPECT_EQ(end - result, 2);
    EXPECT_EQ(result[0].x, 1);
    EXPECT_EQ(result[1].x, 2);
}

TEST(IsSortedTest, VectorAscending) {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> v(arr, arr + 5);
    EXPECT_TRUE(My::is_sorted(v.begin(), v.end()));
}

// --------- Not sorted vector ---------
TEST(IsSortedTest, VectorNotSorted) {
    int arr[] = {5, 3, 1, 4, 2};
    std::vector<int> v(arr, arr + 5);
    EXPECT_FALSE(My::is_sorted(v.begin(), v.end()));
}

// --------- Empty container ---------
TEST(IsSortedTest, EmptyVector) {
    std::vector<int> v;
    EXPECT_TRUE(My::is_sorted(v.begin(), v.end()));
}

// --------- Single element ---------
TEST(IsSortedTest, SingleElement) {
    int a = 42;
    EXPECT_TRUE(My::is_sorted(&a, &a + 1));
}

// --------- Forward iterator: std::list ---------
TEST(IsSortedTest, ListAscending) {
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    EXPECT_TRUE(My::is_sorted(l.begin(), l.end()));
}

TEST(IsSortedTest, ListNotSorted) {
    std::list<int> l;
    l.push_back(2);
    l.push_back(1);
    l.push_back(3);
    EXPECT_FALSE(My::is_sorted(l.begin(), l.end()));
}

// --------- Custom struct with operator< ---------
struct Point1 {
    int x;
    bool operator<(const Point1& other) const { return x < other.x; }
};

TEST(IsSortedTest, CustomStruct) {
    Point1 p[] = {{1}, {2}, {3}};
    EXPECT_TRUE(My::is_sorted(p, p + 3));

    Point1 q[] = {{3}, {1}, {2}};
    EXPECT_FALSE(My::is_sorted(q, q + 3));
}

struct LessInt {
    bool operator()(int a, int b) const { return a < b; }
};

struct GreaterInt {
    bool operator()(int a, int b) const { return a > b; }
};

// --------- Vector ascending with comparator ---------
TEST(IsSortedCompTest, VectorAscending) {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> v(arr, arr + 5);
    EXPECT_TRUE(My::is_sorted(v.begin(), v.end(), LessInt()));
}

// --------- Vector descending with comparator ---------
TEST(IsSortedCompTest, VectorDescending) {
    int arr[] = {5, 4, 3, 2, 1};
    std::vector<int> v(arr, arr + 5);
    EXPECT_TRUE(My::is_sorted(v.begin(), v.end(), GreaterInt()));
}

// --------- Not sorted vector ---------
TEST(IsSortedCompTest, VectorNotSorted) {
    int arr[] = {1, 3, 2, 4, 5};
    std::vector<int> v(arr, arr + 5);
    EXPECT_FALSE(My::is_sorted(v.begin(), v.end(), LessInt()));
}

// --------- Empty container ---------
TEST(IsSortedCompTest, EmptyVector) {
    std::vector<int> v;
    EXPECT_TRUE(My::is_sorted(v.begin(), v.end(), LessInt()));
}

// --------- Single element ---------
TEST(IsSortedCompTest, SingleElement) {
    int a = 42;
    EXPECT_TRUE(My::is_sorted(&a, &a + 1, LessInt()));
}

// --------- Forward iterator: std::list ---------
TEST(IsSortedCompTest, ListAscending) {
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    EXPECT_TRUE(My::is_sorted(l.begin(), l.end(), LessInt()));
}

TEST(IsSortedCompTest, ListNotSorted) {
    std::list<int> l;
    l.push_back(2);
    l.push_back(1);
    l.push_back(3);
    EXPECT_FALSE(My::is_sorted(l.begin(), l.end(), LessInt()));
}

// --------- Custom struct ---------
struct Point2 {
    int x;
};

struct ComparePoint1 {
    bool operator()(const Point2& a, const Point2& b) const { return a.x < b.x; }
};

TEST(IsSortedCompTest, CustomStruct) {
    Point2 arr[] = {{1}, {2}, {3}};
    EXPECT_TRUE(My::is_sorted(arr, arr + 3, ComparePoint1()));

    Point2 arr2[] = {{3}, {1}, {2}};
    EXPECT_FALSE(My::is_sorted(arr2, arr2 + 3, ComparePoint1()));
}

TEST(NthElementTest, VectorIntDefault) {
    int arr[] = {7, 2, 6, 11, 9, 3, 12, 10, 8, 4, 1, 5};
    const int N = sizeof(arr)/sizeof(int);
    std::vector<int> v(arr, arr + N);

    My::nth_element(v.begin(), v.begin() + 6, v.end());

    int nth = v[6];
    for (int i = 0; i < 6; ++i)
        EXPECT_LE(v[i], nth); 
    for (int i = 7; i < N; ++i)
        EXPECT_GE(v[i], nth); 
}

// ----------- Vector<int> with custom comparator -----------
struct GreaterInt1 {
    bool operator()(int a, int b) const { return a > b; }
};

TEST(NthElementTest, VectorIntCustomComp) {
    int arr[] = {1, 4, 3, 2, 5};
    std::vector<int> v(arr, arr + 5);

    My::nth_element(v.begin(), v.begin() + 2, v.end(), GreaterInt());

    int nth = v[2];
    for (int i = 0; i < 2; ++i)
        EXPECT_GE(v[i], nth); 
    for (int i = 3; i < 5; ++i)
        EXPECT_LE(v[i], nth);
}

// ----------- Array of custom struct -----------
struct Point3 {
    int x;
};

struct ComparePoint3 {
    bool operator()(const Point3& a, const Point3& b) const { return a.x < b.x; }
};

TEST(NthElementTest, CustomStruct) {
    Point3 arr[] = {{5}, {2}, {8}, {1}, {7}};
    const int N = 5;

    My::nth_element(arr, arr + 3, arr + N, ComparePoint3());

    Point3 nth = arr[3];
    for (int i = 0; i < 3; ++i)
        EXPECT_LE(arr[i].x, nth.x);
    for (int i = 4; i < N; ++i)
        EXPECT_GE(arr[i].x, nth.x);
}

TEST(LowerBoundTest, VectorInt) {
    std::vector<int> v;
    for (int i = 0; i < 10; ++i) v.push_back(i);

    std::vector<int>::iterator it = My::lower_bound(v.begin(), v.end(), 5);
    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 5);  // 5 >= 5

    it = My::lower_bound(v.begin(), v.end(), 10);
    EXPECT_EQ(it, v.end());
}

TEST(LowerBoundTest, ListDouble) {
    std::list<double> l;
    for (int i = 0; i < 5; ++i) l.push_back(i*1.5);

    std::list<double>::iterator it = My::lower_bound(l.begin(), l.end(), 2.0);
    ASSERT_NE(it, l.end());
    EXPECT_EQ(*it, 3.0); 
}

struct Descending {
    bool operator()(int a, int b) const { return a > b; }
};

TEST(LowerBoundTest, VectorIntWithComparator) {
    std::vector<int> v;
    for (int i = 10; i > 0; --i) v.push_back(i); // 10,9,8,...,1

    std::vector<int>::iterator it = My::lower_bound(v.begin(), v.end(), 5, Descending());
    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 5); 
}


TEST(LowerBoundTest, EmptyVector) {
    std::vector<int> v;
    std::vector<int>::iterator it = My::lower_bound(v.begin(), v.end(), 0);
    EXPECT_EQ(it, v.end());
}

TEST(LowerBoundTest, SingleElementVector) {
    std::vector<int> v; v.push_back(7);
    std::vector<int>::iterator it = My::lower_bound(v.begin(), v.end(), 7);
    ASSERT_NE(it, v.end());
    EXPECT_EQ(*it, 7);

    it = My::lower_bound(v.begin(), v.end(), 10);
    EXPECT_EQ(it, v.end());
}

TEST(UpperBoundTest, SimpleAscending) {
    std::vector<int> v;
    for(int i=0; i<5; ++i) v.push_back(i); // {0,1,2,3,4}

    std::vector<int>::iterator it;

    it = My::upper_bound(v.begin(), v.end(), 2);
    ASSERT_EQ(*it, 3);

    it = My::upper_bound(v.begin(), v.end(), 4);
    ASSERT_EQ(it, v.end());

    it = My::upper_bound(v.begin(), v.end(), -1);
    ASSERT_EQ(*it, 0);
}

TEST(UpperBoundTest, AllEqual) {
    std::vector<int> v(5, 7); // {7,7,7,7,7}

    std::vector<int>::iterator it;
    it = My::upper_bound(v.begin(), v.end(), 7);
    ASSERT_EQ(it, v.end());

    it = My::upper_bound(v.begin(), v.end(), 6);
    ASSERT_EQ(*it, 7);
}
/// binary
TEST(BinarySearchTest, IntVectorPresent) {
    std::vector<int> v;
    for (int i = 1; i <= 10; ++i) v.push_back(i);

    for (int i = 1; i <= 10; ++i) {
        bool expected = true; 
        EXPECT_EQ(My::binary_search(v.begin(), v.end(), i), expected);
    }
}

TEST(BinarySearchTest, IntVectorNotPresent) {
    std::vector<int> v;
    for (int i = 1; i <= 5; ++i) v.push_back(i);

    for (int i = 6; i <= 10; ++i) {
        bool expected = false; 
        EXPECT_EQ(My::binary_search(v.begin(), v.end(), i), expected);
    }
}

TEST(BinarySearchTest, CustomComparator) {
    std::vector<int> v;
    v.push_back(7); v.push_back(5); v.push_back(3); v.push_back(1);

    struct Greater {
        bool operator()(int a, int b) const { return a > b; }
    };

    EXPECT_TRUE(My::binary_search(v.begin(), v.end(), 7, Greater()));
    EXPECT_TRUE(My::binary_search(v.begin(), v.end(), 3, Greater()));
    EXPECT_FALSE(My::binary_search(v.begin(), v.end(), 2, Greater()));
    EXPECT_FALSE(My::binary_search(v.begin(), v.end(), 0, Greater()));
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

