#include "log.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LogEntry create_log_struct(const char* log_infos){
    LogEntry new_log;

    int offset = 0;
    
    int result = sscanf(log_infos, "%10s %8s %9s %n", new_log.date, new_log.time, new_log.level, &offset);
    if (result != 3) return new_log;
    char* msg = log_infos + offset;
    while (*msg == ' ') msg++;

    strncpy(new_log.message, msg, 255);
    
    return new_log;
}

LogEntry* load_logs(const char* filename, int* count){
    FILE *fptr;

    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("File could not be opened properly.\n");
        return NULL;
    }

    char line[256];
    LogEntry* Log_array = NULL;
    int counter = 0;
    
    while (fgets(line, sizeof(line), fptr)){
        LogEntry* temp = (LogEntry*)realloc(Log_array, (counter + 1) * sizeof(LogEntry));

        if (Log_array == NULL) {
            free(Log_array);
            return NULL;
        }
        
        Log_array = temp;

        Log_array[counter]= create_log_struct(line);
        counter++;
    }

    fclose(fptr);
    *count = counter;

    return Log_array;
}

void free_logs(LogEntry* logs){
    free(logs);
}