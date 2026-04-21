#include "stats.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

LevelStats count_levels(const LogEntry* Logs, int log_count){
    int size_of_array = 0;
    

    LevelCount* array_levels = NULL;
    LevelStats Stats = {0}; 

    for (int i = 0; i < log_count; i++){
            bool level_found = false;

            for (int j = 0; j < size_of_array; j++){
                if (!strcmp(array_levels[j].level, Logs[i].level)) {
                    array_levels[j].count++;
                    level_found = true;

                    if (array_levels[j].count > Stats.max_count){
                        Stats.max_count = array_levels[j].count;
                        strcpy(Stats.most_common, array_levels[j].level);
                    }
                    break;
                }
            }
            if (!level_found){
                LevelCount* temp = (LevelCount*)realloc(array_levels, (size_of_array + 1) * sizeof(LevelCount));

                if (temp == NULL) {
                    free(array_levels);
                    Stats.error = true;
                    return Stats;
                }
        
                array_levels = temp;

                if (size_of_array == 0){
                    strcpy(Stats.most_common, Logs[i].level);
                    Stats.max_count = 1;
                }

                strcpy(array_levels[size_of_array].level, Logs[i].level);
                array_levels[size_of_array].count = 1;
                size_of_array++;
            }
    }

    Stats.levels = array_levels;
    Stats.count = size_of_array;

    return Stats;
}

void write_stats(const LevelStats levels){
    FILE *fptr;

    if (levels.error){
        puts("There is no data to be written into the file.");
        return;
    }

    fptr = fopen("output/log_stats.txt", "w");

    fprintf(fptr, "Total level count: %d\n", levels.count);

    for (int i = 0; i < levels.count; i++){
        fprintf(fptr, "%s: %d\n", levels.levels[i].level, levels.levels[i].count);
    }

    fprintf(fptr, "Most often level: %s\n", levels.most_common);
    fclose(fptr);
}