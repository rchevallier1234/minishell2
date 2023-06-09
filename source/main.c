/*
** EPITECH PROJECT, 2023
** simple_execution
** File description:
** main
*/

#include "mysh.h"

void print_info(char **new_argv)
{
    mini_printf("Program name: %s\n", new_argv[0]);
    mini_printf("Nb args: %d\n", my_array_len(new_argv) - 1);
    mini_printf("PID: %d\n", getpid());
}

void handler(int sig)
{
    sig = sig;
    signal(SIGINT, SIG_IGN);
}

char *get_current_directory(void)
{
    int size = 1;
    char *pwd = NULL;

    pwd = malloc(sizeof(char) * size);
    while (getcwd( pwd, size) == NULL) {
        if (errno == ERANGE) {
            size++;
            free(pwd);
            pwd = malloc(sizeof(char) * size);
        }
    }
    return (pwd);
}

void set_system(struct system_s *system, char **env)
{
    system->env = NULL;
    system->env = malloc(sizeof(char *) * (my_array_len(env) + 1));
    for (int i = 0; env[i] != NULL; i++) {
        system->env[i] = NULL;
        system->env[i] = my_strdup(env[i]);
        system->env[i + 1] = NULL;
    }
    system->env = env;
    system->old_pwd = NULL;
    system->pwd = find_value_env(system->env, find_env(system->env, "PWD"));
    if (system->pwd == NULL) {
        system->pwd = get_current_directory();
        system->env = my_setenv(system->env, "PWD", system->pwd);
    }
    if (find_value_env(system->env, find_env(system->env, "PATH")) != NULL) {
        system->path = find_value_env(system->env,
            find_env(system->env, "PATH"));
    }
    system->last_sig = 0;
    return;
}

int main(int argc, char **argv, char **env)
{
    char *line_user = NULL;
    struct system_s system;
    int is_finish = 0;

    set_system(&system, env);
    signal(SIGINT, &handler);
    while (is_finish != 1) {
        line_user = get_command(system.last_sig);
        is_finish = execute_command(line_user, &system);
        free(line_user);
    }
    return (0);
}
