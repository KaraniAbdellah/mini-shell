#ifndef BUILT
#define BUILT


#include "../../reading/read_tokenize.h"





    void built_in_cmd(list *head);
    void exit_cmd();
    char *get_after_command(list *head);
    int cd_cmd(list *head);
    void help_cmd(list *head);
    int nbr_slash(char *cwd);
    void set_env(list *head);
    void unset_env(list *head);













#endif



