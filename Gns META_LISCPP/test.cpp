/** 
	* Copyright (C) 2014 Ganesh Prasad Sahoo - All Rights Reserved
	* You may use, distribute and modify this code under the
	* terms of the GNU GPL V3 license. 
	*
	* You should have received a copy of the GNU GPL V3 license with
	* this file. If not, please write to: sir.gnsp@gmail.com , or visit : http://www.gnu.org/licenses/gpl.txt
*/

#include "meta_liscpp.hpp"
#include <iostream>
using namespace gns::meta_liscpp;

LAMBDA_2(Add,A,B,PLUS(A,B));

int main(){
	VAR(int, A, 5);
	VAR(int, B, 10);
	VAR(int, C, 15);
	
	SETQ(L,LIST_3(A,B,C));

	SETQ(M,PLUS_OP(A,A));
	SETQ(N,MINUS_OP(PLUS_OP(A,B)));
	SETQ(Q,COND_OP(ZEROP_OP(A),DIFFERENCE_OP(A,B),A));
	SETQ(P,APPLY_2(Add,A,B));
	SETQ(R,CAR_OP(CDR_OP(L)));
	
	std::cout<<" SHOULD BE 10  ===> "<<(EVAL(M))<<std::endl;
	std::cout<<" SHOULD BE -15  ===> "<<(EVAL(N))<<std::endl;
	std::cout<<" SHOULD BE 5  ===> "<<(EVAL(Q))<<std::endl;
	std::cout<<" SHOULD BE 15  ===> "<<(EVAL(P))<<std::endl;
	std::cout<<" SHOULD BE 10  ===> "<<(EVAL(R))<<std::endl;
	return 0;
}

/**
	ALL TESTS PASSED...
	
	YET MORE TESTS TO BE WRITTEN , VERIFIED AND DEBUGGED ...
*/