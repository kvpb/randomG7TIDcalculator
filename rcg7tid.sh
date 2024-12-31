#!/usr/bin/env bash

#function scnclr
#{
#	printf "\033[2J\033[3J\033[1;1H"
#}

function g_G7ID
{
	declare -n a_G7ID=${1}
	declare -a R_TID_=()
	declare -i R_TID=
	declare -a R_SID_=()
	declare -i R_SID=
	declare -i R_IDNo=
	declare -i R_G7TID=
	declare -i R_G7SID=

	R_TID_[0]=$[RANDOM] && 
	R_TID_[1]=$[RANDOM] && 
	readonly R_TID_
	R_TID=$(( R_TID_[0] + R_TID_[1] + $[RANDOM%2] )) && readonly R_TID
	R_SID_[0]=$[RANDOM] && 
	R_SID_[1]=$[RANDOM] && 
	readonly R_SID_
	R_SID=$(( R_SID_[0] + R_SID_[1] + $[RANDOM%2] )) && readonly R_SID
	R_IDNo=$(( ${R_TID} + ( ${R_SID} * 2**16 ) )) && readonly R_IDNo
	R_G7TID=$(( ${R_IDNo} % 10**6 )) && readonly R_G7TID
	R_G7SID=$(( ${R_IDNo} / 10**( 10 - ( 10 - 6 ) ) )) && readonly R_G7SID
	a_G7ID=( ${R_TID} ${R_SID} ${R_IDNo} ${R_G7TID} ${R_G7SID} )

	#printf "%s %s %s %s %s" ${R_TID} ${R_SID} ${R_IDNo} ${R_G7TID} ${R_G7SID}
}

main()
{
	declare -i n
	declare -a a
	declare -i i

	#scnclr
	if [ -z ${1} ]
	then
		n=1
	else
		n=${1}
	fi && readonly n
	i=0
	while [ ${i} -lt ${n} ]
	do
		g_G7ID a
		eval $(declare -p a)
		printf "TID:\t%s\nSID:\t%s\nG7SID:\t%s\nG7TID:\t%s\n" ${a[0]} ${a[1]} ${a[4]} ${a[3]}
		i=$(( ${i} + 1 ))
	done
	#exit 0
}

main ${1}
#unset -f scnclr
unset -f g_G7ID

#	rcg7tid.sh
#	RCG7TID (Random G7TID Calculator)
#
#	Karl V. P. B. `kvpb`	AKA Karl Thomas George West `ktgw`
#	+33 A BB BB BB BB		+1 (DDD) DDD-DDDD
#	local-part@domain
#	https://twitter.com/ktgwkvpb
#	https://github.com/kvpb

#	Copyright 2022 Karl Vincent Pierre Bertin
#
#	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
#
#	1.	Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
#
#	2.	Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
#
#	3.	Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
#
#	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
