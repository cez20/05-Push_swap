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

#TESTING FOR "NO OUTPUT ON SCREEN"
printf "\n\n\e[1;94m------TESTING FOR NO OUTPUT ON SCREEN------\e[0m\n\n"
printf "\033[1;31mThis is the test with NO INPUT: \033[0;32mnothing\033[0m\n\n"
./push_swap
printf "\033[1;31mThis is the test  with 1 number: \033[0;32m 1 \033[0m\n\n"
./push_swap 1
printf "\033[1;31mThis is the test  with 1 number (string): \033[0;32m '1' \033[0m\n\n"
./push_swap "1"
printf "\033[1;31mThis is the test with 2 numbers in order: \033[0;32m 1 2 \033[0m\n\n"
./push_swap 1 2 
printf "\033[1;31mThis is the test with 2 numbers in order (string) : \033[0;32m'10 20'\033[0m\n\n"
./push_swap "10 20"
printf "\033[1;31mThis is the test with 3 numbers in order: \033[0;32m 1 2 3\033[0m\n\n"
./push_swap 1 2 3
printf "\033[1;31mThis is the test with 3 numbers in order (string) : \033[0;32m'10 20 30'\033[0m\n\n"
./push_swap "10 20 30"
printf "\033[1;31mThis is the test with 4 numbers in order: \033[0;32m 1 2 3 4\033[0m\n\n"
./push_swap 1 2 3 4
printf "\033[1;31mThis is the test with 4 numbers in order (string) : \033[0;32m'10 20 30 40'\033[0m\n\n"
./push_swap "10 20 30 40"
printf "\033[1;31mThis is the test with 5 numbers in order : \033[0;32m 1 2 3 4 5\033[0m\n\n"
./push_swap 1 2 3 4 5
printf "\033[1;31mThis is the test with 5 numbers in order (string) : \033[0;32m'10 20 30 40 50'\033[0m\n\n"
./push_swap "10 20 30 40 50"

