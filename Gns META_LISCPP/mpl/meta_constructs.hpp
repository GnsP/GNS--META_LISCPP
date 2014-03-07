/** 
	* Copyright (C) 2014 Ganesh Prasad Sahoo - All Rights Reserved
	* You may use, distribute and modify this code under the
	* terms of the GNU GPL V3 license. 
	*
	* You should have received a copy of the GNU GPL V3 license with
	* this file. If not, please write to: sir.gnsp@gmail.com , or visit : http://www.gnu.org/licenses/gpl.txt
*/


#ifndef _GNS_META_CONSTRUCTS_V1
#define _GNS_META_CONSTRUCTS_V1

#include "meta_def.hpp"

namespace gns{ namespace mpl{

// Meta Construct IF

template < bool cond, typename T, typename F >
struct IF { typedef T value_type; };	
template <typename T,typename F>
struct IF<false,T,F> { typedef F value_type; };

//Meta Construct FOR

template <typename T,T Current, T End, T step, class Functor, bool done = !(Current+step < End)>
struct FOR{
	static inline void DO(){
	    static Functor f;
		f(Current);
		FOR <T, Current+step, End, step, Functor >::DO();
	}
};

template <typename T,T Current,T End, T step, class Functor>
struct FOR <T, Current,End,step,Functor,true> {
	static inline void DO(){
	    static Functor f;
		f(Current);
	}
};
			
}}

#endif