/*//	Copyright 2022 Karl Vincent Pierre Bertin
////
////	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
////
////	1.	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
////
////	2.	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
////
////	3.	Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
////
*///	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "../include/header.hpp"

int /*w*/main( /*int count_argument, wchar_t* vector_argument[]*/ )
{
	/*if ( count_argument != 1 )
		exit( 1 );*/

	uint16_t maximum_16bitunsigned; // 16-bit unsigned maximum value: 2**16 - 1 == 65535
	uint16_t integer_TID;           // generation I trainer ID number (TID): 0 <= i_TID <= 2**16 - 1, ( 2**32 - ( 65535 * 2**16 ) ) - 1 == max_TID
	uint16_t integer_SID;           // generation III secret ID number (SID): 0 <= i_SID <= 2**16 - 1, ( 2**32 - ( 65535 * 2**16 ) ) - 1 == max_SID
	uint16_t result;                // i_TID ^ i_SID
	uint16_t integer_TSV;           // trainer shiny value (TSV): 0 <= i_TSV <= ( min( 0x0, 0xFFFF ) ^ max( 0x0, 0xFFFF ) ) >> 4 == 4095, i_TSV = ( i_TID ^ i_SID ) >> 4
	uint8_t integer_TRV;            // trainer residual value (TRV): 0 <= i_TRV <= ( min( 0x0, 0xFFFF ) ^ max( 0x0, 0xFFFF ) ) & 0xF == 15, i_TRV = ( i_TID ^ i_SID ) & 0xF
	uint32_t integer_IDNo;          // generation VII ID number (G7ID, 'IDNo'): 0 <= i_IDNo <= 2**32 - 1 == 4294967295, i_G7ID = i_TID + ( 2**16 * i_SID )
	int32_t million;                // 'mask': 10**6 == 1000000
	int32_t integer_G7TID;          // generation VII trainer ID number (G7TID): 0 <= i_G7TID <= 999999, i_G7TID = i_G7ID % 10**6
	int8_t radix;                   // positional numeral system: decimal system ( radix = 10 )
	uint32_t maximum_32bitunsigned; // 32-bit unsigned maximum value: 2**32 - 1 == 4294967295
	uint8_t length_maximum;         // 32-bit unsigned maximum value length: for r = 10, l_max = floor( r - log_r( i_max ) + 1 ) == 10
	uint8_t length_G7TID;           // G7TID length: l_G7TID = 6 == l_max - l_G7SID
	uint8_t length_G7SID;           // G7SID length: l_G7SID = l_max - l_G7TID == 4
	int16_t integer_G7SID;          // generation VII secret ID number (G7SID): 0 <= i_G7SID <= 4294, i_G7SID = floor( n / 10**( l_max - 6 ) )

	srand( time( NULL ) );
	maximum_16bitunsigned = (uint16_t) ( pow( 2, 16 ) - 1 );
	integer_SID = (uint16_t) ( rand() % maximum_16bitunsigned );
	integer_TID = (uint16_t) ( rand() % maximum_16bitunsigned );
	result = integer_TID ^ integer_SID;
	integer_TSV = (uint16_t) ( ( result ) >> 4 );
	integer_TRV = (uint8_t) ( ( result ) & 0xF );
	million = (int32_t) pow( 10, 6 );
	maximum_32bitunsigned = (uint32_t) ( pow( 2, 32 ) - 1 );
	radix = (int8_t) 10;
	length_G7TID = (uint8_t) 6;
	length_maximum = nbrlen( maximum_32bitunsigned, radix );
	length_G7SID = (uint8_t) length_maximum - length_G7TID;
	integer_IDNo = (uint32_t) ( integer_TID + ( ( maximum_16bitunsigned + 1 ) * integer_SID ) );
	integer_G7TID = (int32_t) ( integer_IDNo % million );
	integer_G7SID = (int16_t) ( floor( (double) integer_IDNo / pow( 10, ( length_maximum - length_G7SID ) ) ) );
	std::cout << "TID:\t" << integer_TID << "\nSID:\t" << integer_SID << "\nTSV:\t" << integer_TSV << "\nTRV:\t" << +integer_TRV /* Because that variable is data of primitive type, I gotta prefix it with this unary operator, or else as the uint8_t type is the unsigned char one, it will interpret its data as an ASCII character instead of a printable numerical value. */ << "\nG7SID:\t" << integer_G7SID << "\nG7TID:\t" << integer_G7TID << std::endl;

	return 0;
}

/*//	main.cpp
////	Random G7TID Calculator
////
////	Karl V. P. B. `kvpb` AKA Karl Thomas George West `ktgw`
////	+1 (DDD) DDD-DDDD
////	+33 A BB BB BB BB
////	local-part@domain
////	local-part@domain
////	https://www.linkedin.com/in//
////	https://twitter.com/ktgwkvpb
////	https://github.com/kvpb
*///	https://vm.tiktok.com/ZSwAmcFh/
