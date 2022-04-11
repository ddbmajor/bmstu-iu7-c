#ifndef SL
#define SL 256
#endif

#ifndef MARKS
#define MARKS ".,!?;"
#endif

void space_remover(char str[SL + 1]);
void begin_mark_remover(char str[SL + 1]);
void mark_space_remover(char str[SL + 1]);
void mark_space_adder(char str[SL + 1]);
void mark_remover(char str[SL + 1]);
void upper(char str[SL + 1]);
void dotter(char str[SL + 1]);
int latinchecker(char str[SL + 1]);
int format_text(char str[SL + 1]);