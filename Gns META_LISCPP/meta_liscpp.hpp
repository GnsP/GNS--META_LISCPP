/** 
	* Copyright (C) 2014 Ganesh Prasad Sahoo - All Rights Reserved
	* You may use, distribute and modify this code under the
	* terms of the GNU GPL V3 license. 
	*
	* You should have received a copy of the GNU GPL V3 license with
	* this file. If not, please write to: sir.gnsp@gmail.com , or visit : http://www.gnu.org/licenses/gpl.txt
*/




#ifndef _GNS_META_LISCPP_DEF_V1
#define _GNS_META_LISCPP_DEF_V1

#include "mpl/meta_basic.hpp"
#include "mpl/meta_type.hpp"
#include "mpl/meta_algo.hpp"
#include "mpl/meta_constructs.hpp"

namespace gns { namespace meta_liscpp {

#define SETQ(name,exp...) typedef exp name;
#define EVAL(Exp...) Exp::RET

template < typename T, T var>
struct var_{
	typedef T value_type;
	static const T RET = var;
};
#define VAR(TypeName, Identifier, Value ) typedef var_<TypeName,Value> Identifier;

/**
	INBUILT META_LISCPP FUNCTIONS
	-----------------------------
		1.	PLUS
		2.	DIFFERENCE
		3.	MULTIPLY
		4.	QUOTIENT
		5.	REMAINDER
		6.	MINUS
		7.	POW
		8. 	SQRT
		9.	GCD
		10.	AND
		11. OR
		12. NOT
*/


template <typename A, typename B>
struct plus_ {
	struct retVar_ {
		typedef typename gns::mpl::IF < gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET, 
								typename A::value_type,
								emptyType > :: value_type value_type;
		static const value_type RET = A::RET + B::RET;
	};
	typedef retVar_ RET;
};
#define PLUS(A,B) typename plus_<A,B>::RET
#define PLUS_OP(A,B) plus_<A,B>::RET

template <typename A, typename B>
struct diff_ {
	struct retVar_ {
		typedef typename gns::mpl::IF < gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET, 
								typename A::value_type,
								emptyType > :: value_type value_type;
		static const value_type RET = A::RET - B::RET;
	};
	typedef retVar_ RET;
};
#define DIFFERENCE(A,B) typename diff_<A,B>::RET
#define DIFFERENCE_OP(A,B) diff_<A,B>::RET

template <typename A, typename B>
struct mult_ {
	struct retVar_ {
		typedef typename gns::mpl::IF < gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET, 
								typename A::value_type,
								emptyType > :: value_type value_type;
		static const value_type RET = A::RET * B::RET;
	};
	typedef retVar_ RET;
};
#define MULTIPLY(A,B) typename mult_<A,B>::RET
#define MULTIPLY_OP(A,B) mult_<A,B>::RET

template <typename A, typename B>
struct quotient_ {
	struct retVar_ {
		typedef typename gns::mpl::IF < gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET, 
								typename A::value_type,
								emptyType > :: value_type value_type;
		static const value_type RET = A::RET / B::RET;
	};
	typedef retVar_ RET;
};
#define QUOTIENT(A,B) typename quotient_<A,B>::RET
#define QUOTIENT_OP(A,B) quotient_<A,B>::RET

template <typename A, typename B>
struct remainder_ {
	struct retVar_ {
		typedef typename gns::mpl::IF < gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET, 
								typename A::value_type,
								emptyType > :: value_type value_type;
		static const value_type RET = A::RET % B::RET;
	};
	typedef retVar_ RET;
};
#define REMAINDER(A,B) typename remainder_<A,B>::RET
#define REMAINDER_OP(A,B) remainder_<A,B>::RET

template <typename A>
struct minus_ {
	struct retVar_ {
		typedef typename A:: value_type value_type;
		static const value_type RET = -(A::RET);
	};
	typedef retVar_ RET;
};
#define MINUS(A) typename minus_<A>::RET
#define MINUS_OP(A) minus_<A>::RET

template <typename A, typename B>
struct power_ {
	struct retVar_ {
		typedef typename gns::mpl::IF < gns::mpl::same_type < typename  A::value_type, typename B::value_type >::RET, 
								typename A::value_type,
								emptyType > :: value_type value_type;
		static const value_type RET = gns::mpl::meta_pow <value_type, A::RET, B::RET>::RET;
	};
	typedef retVar_ RET;
};
#define POW(A,B) typename power_<A,B>::RET
#define POW_OP(A,B) power_<A,B>::RET

template <typename A>
struct sqrt_ {
	struct retVar_ {
		typedef typename A::value_type value_type;
		static const value_type RET = gns::mpl::meta_sqrt <value_type, A::RET>::RET;
	};
	typedef retVar_ RET;
};
#define SQRT(A) typename sqrt_<A>::RET
#define SQRT_OP(A) sqrt_<A>::RET

template <typename A, typename B>
struct gcd_ {
	struct retVar_ {
		typedef typename gns::mpl::IF < gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET, 
								typename A::value_type,
								emptyType > :: value_type value_type;
		static const value_type RET = gns::mpl::meta_gcd <value_type, A::RET, B::RET>::RET;
	};
	typedef retVar_ RET;
};
#define GCD(A,B) typename gcd_<A,B>::RET
#define GCD_OP(A,B) gcd_<A,B>::RET

template <typename A, typename B>
struct and_ {
	struct retVar_ {
		typedef bool value_type;
		static const value_type RET = gns::mpl::IF< gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET,
										 typename gns::mpl::IF < A::RET == 0 || B::RET == 0, NIL, TRUE >::RET,
										 NIL >::RET::RET;
	};
	typedef retVar_ RET;
};
#define AND(A,B) typename and_<A,B>::RET
#define AND_OP(A,B) and_<A,B>::RET

template <typename A, typename B>
struct or_ {
	struct retVar_ {
		typedef bool value_type;
		static const value_type RET = gns::mpl::IF< gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET,
										 typename gns::mpl::IF < A::RET == 0 && B::RET == 0, NIL, TRUE >::RET,
										 NIL >::RET::RET;
	};
	typedef retVar_ RET;
};
#define OR(A,B) typename or_<A,B>::RET
#define OR_OP(A,B) or_<A,B>::RET

template <typename A>
struct not_ {
	struct retVar_ {
		typedef bool value_type;
		static const value_type RET = !(A::RET);
	};
	typedef retVar_ RET;
};
#define NOT(A) typename not_<A>::RET
#define NOT_OP(A) not_<A>::RET



/**
	INBUILT META_LISCPP PREDICATES
	------------------------------
		1.	EQ
		2.	GT
		3.	GTE
		4.	LT
		5.	LTE
		6.	ZEROP
		7.	NUMBERP
*/

template <typename A, typename B>
struct eq_ {
	struct retVar_ {
		typedef bool value_type;
		static const bool RET = gns::mpl::IF< gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET,
										typename gns::mpl::IF< A::RET == B::RET, TRUE, NIL >::RET,
										NIL >::RET::RET;
	};
	typedef retVar_ RET;
};
#define EQ(A,B) typename eq_<A,B>::RET
#define EQ_OP(A,B) eq_<A,B>::RET

template <typename A, typename B>
struct gt_ {
	struct retVar_ {
		typedef bool value_type;
		static const bool RET = gns::mpl::IF< gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET,
										typename gns::mpl::IF< ( A::RET > B::RET ), TRUE, NIL >::RET,
										NIL >::RET::RET;
	};
	typedef retVar_ RET;
};
#define GT(A,B) typename gt_<A,B>::RET
#define GT_OP(A,B) gt_<A,B>::RET

template <typename A, typename B>
struct gte_ {
	struct retVar_ {
		typedef bool value_type;
		static const bool RET = gns::mpl::IF< gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET,
										typename gns::mpl::IF< ( A::RET >= B::RET ), TRUE, NIL >::RET,
										NIL >::RET::RET;
	};
	typedef retVar_ RET;
};
#define GTE(A,B) typename gte_<A,B>::RET
#define GTE_OP(A,B) gte_<A,B>::RET

template <typename A, typename B>
struct lt_ {
	struct retVar_ {
		typedef bool value_type;
		static const bool RET = gns::mpl::IF< gns::mpl::same_type < typename A::value_type,typename B::value_type >::RET,
										typename gns::mpl::IF< ( A::RET < B::RET ), TRUE, NIL >::RET,
										NIL >::RET::RET;
	};
	typedef retVar_ RET;
};
#define LT(A,B) typename lt_<A,B>::RET
#define LT_OP(A,B) lt_<A,B>::RET

template <typename A, typename B>
struct lte_ {
	struct retVar_ {
		typedef bool value_type;
		static const bool RET = gns::mpl::IF< gns::mpl::same_type < typename A::value_type, typename B::value_type >::RET,
										typename gns::mpl::IF< ( A::RET <= B::RET ), TRUE, NIL >::RET,
										NIL >::RET::RET;
	};
	typedef retVar_ RET;
};
#define LTE(A,B) typename lte_<A,B>::RET
#define LTE_OP(A,B) lte_<A,B>::RET

template <typename A>
struct zerop_ {
	struct retVar_ {
		typedef bool value_type;
		static const bool RET = A::RET == 0;
	};
	typedef retVar_ RET;
};
#define ZEROP(A) typename zerop_<A>::RET
#define ZEROP_OP(A) zerop_<A>::RET

template <typename A>
struct numberp_ {
	struct retVar_ {
		typedef bool value_type;
		static const bool RET = gns::mpl::is_integer<typename A::value_type>::RET;
	};
	typedef retVar_ RET;
};
#define NUMBERP(A) typename numberp_<A>::RET
#define NUMBERP_OP(A) numberp_<A>::RET

/**
	LIST CONSTRUCT FOR META_LISCPP
	------------------------------
		1.	LIST (Support upto 20 elements... But you can also build longer lists using CONS)
		2.	LEN
		3.	CONS
		4.	CAR
		5.	CDR
*/

template < typename A, typename B >
struct list_ {
	typedef A value_type;
	typedef B next_type;
};

template <typename T> struct len_ ;

template <typename A, typename B>
struct len_ < list_ <A,B> > {
	struct retVar_ {
		typedef int value_type;
		static const value_type RET = 1 + len_ <B> :: RET :: RET;
	};
	typedef retVar_ RET;
};

template <> struct len_ <NIL> {
	struct retVar_ {
		typedef int value_type;
		static const value_type RET = 0;
	};
	typedef retVar_ RET;
};
#define LEN(A) typename len_<A>::RET
#define LEN_OP(A) len_<A>::RET

template <typename A>
struct car_ {
	typedef typename A::value_type RET;
};
#define CAR(A) typename car_<A>::RET
#define CAR_OP(A) car_<A>::RET

template <typename A>
struct cdr_ {
	typedef typename A::next_type RET;
};
#define CDR(A) typename cdr_<A>::RET
#define CDR_OP(A) cdr_<A>::RET

template <typename A, typename B>
struct cons_ {
	typedef list_<A,B> RET;
};
#define CONS(A,B) cons_<A,B>::RET

#define LIST_1(T1) CONS(T1,NIL)
#define LIST_2(T1,T2) CONS(T1,LIST_1(T2))
#define LIST_3(T1,T2,T3) CONS(T1, LIST_2(T2,T3))
#define LIST_4(T1,T2,T3,T4) CONS(T1,LIST_3(T2,T3,T4))
#define LIST_5(T1,T2,T3,T4,T5) CONS(T1,LIST_4(T2,T3,T4,T5))
#define LIST_6(T1,T2,T3,T4,T5,T6) CONS(T1,LIST_5(T2,T3,T4,T5,T6))
#define LIST_7(T1,T2,T3,T4,T5,T6,T7) CONS(T1,LIST_6(T2,T3,T4,T5,T6,T7))
#define LIST_8(T1,T2,T3,T4,T5,T6,T7,T8) CONS(T1,LIST_7(T2,T3,T4,T5,T6,T7,T8))
#define LIST_9(T1,T2,T3,T4,T5,T6,T7,T8,T9) CONS(T1,LIST_8(T2,T3,T4,T5,T6,T7,T8,T9))
#define LIST_10(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10) CONS(T1,LIST_9(T2,T3,T4,T5,T6,T7,T8,T9,T10))
#define LIST_11(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11) CONS(T1,LIST_10(T2,T3,T4,T5,T6,T7,T8,T9,T10,T11))
#define LIST_12(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12) CONS(T1,LIST_11(T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12))
#define LIST_13(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13) CONS(T1,LIST_12(T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13))
#define LIST_14(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14) CONS(T1,LIST_13(T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14))
#define LIST_15(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15) CONS(T1,LIST_14(T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15))
#define LIST_16(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16) CONS(T1,LIST_15(T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16))
#define LIST_17(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17) CONS(T1,LIST_16(T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T!7))
#define LIST_18(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18) CONS(T1,LIST_17(T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18))
#define LIST_19(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19) CONS(T1,LIST_18(T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19))
#define LIST_20(T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20) CONS(T1,LIST_19(T2,T3,T4,T5,T6,T7,T8,T9,T10,T11,T12,T13,T14,T15,T16,T17,T18,T19,T20))



/**
	COND AND LAMBDA
	---------------
		1.	COND 	: Implemeted as a list of conditionals to support lazy evaluation
		2.	LAMBDA	: Declaration of unnamed functions, should be used with SETQ to assign names
					  Supports upto functions taking 3 arguments
					  Doesn't support variadic lambda, user must do manual currying
		3.	APPLY	: Application of LAMBDA over a value
*/

template <typename  A, typename B, typename C>
struct cond_ {
	typedef typename gns::mpl::IF<A::RET, B, C>::value_type RET;
};
#define COND(A,B,C) typename cond_<A,B,C>::RET
#define COND_OP(A,B,C) cond_<A,B,C>::RET


struct __lambda_1{
    template < template <typename A> class Expr >
    struct use {
        struct type{
            template <typename X>
            struct apply{
                typedef typename Expr<X>::RET RET;
            };
            typedef type RET;
        };
    };
};
#define LAMBDA_1(Name,A,Expr) 	template <typename A>\
										struct Name {\
											typedef Expr RET; \
										};                        
#define APPLY_1(Fun,A)	__lambda_1::use<Fun>::type::apply<A>::RET


struct __lambda_2{
    template < template <typename A, typename B> class Expr >
    struct use {
        struct type{
            template <typename X, typename Y>
            struct apply{
                typedef typename Expr<X,Y>::RET RET;
            };
            typedef type RET;
        };
    };
};
#define LAMBDA_2(Name,A,B,Expr) 	template <typename A, typename B>\
										struct Name {\
											typedef Expr RET; \
										};                        
#define APPLY_2(Fun,A,B)	__lambda_2::use<Fun>::type::apply<A,B>::RET


struct __lambda_3{
    template < template <typename A, typename B, typename C> class Expr >
    struct use {
        struct type{
            template <typename X, typename Y, typename Z >
            struct apply{
                typedef typename Expr<X,Y,Z>::RET RET;
            };
            typedef type RET;
        };
    };
};
#define LAMBDA_3(Name,A,B,C,Expr) 	template <typename A, typename B,typename C>\
										struct Name {\
											typedef Expr RET; \
										};                        
#define APPLY_3(Fun,A,B,C)	__lambda_3::use<Fun>::type::apply<A,B,C>::RET



template <bool> struct static_assert_;
template <> struct static_assert_<true> {}; 
#define  GNS_STATIC_ASSERT(x) static_assert_<(x)>()

}}
#endif