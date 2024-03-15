#include <iostream>

template < typename Itr >
Itr Copy ( Itr First, Itr Last, Itr d_first){

	for(d_first = First; d_first != Last; d_first++){
		*d_first = *First;
		First++;
	}

	return --d_first;
}


bool p( const Type& a0){}
template < typename Itr, typename Predicate >
Itr find_if ( Itr First, Itr Last, Predicate P){

}


