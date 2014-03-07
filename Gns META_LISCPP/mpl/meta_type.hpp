/** 
	* Copyright (C) 2014 Ganesh Prasad Sahoo - All Rights Reserved
	* You may use, distribute and modify this code under the
	* terms of the GNU GPL V3 license. 
	*
	* You should have received a copy of the GNU GPL V3 license with
	* this file. If not, please write to: sir.gnsp@gmail.com , or visit : http://www.gnu.org/licenses/gpl.txt
*/




#ifndef _GNS_META_TYPE_V1
#define _GNS_META_TYPE_V1

#include "meta_def.hpp"
#include "meta_algo.hpp"

namespace gns{ namespace mpl{

//meta type RATIONAL

template< int N, int D = 1>
struct RATIONAL
{
    static const int numerator = N;
	static const int denominator = D;
	
    typedef RATIONAL < N, D> value_type;
    RATIONAL() {}
};

//meta type FLOAT

template < int S, int E, int M >
struct FLOAT{
	static const int mantissa = M;
	static const int exponent = E;
	static const int sign = S;
	
	typedef FLOAT < S, M, E > value_type;
	FLOAT () {}
};

// meta type INT
template <int N> struct INT { static const int RET = N; };



}}
#endif