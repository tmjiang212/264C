"#264C" 
All C code has been targeted to compile using GCC and the C89 language standard.

//alias gcc='gcc -g -Wall -Wshadow --std=c99 --pedantic'
//gcc -Wall -Wshadow -g input.c -o output

To test, create test cases in C, output in txt, then use the following command to compile & compare:
gcc -o hw02test hw02test.c hw02.c && ./hw02test | diff hw02test.txt -

Pro tips (optional)
bash, && – You can do this with a bash one-liner. To join commands, use the && operator in bash. With &&, the second command runs only if the first succeeded (i.e., no compiler warnings or errors). You can also send the output of your hw02test directly to diff using the pipe operator (|). Putting it all together, you get this:
gcc -o hw02test hw02test.c hw02.c && ./hw02test | diff hw02test.txt -
To repeat, use your up arrow key (in bash)
bash, alias – To avoid typing all of that, you can create an alias in bash. (This is one command, i.e., one line.)
alias testhw2='gcc -o hw02test hw02test.c hw02.c && ./hw02test | diff hw02test.txt -'
After that, you can simply type testhw2 in bash. To make it work in future sessions, add it to your .bashrc toward the end, after the other gcc alias that adds in other compilation flags.
vim, mappings – To do all of this from vim, you can map it to a key, such as F5. (Enter all of that as a single command in Vim.)
:nmap <F5> :!gcc hw02.c hw02test.c --std=c99 --pedantic -g -Wall -Wshadow -o hw02test && ./hw02test | diff - hw02test.txt<CR>




For more information, refer to https://engineering.purdue.edu/ece264/15au/ and Prof Yong-Hsiang Lu from Purdue University
