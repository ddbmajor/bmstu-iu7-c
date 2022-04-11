#ifndef _SITE_H_

#include "defines.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct site site_t;

struct site
{
    char *title;
    char *theme;
    int visitors;
};

site_t *create_site(char *title, char *theme, int visitors);
void delete_site(void *site);
int read_site(site_t **site, FILE *f);
int site_visitors_compare(const void *a, const void *b);
int site_theme_compare(const void *a, const void *b);

#define _SITE_H_
#endif