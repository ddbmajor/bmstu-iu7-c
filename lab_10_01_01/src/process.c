#include "process.h"


int read_file(node_t **head, FILE *f)
{
    int rc;
    site_t *site;

    rc = read_site(&site, f);
    if (rc != 0)
    {
        return rc;
    }
    node_t *list = create_node((void *)site);
    if (list == NULL)
        return ALLOC_ERROR;

    while (rc == 0)
    {
        rc = read_site(&site, f);
        if (rc > 0)
        {
            delete_list(list, delete_site);
            return INPUT_ERROR;
        }
        else if (rc < 0)
        {
            break;
        }
        node_t *node = create_node((void *)site);
        if (node == NULL)
            return ALLOC_ERROR;
        list = list_append(list, node);
    }

    *head = list;
    return 0;
}


int write_file(FILE *f, node_t **head)
{
    node_t *themes = NULL;
    site_t *site = NULL;

    int flag = 0;

    while ((site = pop_back(head)))
    {
        flag = 1;
        if (!find(themes, site, site_theme_compare))
        {
            node_t *node = create_node((void *)site);
            if (node == NULL)
                return ALLOC_ERROR;
            themes = list_append(themes, node);
        }
        else
        {
            delete_site(site);
        }
    }
    if (flag == 0)
        return EMPTY_FILE_ERROR;

    themes = reverse(themes);

    node_t *curr = themes;
    for (; curr; curr = curr->next)
    {
        fprintf(f, "%s\n", ((site_t *)(curr->data))->title);
        fprintf(f, "%s\n", ((site_t *)(curr->data))->theme);
        fprintf(f, "%d\n", ((site_t *)(curr->data))->visitors);
    }

    delete_list(themes, delete_site);
    return 0;
}


int process(FILE *infile, FILE *outfile)
{
    if (infile == NULL || outfile == NULL)
        return FILE_ERROR;

    node_t *sites = NULL;
    int rc;
    rc = read_file(&sites, infile);
    if (rc != 0)
    {
        return rc;
    }

    sites = sort(sites, site_visitors_compare);

    rc = write_file(outfile, &sites);
    if (rc != 0)
    {
        delete_list(sites, delete_site);
        return rc;
    }
    delete_list(sites, delete_site);

    return 0;
}