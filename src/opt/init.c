#include "opt.h"
#include "ft_ls.h"

t_opt   *init(void) {
    t_opt   *options;

    if (options = malloc(sizeof(t_opt)))
        return (NULL);
    options->tab = {0};
    ft_strcpy(options->valid_ids, VALID_OPT, ft_strlen(VALID_OPT));
    options->id = {0};
    return (options);
}

