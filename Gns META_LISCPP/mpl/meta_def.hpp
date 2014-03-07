/** 
	* Copyright (C) 2014 Ganesh Prasad Sahoo - All Rights Reserved
	* You may use, distribute and modify this code under the
	* terms of the GNU GPL V3 license. 
	*
	* You should have received a copy of the GNU GPL V3 license with
	* this file. If not, please write to: sir.gnsp@gmail.com , or visit : http://www.gnu.org/licenses/gpl.txt
*/


#ifndef _GNS_META_DEF_V1
#define _GNS_META_DEF_V1

#define ALLOW_NEW_NUMERIC_TYPES__
#define ALLOW_NEW_INTEGER_TYPES__

struct emptyType{};   // just a marker class, no real usage except for typelists
class nullType{};		// a valid type to be inherited from. Objects of empty type can be declared

struct TRUE { static const bool RET= true; };	// marker type for boolean RETtrue
struct NIL{ static const bool RET= false; };	// marker type for boolean RETfalse

#endif