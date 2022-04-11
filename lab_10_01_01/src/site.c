#include "site.h"


site_t *create_site(char *title, char *theme, int visitors)
{
    site_t *site = malloc(sizeof(site_t));
    if (site == NULL)
        return NULL;
    site->title = title;
    site->theme = theme;
    site->visitors = visitors;

    return site;
}


void delete_site(void *site)
{
    site_t *a = site;
    free(a->title);
    free(a->theme);
    free(a);
}


int read_site(site_t **site, FILE *f)
{
    char *line1 = NULL;
    char *line2 = NULL;
    size_t len1 = 0;
    size_t len2 = 0;
    ssize_t read1, read2;

    int num;
    int rc;
    int flag = 0;

    read1 = getline(&line1, &len1, f);
    if (read1 == -1)
    {
        free(line1);
        if (feof(f))
            return -1;
        else
            return INPUT_ERROR;
    }
    
    for (int i = 0; line1[i] != '\0'; i++)
    {
        if (!isspace(line1[i]))
            flag = 1;
        if (line1[i] == '\n' || line1[i] == '\r')
            line1[i] = '\0';
    }
    if (flag == 0)
    {
        free(line1);
        return INPUT_ERROR;
    }

    read2 = getline(&line2, &len2, f);
    if (read2 == -1)
    {
        free(line1);
        free(line2);
        return INPUT_ERROR;
    }
    flag = 0;
    for (int i = 0; line2[i] != '\0'; i++)
    {
        if (!isspace(line2[i]))
            flag = 1;
        if (line2[i] == '\n' || line2[i] == '\r')
            line2[i] = '\0';
    }
    if (flag == 0)
    {
        free(line1);
        free(line2);
        return INPUT_ERROR;
    }

    rc = fscanf(f, "%d", &num);
    if (rc != 1 || num < 0)
    {
        free(line1);
        free(line2);
        return INPUT_ERROR;
    }
    fscanf(f, "%d", &num);

    site_t *s = create_site(line1, line2, num);
    if (s == NULL)
        return ALLOC_ERROR;
    *site = s;

    return 0;
}


int site_visitors_compare(const void *a, const void *b)
{
    const site_t *first = a;
    const site_t *second = b;
    if (first->visitors == second->visitors)
        return 0;
    else if (first->visitors < second->visitors)
        return -1;
    else
        return 1;

    return 0;
}


int site_theme_compare(const void *a, const void *b)
{
    const site_t *first = a;
    const site_t *second = b;

    return strcmp(first->theme, second->theme);
}
