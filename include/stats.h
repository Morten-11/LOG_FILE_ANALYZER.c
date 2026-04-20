#ifndef STATS_H
#define STATS_H

#include "log.h"

typedef struct {
    char level[10];
    int count;
} LevelCount;

LevelCount* count_levels(const LogEntry* Logs, int log_count);

void write_stats(const LevelCount* levels, int count);

#endif