#ifndef STATS_H
#define STATS_H

#include "log.h"
#include <stdbool.h>

typedef struct {
    char level[10];
    int count;
} LevelCount;

typedef struct {
    LevelCount* levels;
    int count;
    char most_common[10];
    int max_count;
    bool error;
} LevelStats;

LevelStats count_levels(const LogEntry* Logs, int log_count);

void write_stats(const LevelCount* levels, int count);

#endif