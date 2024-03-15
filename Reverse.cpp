
#include <iostream>

template <typename Itr>
void reverse ( Itr First, Itr Last ){

	for(auto it = First; it != Last; it++){
		--Last;
		Itr Temp = *Last;
		*Last = *it;
		*it = Temp;
	}

}