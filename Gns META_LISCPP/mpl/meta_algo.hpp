/** 
	* Copyright (C) 2014 Ganesh Prasad Sahoo - All Rights Reserved
	* You may use, distribute and modify this code under the
	* terms of the GNU GPL V3 license. 
	*
	* You should have received a copy of the GNU GPL V3 license with
	* this file. If not, please write to: sir.gnsp@gmail.com , or visit : http://www.gnu.org/licenses/gpl.txt
*/



#ifndef _GNS_META_ALGO_V1
#define _GNS_META_ALGO_V1

#include "meta_def.hpp"

namespace gns{ namespace mpl{

// Meta algorithm for sqrt of int

template	<typename intType, intType A, intType B = 0, intType C = ((A==1) ? 1 : A/2), 
			bool is_complete = ((C-B)<=1 ? true : ((C*C <= A) && ((C+1)*(C+1) > A))) >
class meta_sqrt
{
	private:
		static const intType Temp = (B+C)/2;
		static const intType State = (Temp * Temp) > A ? 1:0;
		static const intType NewState = intType(State) ? B : intType(Temp) ;
		static const intType C_prime = intType(State) ? intType(Temp) : C;
	public: 
		static const int RET = meta_sqrt<intType,A,NewState,C_prime>::RET;
};

template<typename intType, intType A, intType B, intType C>
class meta_sqrt<intType,A, B, C, true> { 
	public:  
		static const intType RET = ((C*C) <= A) ? C : B;
};

//meta algorithm for GCD of two integers

template <typename intType, intType A, intType B, bool is_complete = (B==0) >
struct meta_gcd{
	static const intType RET = meta_gcd < intType, B, A%B >::RET;
};
template < typename intType, intType A, intType B>
struct meta_gcd < intType, A, B, true >{
	static const intType RET = A;
};

// meta algorithm for pow

template <typename intType, intType Base, intType Exponent, bool done = Exponent == 0 >
struct meta_pow{
	static const intType RET = ( Exponent & 1 ) ? (	meta_pow < intType, Base, Exponent>>1 >::RET 
														* meta_pow < intType, Base, Exponent>>1 >::RET
														* Base )
													:(	meta_pow < intType, Base, Exponent>>1 >::RET 
														* meta_pow < intType, Base, Exponent>>1 >::RET);
};
template <typename intType, intType Base, intType Exponent>
struct meta_pow<intType, Base, Exponent,true>{
	static const intType RET = 1;
};
 									

}}
#endif