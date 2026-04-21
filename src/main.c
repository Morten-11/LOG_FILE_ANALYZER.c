#include "log.h"
#include "stats.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    puts("Welcome to the Log Analyzer! To start, please enter the filename of the logfile that you want to analyze:");
    char filename[256];
    int count = 0;

    scanf("%255s", filename);
    
    LogEntry* all_entries = load_logs(filename, &count);
    if (all_entries == NULL) {
        printf("Failed to load log file.\n");
        return 1;
    }
    
    LevelStats Stats = count_levels(all_entries, count);
    if (Stats.error) {
        printf("Error analyzing logs.\n");
        free_logs(all_entries);
        return 1;
    }
    
    write_stats(Stats);

    free_logs(all_entries);
    free(Stats.levels);

    puts("Log file analyzed successfully. Check your output folder for the result.");
    
    return 0;
}