#ifndef GRAAL_CPP_
#define GRAAL_CPP_

#include <iostream>

template <typename T>
bool cmp(const T& elementOne, const T& elementTwo){
    return elementOne < elementTwo;
}


template< typename Itr, typename Compare >
std::pair<Itr, Itr> MinMax (Itr First, Itr Last, Compare cmp){

	if(First == Last){return std::make_pair<First, First>;}
	else{
		Itr Smallest = &First, Largest = &First;
		for(auto it = First; it != Last; it++){
			if(cmp(*it, *Smallest)){
				Smallest = *it;
			}
			if(cmp(*Largest, *it) || it >= Largest){
				Largest = it;
			}
		}
	}

	return std::make_pair<Smallest, Largest>

}

