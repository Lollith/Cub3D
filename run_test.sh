#!/bin/bash

SEP_P="#########################"
SEP_SP="------------------------"

BK_RD='\033[31;7m'
BK_GN='\033[32;7m'
BK_YE='\033[33;7m'
RD='\033[0;31m'
GN='\033[0;32m'
YE='\033[0;33m'
BU='\033[0;34m'
MG='\033[0;35m'
NC='\033[0m'

PROGNAME="cub3D"
ORI_P=$(pwd)
FILE_P=${ORI_P}/maps
RES_P=${ORI_P}/result

TEST_MANUAL=("file_does_not_exist" "map_subject.cub            ")

function	run_manual()
{
	local	res_file="result_manual.txt";

	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	for i in ${TEST_MANUAL[@]}
	do
		echo -e "${BU}Progress on : ${2}/${i}${NC}" | tee -a ${3}/${res_file};
		if ./${1} ${2}/${i} >> ${3}/${res_file} 2>&1; [ $? != 0 ]
		then
			echo -e "${RD}Program failed${NC}" | tee -a ${3}/${res_file};
		else
			echo -e "${GN}Program successed${NC}" | tee -a ${3}/${res_file};
		fi;
		echo -e "${BU}${SEP_SP}${NC}" | tee -a ${3}/${res_file};
	done
	echo -e "${YE}${SEP_P}${NC}";
	return 0
}

function	run_maps()
{
	local	res_file="${4}_result_maps.txt";
	local	n_test=0;
	local	res_ok=0;
	local	res_ko=0;

	echo -e "${YE}Executing \"${FUNCNAME} - ${4}\"${NC}";
	for i in ${2}/${4}*
	do
		echo -e "${BU}Progress on : ${i}${NC}" | tee -a ${3}/${res_file};
		((n_test++));
		if ./${1} ${i} >> ${3}/${res_file} 2>&1; [ $? != 0 ]
		then
			echo -e "${RD}Program failed${NC}" | tee -a ${3}/${res_file};
			((res_ko++))
			if [ "${4}" == "ko" ]
			then
				echo -e "${BK_GN}RESULT: Corrrect${NC}" | tee -a ${3}/${res_file};
			else
				echo -e "${BK_RD}RESULT: Wrong${NC}" | tee -a ${3}/${res_file};
			fi
		else
			echo -e "${GN}Program successed${NC}" | tee -a ${3}/${res_file};
			((res_ok++))
			if [ "${4}" == "ko" ]
			then
				echo -e "${BK_RD}RESULT: Wrong${NC}" | tee -a ${3}/${res_file};
			else
				echo -e "${BK_GN}RESULT: Correct${NC}" | tee -a ${3}/${res_file};
			fi
		fi;
		echo -e "${BU}${SEP_SP}${NC}" | tee -a ${3}/${res_file};
	done
	echo -e "${BK_GN}Total of ok: ${res_ok}/${n_test}${NC}" | tee -a ${3}/${res_file};
	echo -e "${BK_RD}Total of ko: ${res_ko}/${n_test}${NC}" | tee -a ${3}/${res_file};
	echo -e "${YE}${SEP_P}${NC}";
	return 0
}

function	create_dir_res
{
	local usr_answer=""

	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	while [ "${usr_answer}" != "y" ] && [ "${usr_answer}" != "n" ]
	do
		read -n 1 -p "The process will delete the directory. Do you want to continue [y/n] ? " usr_answer;
		echo "";
		echo "Answer: ${usr_answer}";
	done
	if [ "${usr_answer}" == "y" ]
	then
		rm -rf ${2} && echo -e "${BU}Directory \"${2}\" has been deleted from the current directory \"${1}\"${NC}" || echo -e "${RD}Error: impossible to delete the directory \"${2}\" from the current directory \"${1}\"${NC}";
		if [ "$?" != 0 ]; then return 2; fi;
	else
		echo -e "${BU}The process has been stopped${NC}";
		return 3;
	fi
	mkdir ${2} && echo -e "${GN}Directory \"${2}\" has been created in the current directory \"${1}\"${NC}" || echo -e "${RD}Error: impossible to create the directory \"${2}\" in the current directory \"${1}\"${NC}";
	if [ "$?" != 0 ]; then return 3; fi;
	echo -e "${YE}${SEP_P}${NC}";
}

function	checkfiles()
{
	echo -e "${YE}Executing \"${FUNCNAME}\"${NC}";
	if [ ! -e ${1} ]
	then
		echo -e "${RD}path does not exist: ${1}${NC}";
		return 1;
	else
		echo -e "${GN}path does exist: ${1}${NC}";
	fi;
	echo -e "${YE}${SEP_P}${NC}";
	return 0;
}

function	main()
{
	if make; [ $? != 0 ]; then return 1; fi;
	if checkfiles ${FILE_P}; [ $? != 0 ]; then return 1; fi;
	if create_dir_res ${ORI_P} ${RES_P}; [ $? != 0 ]; then return 1; fi;
	run_maps ${PROGNAME} ${FILE_P} ${RES_P} "ko";
	run_maps ${PROGNAME} ${FILE_P} ${RES_P} "ok";
	run_manual ${PROGNAME} ${FILE_P} ${RES_P};
	return 0
}

### PROGRAM START ###
clear && echo "Terminal cleared"
echo -e "${YE}Program start${NC}"
main
echo -e "${YE}Program end${NC}"
exit 0
### PROGRAM END ###