# TEST FOR 2 DIGITS
printf "\n\n\e[1;94m------TESTING FOR 2 DIGITS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m 2000 1000\033[0m\n"
./push_swap 2000 1000 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m '2000 1000'\033[0m\n"
./push_swap 2000 1000 | wc -l

# TEST FOR 3 DIGITS
printf "\n\n\e[1;94m------TESTING FOR 3 DIGITS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : ${GREEN} 3 1 2${RESET}"
./push_swap 3 1 2 | wc -l
printf "\033[1;31mThis is the test  with : ${GREEN} 3 2 1${RESET}"
./push_swap 3 2 1 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 2 3 1\033[0m\n"
./push_swap 2 3 1 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 2 1 3\033[0m\n"
./push_swap 2 1 3 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 2 3\033[0m\n"
./push_swap 1 2 3 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 3 2\033[0m\n"
./push_swap 1 3 2 | wc -l

# # TEST FOR 4 DIGITS
printf "\n\n\e[1;94m------TESTING FOR 4 DIGITS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m 1 2 3 4\033[0m\n"
./push_swap 1 2 3 4 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 2 4 3\033[0m\n"
./push_swap 1 2 4 3 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 3 1 2 4\033[0m\n"
./push_swap 3 1 2 4 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 3 4 2\033[0m\n"
./push_swap 1 3 4 2 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 1 4 2 3\033[0m\n"
./push_swap 1 4 2 3 | wc -l

# TEST FOR 5 DIGITS
printf "\n\n\e[1;94m------TESTING FOR 5 DIGITS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m 4 3 2 1 5\033[0m\n"
./push_swap 1 2 3 5 4 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m 5 4 2 3 1\033[0m\n"
./push_swap 5 4 2 3 1 | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m \"5 4 2 3 1\"\033[0m\n"
./push_swap "5 4 2 3 1" | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 5 numbers\033[0m\n"
ARG=`ruby -e "puts (10..14).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 5 numbers\033[0m\n"
ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 5 numbers\033[0m\n"
ARG=`ruby -e "puts (5..9).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l

# # TEST BETWEEN 12 AND 50 DIGITS
printf "\n\n\e[1;94m------TESTING BETWEEN 12 and 50 DIGITS------\e[0m\n\n"
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
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 25 numbers \033[0m\n"
ARG=`ruby -e "puts (10..34).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 50 numbers \033[0m\n"
ARG=`ruby -e "puts (10..59).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l

#TESTING FOR 100 DIGITS
printf "\n\n\e[1;94m------TESTING FOR 100 DIGITS------\e[0m\n\n"
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

#TESTING FOR 500 DIGITS
printf "\n\n\e[1;94m------TESTING FOR 500 DIGITS------\e[0m\n\n"
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

#TESTING FOR CHECKER_MAC
printf "\n\n\e[1;94m------TESTING FOR CHECKER MAC------\e[0m\n\n"
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 3 numbers \033[0m\n"
ARG=`ruby -e "puts (0..2).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 3 numbers \033[0m\n"
ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 5 numbers \033[0m\n"
ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 5 numbers \033[0m\n"
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_Mac $ARG



#TESTING FOR PROBLEMS
printf "\n\n\e[1;94m------TESTING FOR PROBLEMS------\e[0m\n\n"
printf "\033[1;31mThis is the test with duplicates: \033[0;32m10 20 30 40 50 50\033[0m\n"
./push_swap 10 20 30 40 50 50
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
printf "\033[1;31mThis is the test with symbol ',' in a string : \033[0;32m'10 20 , 40 50'\033[0m\n"
./push_swap "10 20 , 40 50"
printf "\033[1;31mThis is the test with symbol '/' in a string : \033[0;32m'10 20 / 40 50'\033[0m\n"
./push_swap "10 20 / 40 50"
printf "\033[1;31mThis is the test with symbol '.' in a string : \033[0;32m'10 20 . 40 50'\033[0m\n"
./push_swap "10 20 . 40 50"

#TESTING FOR MEMORY LEAKS
printf "\n\n\e[1;94m------TESTING FOR MEMORY LEAKS------\e[0m\n\n"
printf "\033[1;31mThis is the test  with :\033[0;32m 1  \033[0m\n"
leaks -atExit -- ./push_swap 1 | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with :\033[0;32m '1' \033[0m\n"
leaks -atExit -- ./push_swap "1" | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with :\033[0;32m 1 2 \033[0m\n"
leaks -atExit -- ./push_swap 1 2 | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with : \033[0;32m '1 2' in order \033[0m\n"
leaks -atExit -- ./push_swap "1 2" | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with \033[0;32m '2 1'\033[0m\n"
leaks -atExit -- ./push_swap "2 1" | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with \033[0;32m 1 2 3\033[0m\n"
leaks -atExit -- ./push_swap 1 2 3 | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with : \033[0;32m '1 2 3' \033[0m\n"
leaks -atExit -- ./push_swap "1 2 3" | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with : \033[0;32m '3 1 2' \033[0m\n"
leaks -atExit -- ./push_swap "3 1 2" | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with : \033[0;32m -14 38 1 156 49 \033[0m\n"
leaks -atExit -- ./push_swap -14 38 1 156 49 | grep 'leaked bytes'
printf "\033[1;31mThis is the test  with : \033[0;32m '-14 38 1 156 49' \033[0m\n"
leaks -atExit -- ./push_swap "-14 38 1 156 49" | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with : \033[0;32m 'RANDOMIZER with 5 numbers' \033[0m\n"
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; leaks -atExit -- ./push_swap $ARG | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with : \033[0;32m 1 14 10 5 3 18 2 19 12 11 9 15 13 20 7 6 17 16 4 8 \033[0m\n"
leaks -atExit -- ./push_swap 1 14 10 5 3 18 2 19 12 11 9 15 13 20 7 6 17 16 4 8 | grep 'leaked bytes'
printf "\033[1;31mThis is the test  with : \033[0;32m '1 14 10 5 3 18 2 19 12 11 9 15 13 20 7 6 17 16 4 8' \033[0m\n"
leaks -atExit -- ./push_swap "1 14 10 5 3 18 2 19 12 11 9 15 13 20 7 6 17 16 4 8" | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 20 numbers \033[0m\n"
ARG=`ruby -e "puts (1..20).to_a.shuffle.join(' ')"`; leaks -atExit -- ./push_swap $ARG | grep 'leaked bytes' 
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 100 numbers \033[0m\n"
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; leaks -atExit -- ./push_swap $ARG | grep 'leaked bytes'
printf "\033[1;31mThis is the test  with : \033[0;32m RANDOMIZER with 500 numbers \033[0m\n"
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; leaks -atExit -- ./push_swap $ARG | grep 'leaked bytes'


printf "\n\n\e[1;94m------END OF TESTS------\e[0m\n\n"