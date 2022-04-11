
#ifndef WL
#define WL 16
#endif

#ifndef SL
#define SL 256
#endif

#ifndef N
#define N 128
#endif

void format_word(char str[WL + 1], char newstr[WL + 1]);
int form_word_array(char arr[N][WL + 1]);
int form_string(char str[SL + 1], char arr[N][WL + 1], int n);
