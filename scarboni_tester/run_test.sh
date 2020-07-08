make && ./scarboni_tester > test
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c test.c -o check_tests
./check_tests
