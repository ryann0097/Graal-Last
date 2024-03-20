#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;

namespace graal {

/*!
 * Finds and returns a pair with the smallest and greatest elements in a range.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Compare A regular comparison function. Comparison functor.
 *
 * @param first_ Pointer to the first element of the range (inclusive).
 * @param last_ Pointer to the last element of the range (exclusive).
 * @param cmp The comparison function that return true if the first element is *less* than the
 * second.
 *
 * @return A pair of the smallest and greatest elements.
 *
 */

template <typename T>
  bool cmp(const T& elementOne, const T& elementTwo){return elementOne < elementTwo;}

template< typename Itr, typename Compare >
  std::pair<Itr, Itr> minmax (Itr first, Itr last, Compare cmp){
   Itr pointerOne = first;
   Itr pointerTwo = first;

   if(first == last){return std::make_pair(first, first);}
   else{
    for(auto it = first; it != last; it++){
     if(cmp(*it, *pointerOne)){pointerOne = it;}
     if(cmp(*pointerTwo, *it) || *it >= *pointerTwo){pointerTwo = it;}
   }
 }
 return std::make_pair(pointerOne, pointerTwo);
}

/*!
 * Reverses the order of the elements in a range.
 *
 * @tparam Itr Iterator to the range.
 *
 * @param first_ Pointer to the first element of the range we want to reverse (inclusive).
 * @param last_ Pointer to the last element of the range we want to reverse (exclusive).
 *
 */

template <typename Itr> 
void reverse(Itr first, Itr last) {
  auto Alcance = last - first;
  for (int i = 0; i < Alcance / 2; i++) {
    auto Troca = Alcance - i - 1;
    auto Temp = *(first + i);
    *(first + i) = *(first + Troca);
    *(first + Troca) = Temp;
  }
}

/*!
 * Copies the range values into a new range beginning.
 *
 * @tparam Itr Iterator to the range.
 *
 * @param first_ Pointer to the first element of the range (inclusive).
 * @param last_ Pointer to the last element of the range (exclusive).
 *
 * @return A pointer to the position just past the last element copied.
 *
 */

template <typename Itr> 
Itr copy(Itr first, Itr last, Itr d_first) {
  while(first != last){
    *d_first = *first;
    first++;
    d_first++;
  }
  return d_first;
}

/*!
 * Finds and return a pointer to the first element in the range for which a given predicate p returns true.
 *
 * @tparam Itr Iterator to the range.
 * @tparam An unary predicate that will be given by the user.
 *
 * @param first_ Pointer to the first element of the range (inclusive).
 * @param last_ Pointer to the last element of the range (exclusive).
 * @param p_ Predicate which return true for the required element.
 *
 * @return A pointer to the first element that satisfied the condition or last, if no such element was found.
 *
 */

template <typename Type>
bool p (const Type &a);

template <typename Itr, typename Predicate>
Itr find_if(Itr first, Itr last, Predicate p) {
  Itr pointerOne = first;
  Itr pointerTwo = last;

  while(pointerOne != pointerTwo){
    if(p(*pointerOne)){return pointerOne;}
    pointerOne++;
  }
  return last; 
}

/*!
 * Receive a range and a given prediacte. Returns true if the predicate returns true for all elements
 * in the range.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Predicate A predicate unary.
 *
 * @param first_ Pointer to the first element of the range (inclusive).
 * @param last_ Pointer to the last element of the range (exclusive).
 * @param p Predicate which returns true if the element satisfies the condition.
 *
 * @return A boolean value true, in the case which the range is empty or if all elements, or false,
 * if none of the elements of the range satisfies the condition.
 *
 */

template <typename Type>
bool p (const Type &a);

template <typename Itr, typename Predicate>
bool all_of(Itr first, Itr last, Predicate p) {
  Itr pointerOne = first;
  Itr pointerTwo = last;

  while(pointerOne != pointerTwo && p(*pointerOne)){pointerOne++;}
  return (pointerOne == pointerTwo);  
}

/*!
 * Receive a range and a given prediacte. Returns true if at least one element in the range satisfies
 * the condition.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Predicate A predicate unary.
 *
 * @param first_ Pointer to the first element of the range (inclusive).
 * @param last_ Pointer to the last element of the range (exclusive).
 * @param p An unary predicate that will be given by the user.
 *
 * @return A boolean value true if at least one element satisfies the condition, or false,
 * in the case which the range is empty or if none element satisfies the condition.
 *
 */

template <typename Itr, typename Predicate>
bool any_of(Itr first, Itr last, Predicate p) {
  Itr pointerOne = first;
  Itr pointerTwo = last;

  while(pointerOne != pointerTwo){
    if(p(*pointerOne)){
      return true;
    }
    pointerOne++;
  }
  return false;
}

/*!
 * Receive a range and a given prediacte. Returns true if the predicate returns true for all elements
 * in the range.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Predicate A predicate unary.
 *
 * @param first_ Pointer to the first element of the range (inclusive).
 * @param last_ Pointer to the last element of the range (exclusive).
 * @param p An unary predicate that will be given by the user.
 *
 * @return A boolean value true, in the case which the range is empty or if all elements, or false,
 * if none of the elements of the range satisfies the condition.
 *
 */

template <typename Itr, typename Predicate>
bool none_of(Itr first, Itr last, Predicate p) {
  Itr pointerOne = first;
  Itr pointerTwo = last;

  while(pointerOne != pointerTwo && !(p(*pointerOne))){
    pointerOne++;
  }
  return (pointerOne == pointerTwo);
}

template <typename Type>
bool eq(const Type &a, const Type &b){
  return(a == b);
}

/*!
 * Receives two ranges and verifies if it are equal and return the equality response.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Equal A regular equality function. Equality functor.
 *
 * @param first1_ Pointer to the first element of the first range (inclusive).
 * @param last1_ Pointer to the last element of the first range (exclusive).
 * @param first2_ Pointer to the first element of the second range (inclusive).
 * @param eq The equality function return true if the two elements are equal and false otherwise.
 *
 * @return A boolean value true if the two elements correspond the equality and false if not.
 *
 */

template <typename Itr, typename Equal>
bool equal(Itr first1, Itr last1, Itr first2, Equal eq) {

  while(first1 != last1){
    if(!eq(*first1, *first2)){return false;}
    first1++;
    first2++;
  }
  return true;
}

/*!
 * Receives two ranges and verifies if their elements are equal and return the equality response.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Equal A regular equality function. Equality functor.
 *
 * @param first1_ Pointer to the first element of the first range (inclusive).
 * @param last1_ Pointer to the last element of the first range (exclusive).
 * @param first2_ Pointer to the first element of the second range (inclusive).
 * @param last2_ Pointer to the last element of the second range (exclusive).
 * @param eq The equality function return true if the two elements are equal and false otherwise.
 *
 * @return A boolean value true if all the elements in the ranges are equal, and false otherwise.
 *
 */

template <typename Itr, typename Equal>
bool equal(Itr first1, Itr last1, Itr first2, Itr last2, Equal eq) {

  Itr pointerOne = first1;
  Itr pointerTwo = first2;
  while(pointerOne != last1 && pointerTwo != last2 && eq(*pointerOne, *pointerTwo)){
    pointerOne++;
    pointerTwo++;
  }

  return (pointerOne == last1);
}

/*!
 * Receives a range of elements, rearrange the elements in the range in a way that the non-duplicated 
 * elements are located at the beginning of the array. Returns a pointer to the address with the last element
 * of the range with unique elements.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Equal A regular equality function. Equality functor.
 *
 * @param first_ Pointer to the first element of the range (inclusive).
 * @param last_ Pointer to the last element of the range (exclusive).
 * @param eq The equality function return true if the two elements are equal and false otherwise.
 *
 * @return A pointer to the address with the last element of the range with unique elements.
 *
 */

template <typename Itr, typename Equal> 
Itr unique(Itr first, Itr last, Equal eq) {
  if (first == last) return last;

  Itr pointerOne = first;
  while (++first != last) {
    if (!eq(*pointerOne, *first)) {
      *(++pointerOne) = *first;
    }
  }
  return ++pointerOne;

}

/**/

template <typename Type>
bool p( const Type &a);

/*!
 * Receives a range and reorders in such way that all elements for which given preidcate p returns
 * true precede the elements for which predicate returns false and returns a pointer to the beginning of
 * the range which p returns false.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Compare A regular comparison function.Comparison functor.
 *
 * @param first_ Pointer to the first element of the range (inclusive).
 * @param last_ Pointer to the last element of the range (exclusive).
 * @param p_ An unary predicate that will be given by the user.
 *
 * @return A pointer to the beginning of the range which p returns false.
 *
 */

template <typename Itr, typename Predicate>
Itr partition(Itr first, Itr last, Predicate p) {
  Itr pointerOne = first;
  Itr pointerTwo = first;

  while(pointerOne != last){
    if(p(*pointerOne)){
      *pointerTwo = *pointerOne;
      pointerTwo++;
    }
    pointerOne++;
  }

  return pointerTwo;
}

}  

#endif
