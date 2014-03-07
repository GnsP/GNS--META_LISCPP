/** 
	* Copyright (C) 2014 Ganesh Prasad Sahoo - All Rights Reserved
	* You may use, distribute and modify this code under the
	* terms of the GNU GPL V3 license. 
	*
	* You should have received a copy of the GNU GPL V3 license with
	* this file. If not, please write to: sir.gnsp@gmail.com , or visit : http://www.gnu.org/licenses/gpl.txt
*/



#ifndef _GNS_META_BASIC_V1
#define _GNS_META_BASIC_V1

#include "meta_def.hpp"

namespace gns{ namespace mpl{

template <typename A,typename B>
struct same_type { static const bool RET = false; };		// true if two types are the same and false if they are not
template <typename A>
struct same_type<A,A> { static const bool RET = true; };

/**
	Templates to recognize Numeric Types.
*/
template <typename T> struct is_numeric { static const bool RET = false; };
template<> struct is_numeric <bool> { static const bool RET = true; };
template<> struct is_numeric <signed char> { static const bool RET = true; };
template<> struct is_numeric <unsigned char> { static const bool RET = true; };
template<> struct is_numeric <signed short> { static const bool RET = true; };
template<> struct is_numeric <unsigned short> { static const bool RET = true; };
template<> struct is_numeric <signed int> { static const bool RET = true; };
template<> struct is_numeric <unsigned int> { static const bool RET = true; };
template<> struct is_numeric <signed long> { static const bool RET = true; };
template<> struct is_numeric <unsigned long> { static const bool RET = true; };
template<> struct is_numeric <signed long long> { static const bool RET = true; };
template<> struct is_numeric <unsigned long long> { static const bool RET = true; };
template<> struct is_numeric <float> { static const bool RET = true; };
template<> struct is_numeric <double> { static const bool RET = true; };
template<> struct is_numeric <long double> { static const bool RET = true; };

/**
	Macro def to add user defined types like complex to numeric_types
	Usage : use this in global namespace
*/
#ifdef ALLOW_NEW_NUMERIC_TYPES__	
#define ADD_TO_NUMERIC_TYPES( type_name ) \
	namespace gns{ namespace mpl{ \
	template <> struct is_numeric <type_name> { static const bool RET = true; }; \
	}}}
#endif


template <typename T> struct is_integer { static const bool RET = false; };
template<> struct is_integer <bool> { static const bool RET = true; };
template<> struct is_integer <signed char> { static const bool RET = true; };
template<> struct is_integer <unsigned char> { static const bool RET = true; };
template<> struct is_integer <signed short> { static const bool RET = true; };
template<> struct is_integer <unsigned short> { static const bool RET = true; };
template<> struct is_integer <signed int> { static const bool RET = true; };
template<> struct is_integer <unsigned int> { static const bool RET = true; };
template<> struct is_integer <signed long> { static const bool RET = true; };
template<> struct is_integer <unsigned long> { static const bool RET = true; };
template<> struct is_integer <signed long long> { static const bool RET = true; };
template<> struct is_integer <unsigned long long> { static const bool RET = true; };

/**
	Macro def to add user defined types like big_int to intger_types
	Usage : use this in global namespace
*/
#ifdef ALLOW_NEW_INTEGER_TYPES__	
#define ADD_TO_INTEGER_TYPES( type_name ) \
	namespace gns{ namespace mpl { \
	template <> struct is_integer <type_name> { static const bool RET = true; }; \
	}}}
#endif

	
template <typename T> struct remove_reference { typedef T value_type; };			
template <typename T> struct remove_reference<T&> { typedef T value_type; };

template <typename T> struct remove_pointer { typedef T value_type; };
template <typename T> struct remove_pointer <T*> { typedef T value_type; };
template <typename T> struct remove_pointer <T* const> { typedef T value_type; };

template <typename T> struct remove_const { typedef T value_type; };
template <typename T> struct remove_const <const T> { typedef T value_type; };
template <typename T> struct remove_const <const T[]> { typedef T value_type[]; };
template <typename T, unsigned int S> struct remove_const <const T[S]> { typedef T value_type[S]; };

template <typename T> struct remove_all { typedef T value_type; };
template <typename T> struct remove_all <const T> { typedef typename remove_all<T>::value_type value_type; };
template <typename T> struct remove_all <T const &> { typedef typename remove_all<T>::value_type value_type; };
template <typename T> struct remove_all <T const *> { typedef typename remove_all<T>::value_type value_type; };
template <typename T> struct remove_all <T&> { typedef typename remove_all<T>::value_type value_type; };
template <typename T> struct remove_all <T*> { typedef typename remove_all<T>::value_type value_type; };

template <typename T> struct is_reference { static const bool RET = false; };
template <typename T> struct is_reference<T&> { static const bool RET = true; };
template <typename T> struct is_reference<T const &> { static const bool RET = true; };

template <typename T> struct is_pointer { static const bool RET = false; };
template <typename T> struct is_pointer <T*> { static const bool RET = true; };
template <typename T> struct is_pointer <T const*> { static const bool RET = true; };

template <typename T> struct is_const { static const bool RET = false; };
template <typename T> struct is_const <const T> { static const bool RET = true; };
template <typename T> struct is_const <T const &> { static const bool RET = true; };
template <typename T> struct is_const <T const *> { static const bool RET = true; };

template <typename T> struct make_const { typedef const T value_type; };
template <typename T> struct make_const <T&> { typedef T& value_type; };

template <typename T> struct make_const_type { typedef const T value_type; };
template <typename T> struct make_const_type <T &> { typedef T const & value_type; };
template <typename T> struct make_const_type <T *> { typedef T const * value_type; };
template <typename T> struct make_const_type <T * const> { typedef T const * const value_type; };
template <typename T> struct make_const_type <T const * const > { typedef T const * const value_type; };

}}
#endif
