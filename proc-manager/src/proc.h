#ifndef PROC_H
#define PROC_H

void list_processes();
void search_process(const char *name);
int kill_process(int pid);

#endif