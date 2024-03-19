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

template <typename Itr> 
Itr copy(Itr first, Itr last, Itr d_first) {
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

template <typename Type>
bool p (const Type &a);

template <typename Itr, typename Predicate>
bool all_of(Itr first, Itr last, Predicate p) {
  Itr pointerOne = first;
  Itr pointerTwo = last;

  while(pointerOne != pointerTwo && p(*pointerOne)){pointerOne++;}
  return (pointerOne == pointerTwo);  
}

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

template <typename Itr, typename Predicate>
bool none_of(Itr first, Itr last, Predicate p) {
  Itr pointerOne = first;
  Itr pointerTwo = last;

  while(pointerOne != pointerTwo && !(p(*pointerOne))){
    pointerOne++;
  }
  return (pointerOne == pointerTwo);
}

/*
 *
 * EQUAL OVERLOADED FUNCTIONS
 *  
*/
template <typename Type>
bool eq(const Type &a, const Type &b){
  return(a == b);
}

template <typename Itr, typename Equal>
bool equal(Itr first1, Itr last1, Itr first2, Equal eq) {

  int FullRange = last1-first1;
  int HalfRange = first2+FullRange;
  //Primeiro range é full range
  //Segundo range é first2, até first2+full range
  return eq(FullRange, HalfRange);
}

/*full erros*/

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

/*template <typename Type>
bool eq(const Type &a, const Type &b){
  return (a == b);
}*/

template <typename Itr, typename Equal> 
Itr unique(Itr first, Itr last, Equal eq) {
  Itr pointerOne = first;
  Itr pointerTwo = first;

  while(pointerOne != last){
    for(auto it = first; it != pointerOne; it++){
      if(!(eq(*pointerOne, *it))){  
        *pointerTwo = *pointerOne;
        pointerTwo++;
      }
    }
    pointerOne++;
  }

  return pointerTwo;
}

template <typename Type>
bool p( const Type &a);

template <typename Itr, typename Predicate>
Itr partition(Itr first, Itr last, Predicate p) {
  Itr pointerOne = first;
  Itr pointerTwo = first;

  while(pointerOne != last){
    if(!p(*pointerOne)){
      *pointerTwo = *pointerOne;
      pointerTwo++;
    }
    pointerOne++;
  }

  return pointerTwo;
}

}  

#endif
