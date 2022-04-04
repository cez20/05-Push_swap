#!/bin/bash
# Color code
RED="\033[1;31m"
GREEN="\033[0;32m"
LIGRAY="\e[37m"
YELLOW="\033[0;33m"

#Test for colors (2 ways of writing this)
# Where there is a '1' before the semi-colon this means that the color is BOLD (1), otherwise not bold (0)
printf "\033[0;33mThis is the test for COLORS with : \033[0;33m2000 1000\033[0m\n"
printf $YELLOW"This is the test for COLORS with : $YELLOW 2000 1000\033[0m\n"
printf ${YELLOW}"This is the test for COLORS with : ${YELLOW}2000 1000\033[0m\n"

#TESTING THE INPUT
make 
#test for 2
printf "\n\n\e[1;94m------TESTING FOR 2 DIGITS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m 2000 1000\033[0m\n"
./push_swap 2000 1000
#test to use defined color

#TESTING FOR PROBLEMS
printf "\n\n\e[1;94m------TESTING FOR PROBLEMS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m1\033[0m\n"
./push_swap 1
printf "\033[1;31mThis is the test with : \033[0;32mnothing\033[0m\n\n"
./push_swap
printf "\033[1;31mThis is the test with : \033[0;32m10 20 30 40 50\033[0m\n"
./push_swap 10 20 30 40 50
printf "\033[1;31mThis is the test with : \033[0;32m'10 20 30 40 50'\033[0m\n"
./push_swap "10 20 30 40 50"
printf "\033[1;31mThis is the test with duplicate: \033[0;32m'10 20 30 40 50 50'\033[0m\n"
./push_swap "10 20 30 40 50 50"
printf "\033[1;31mThis is the test with duplicate in a string: \033[0;32m'10 20 30 40 50 50'\033[0m\n"
./push_swap "10 20 30 40 50 50"
printf "\033[1;31mThis is the test with INT lower than INT_MIN : \033[0;32m-2147483649 20 30 40 50\033[0m\n"
./push_swap -2147483649 20 30 40 50 
printf "\033[1;31mThis is the test with INT lower than INT_MIN in a string : \033[0;32m'-2147483649 20 30 40 50'\033[0m\n"
./push_swap "-2147483649 20 30 40 50"
printf "\033[1;31mThis is the test with INT above INT_MAX : \033[0;32m2147483649 20 30 40 50\033[0m\n"
./push_swap 2147483649 20 30 40 50 
printf "\033[1;31mThis is the test with INT lower INT_MAX in a string : \033[0;32m'2147483649 20 30 40 50'\033[0m\n"
./push_swap "2147483649 20 30 40 50"
printf "\033[1;31mThis is the test with argument other than INT (letter) : \033[0;32m10 20 CESAR 40 50\033[0m\n"
./push_swap 10 20 YO 40 50 
printf "\033[1;31mThis is the test with argument other than INT (letter) in a string : \033[0;32m'10 20 CESAR 40 50'\033[0m\n"
./push_swap "10 20 YO 40 50"
printf "\033[1;31mThis is the test with argument other than INT (letter) in a string : \033[0;32m'10 20 ? 40 50'\033[0m\n"
./push_swap "10 20 ? 40 50"
printf "\033[1;31mThis is the test with argument other than INT (letter) in a string : \033[0;32m'10 20 0 40 50'\033[0m\n"
./push_swap "10 20 0 40 50"
printf "\033[1;31mThis is the test with argument other than INT (letter) in a string : \033[0;32m'10 20 , 40 50'\033[0m\n"
./push_swap "10 20 , 40 50"
printf "\033[1;31mThis is the test with argument other than INT (letter) in a string : \033[0;32m'10 20 / 40 50'\033[0m\n"
./push_swap "10 20 / 40 50"
printf "\033[1;31mThis is the test with argument other than INT (letter) in a string : \033[0;32m'10 20 . 40 50'\033[0m\n"
./push_swap "10 20 . 40 50"



printf "\n\n\e[1;94m------END OF TESTS------\e[0m\n\n"