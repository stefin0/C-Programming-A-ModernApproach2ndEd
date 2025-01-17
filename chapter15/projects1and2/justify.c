/*
1. The justify program of Section 15.3 justifies lines by inserting extra
spaces between words. The way the write_line function currently works, the
words closer to the end of a line tend to have slightly wider gaps between them
than the words at the beginning. (For example, the words closer to the end
might have three spaces between them, while the words closer to the beginning
might be separated by only two spaces.) Improve the program by having writeline
alternate between putting the larger gaps at the end of the line and putting
them at the beginning of the line.
*/
/* Formats a file of text */
#include "line.h"
#include "word.h"
#include <string.h>
#define MAX_WORD_LEN 20
int main(void)
{
    char word[MAX_WORD_LEN + 2];
    int word_len;
    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN + 1);
        word_len = strlen(word);
        if (word_len == 0) {
            flush_line();
            return 0;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
    }
}
