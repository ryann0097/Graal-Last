#ifndef GRAAL_H
#define GRAAL_H

#include <utility>
using std::pair;

namespace graal {

/*!
 * Finds and returns a pair with the smallest and greatest elements in a range.
 *
 * @tparam Itr Iterator to the range.
 * @tparam Compare A regular comparison function.Comparison functor.
 *
 * @param first_ Pointer to the first element of the range we want to copy (inclusive).
 * @param last_ Pointer to the last element of the range we want to copy (exclusive).
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
			if(cmp(*pointerTwo, *it) || it >= pointerTwo){pointerTwo = it;}
		}
	}
  return std::make_pair(pointerOne, pointerTwo);
}

/**
 * 
 * Doxygen reverse
 * 
 * 
 * 
 * 
 * 
*/

template <class BidirIt> void reverse(BidirIt first, BidirIt last) {
  auto Alcance = last - first;
  for(int i = 0; i < Alcance/2; i++){
    int Troca = Alcance-i-1;
    BidirIt Temp = *(first + i);
    *(first + i) = *(first + Troca);
    *(first + Troca) = Temp;
  }
}

/**
 * 
 * 
 * 
 * doxygen copy
 * 
 * 
 * 
 * 
*/

template <class InputIt> InputIt copy(InputIt first, InputIt last, InputIt d_first) {

  while(first != last){
    *d_first = *first;
    first++;
    d_first++;
  }
  return d_first;
}

/**
 * 
 * 
 * 
 *  doxygen find_if
 * 
 * 
 * 
*/
template <class InputIt, class UnaryPredicate>
InputIt find_if(InputIt first, InputIt last, UnaryPredicate p) {
  
  InputIt *pointerOne = first;
  InputIt *pointerTwo = last;

  while(pointerOne != pointerTwo){
    if(p(*pointerOne)){return pointerOne;}
    pointerOne++;
  }

  /*
  * Why i'm not using the pointerTwo to return the "last" element?
  * Nah, it's simple ash. If the pointer didn't find any occurences,
  * it's obvius that it had percurred over all the array and it's pointing
  * to the last element. Simple, simple.
  */
  return pointerOne; 
}

/**
 * 
 * doxygen companion
*/

template <class InputIt, class UnaryPredicate>
bool all_of(InputIt first, InputIt last, UnaryPredicate p) {
  InputIt *pointerOne = first;
  InputIt *pointerTwo = last;

  while(p(*pointerOne)){*pointerOne++;}
  return (pointerOne == pointerTwo);  // Just a STUB.
}

template <class InputIt, class UnaryPredicate>
bool any_of(InputIt first, InputIt last, UnaryPredicate p) {
  InputIt *pointerOne = {first};
  InputIt *pointerTwo = {last};

  do{
    if(p(*pointerOne)){return true;}
    *pointerOne++;
  } while(!(p(*pointerOne)));

  return false;
}

template <class InputIt, class UnaryPredicate>
bool none_of(InputIt first, InputIt last, UnaryPredicate p) {
  InputIt *pointerOne = {first};
  InputIt *pointerTwo = {last};

  while(!(p(*pointerOne))){*pointerOne++;}
  return (pointerOne == pointerTwo);
}

template <class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, Equal eq) {
  // TODO: add your code here.
  return true;  // Just a STUB.
}

template <class InputIt1, class InputIt2, class Equal>
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Equal eq) {
  // TODO: add your code here.
  return true;  // Just a STUB.
}

template <class InputIt, class Equal> InputIt unique(InputIt first, InputIt last, Equal eq) {
  // TODO: add your code here.
  return first;  // This is just a stub.
}

template <class ForwardIt, class UnaryPredicate>
ForwardIt partition(ForwardIt first, ForwardIt last, UnaryPredicate p) {
  // TODO: add your code here.
  return first;  // This is just a stub.
}

}  // namespace graal.

#endif
