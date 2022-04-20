#!/bin/bash
# Color code
# Where there is a '1' before the semi-colon this means that the color is BOLD (1), otherwise not bold (0)
RED="\033[1;31m"
GREEN="\033[0;32m"
LIGRAY="\e[37m"
YELLOW="\033[0;33m"
RESET="\033[0m\n"

# TEST FOR COLORS 
printf "\n\n\e[1;94m------TESTING FOR COLORS------\e[0m\n\n"
printf "\n\033[0;33mThis text is in YELLOW: \033[0;33m2000 1000\033[0m\n"
printf ${YELLOW}"This text is in YELLOW: ${YELLOW}2000 1000"${RESET}

# COMPILING THE PROGRAM
printf "\n\n\e[1;94m------COMPILING THE PROGRAM-----\e[0m\n\n"
make 

printf "\n\n\e[1;94m------COMPILING THE PROGRAM-----\e[0m\n\n"


# TEST FOR 2 NUMBERS
printf "\n\n\e[1;94m------TESTING FOR 2 DIGITS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m 2000 1000\033[0m\n"
./push_swap 2000 1000 | wc -l

# TEST FOR 3 NUMBERS 
printf "\n\n\e[1;94m------TESTING FOR 3 DIGITS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : ${GREEN} 3 1 2${RESET}"
./push_swap 3 1 2 | wc -l
printf "\033[1;31mThis is the test  with : ${GREEN} 3 1 2${RESET}"
./push_swap 3 2 1 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 2 3 1\033[0m\n"
./push_swap 2 3 1 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 2 1 3\033[0m\n"
./push_swap 2 1 3 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 2 3\033[0m\n"
./push_swap 1 2 3 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 3 2\033[0m\n"
./push_swap 1 3 2 | wc -l

# # TEST FOR 4
printf "\n\n\e[1;94m------TESTING FOR 4 DIGITS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m 1 2 3 4\033[0m\n"
./push_swap 1 2 3 4 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 2 4 3\033[0m\n"
./push_swap 1 2 4 3 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 3 2 4\033[0m\n"
./push_swap 1 3 2 4 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 3 4 2\033[0m\n"
./push_swap 1 3 4 2 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 4 2 3\033[0m\n"
./push_swap 1 4 2 3 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 4 3 2\033[0m\n"
./push_swap 1 4 3 2 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 2 1 3 4\033[0m\n"
./push_swap 2 1 3 4 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 2 1 4 3\033[0m\n"
./push_swap 2 1 4 3 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 2 3 1 4\033[0m\n"
./push_swap 2 3 1 4 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 2 3 4 1\033[0m\n"
./push_swap 2 3 4 1 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 2 4 1 3\033[0m\n"
./push_swap 2 4 1 3 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 2 4 3 1\033[0m\n"
./push_swap 2 4 3 1 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 3 1 2 4\033[0m\n"
./push_swap 3 1 2 4 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 3 1 4 2\033[0m\n"
./push_swap 3 1 4 2 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 3 2 1 4\033[0m\n"
./push_swap 3 2 1 4 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 3 2 4 1\033[0m\n"
./push_swap 3 2 4 1 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 3 4 1 2\033[0m\n"
./push_swap 3 4 1 2 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 3 4 2 1\033[0m\n"
./push_swap 3 4 2 1 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 4 1 2 3\033[0m\n"
./push_swap 4 1 2 3 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 4 1 3 2\033[0m\n"
./push_swap 4 1 3 2 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 4 2 1 3\033[0m\n"
./push_swap 4 2 1 3 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 4 2 3 1\033[0m\n"
./push_swap 4 2 3 1 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 4 3 1 2\033[0m\n"
./push_swap 4 3 1 2 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 4 3 2 1\033[0m\n"
./push_swap 4 3 2 1 | wc -l

# TEST FOR 5
printf "\n\n\e[1;94m------TESTING FOR 5 DIGITS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m 4 3 2 1 5\033[0m\n"
./push_swap 1 2 3 5 4 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 5 4 2 3 1\033[0m\n"
./push_swap 5 4 2 3 1 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m \"5 4 2 3 1\"\033[0m\n"
./push_swap "5 4 2 3 1" | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER \033[0m\n"
ARG=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER \033[0m\n"
ARG=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER \033[0m\n"
ARG=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l

# # TEST FOR 12 digits and more
printf "\n\n\e[1;94m------TESTING FOR 12 and + DIGITS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m 2 3 5 12 10 6 9 7 4 1 8 11\033[0m\n"
./push_swap 2 3 5 12 10 6 9 7 4 1 8 11 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 11 1 2 12 3 7 4 6 10 9 8 5\033[0m\n"
./push_swap 11 1 2 12 3 7 4 6 10 9 8 5 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 9 5 4 10 8 6 2 7 1 3 11 12\033[0m\n"
./push_swap 9 5 4 10 8 6 2 7 1 3 11 12 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 12 numbers \033[0m\n"
ARG=`ruby -e "puts (10..21).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 12 numbers \033[0m\n"
ARG=`ruby -e "puts (10..21).to_a.shuffle.join(' ')"`; ./push_swap $ARG  | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 12 numbers \033[0m\n"
ARG=`ruby -e "puts (10..21).to_a.shuffle.join(' ')"`; ./push_swap $ARG  | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 12 numbers \033[0m\n"
ARG=`ruby -e "puts (10..21).to_a.shuffle.join(' ')"`; ./push_swap $ARG  | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 12 numbers \033[0m\n"
ARG=`ruby -e "puts (10..21).to_a.shuffle.join(' ')"`; ./push_swap $ARG  | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 12 numbers \033[0m\n"
ARG=`ruby -e "puts (10..21).to_a.shuffle.join(' ')"`; ./push_swap $ARG  | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 12 numbers \033[0m\n"
ARG=`ruby -e "puts (10..21).to_a.shuffle.join(' ')"`; ./push_swap $ARG  | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 12 numbers \033[0m\n"
ARG=`ruby -e "puts (10..21).to_a.shuffle.join(' ')"`; ./push_swap $ARG  | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 12 numbers \033[0m\n"
ARG=`ruby -e "puts (10..21).to_a.shuffle.join(' ')"`; ./push_swap $ARG  | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 12 numbers \033[0m\n"
ARG=`ruby -e "puts (10..21).to_a.shuffle.join(' ')"`; ./push_swap $ARG  | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 25 numbers \033[0m\n"
ARG=`ruby -e "puts (10..34).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 50 numbers \033[0m\n"
ARG=`ruby -e "puts (10..59).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (10..109).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l


#TESTING FOR PROBLEMS
printf "\n\n\e[1;94m------TESTING FOR PROBLEMS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m1\033[0m\n"
./push_swap 1
printf "\033[1;31mThis is the test with : \033[0;32mnothing\033[0m\n\n"
./push_swap
printf "\033[1;31mThis is the test with numbers already in order : \033[0;32m10 20 30 40 50\033[0m\n"
./push_swap 10 20 30 40 50
printf "\033[1;31mThis is the test with number already in order (string) : \033[0;32m'10 20 30 40 50'\033[0m\n"
./push_swap "10 20 30 40 50"
printf "\033[1;31mThis is the test with duplicate in a string: \033[0;32m'10 20 30 40 50 50'\033[0m\n"
./push_swap "10 20 30 40 50 50"
printf "\033[1;31mThis is the test with duplicates: \033[0;32m10 20 30 40 50 50\033[0m\n"
./push_swap 10 20 30 40 50 50
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
printf "\033[1;31mThis is the test with symbol ',' in a string : \033[0;32m'10 20 , 40 50'\033[0m\n"
./push_swap "10 20 , 40 50"
printf "\033[1;31mThis is the test with symbol '/' in a string : \033[0;32m'10 20 / 40 50'\033[0m\n"
./push_swap "10 20 / 40 50"
printf "\033[1;31mThis is the test with symbol '.' in a string : \033[0;32m'10 20 . 40 50'\033[0m\n"
./push_swap "10 20 . 40 50"


printf "\n\n\e[1;94m------VALIDATING IF ANY MEMORY LEAKS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 10 numbers \033[0m\n"
ARG=`ruby -e "puts (1..10).to_a.shuffle.join(' ')"`; leaks -atExit -- ./push_swap $ARG 
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 10 numbers \033[0m\n"
ARG=`ruby -e "puts (1..10).to_a.shuffle.join(' ')"`; leaks -atExit -- ./push_swap $ARG 
printf "\033[1;31mThis is the test  with \033[0;32m: 1 2\033[0m\n"
leaks -atExit -- ./push_swap 1 2
printf "\033[1;31mThis is the test  with \033[0;32m:1 2 3\033[0m\n"
leaks -atExit -- ./push_swap 1 2 3

printf "\n\n\e[1;94m------END OF TESTS------\e[0m\n\n"