#ifndef N
#define N 128
#endif

#ifndef WL
#define WL 16
#endif

int read_line(char *str, int n);
int read_line_by_words(char *str, char arr[N][WL + 1]);
int is_there_word(char str[WL + 1], char arr[N][WL + 1], int n);
int unique_words(char a_1[N][WL + 1], int n1, char a_2[N][WL + 1], int n2, char res[N][WL + 1]);