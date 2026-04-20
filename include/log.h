#ifndef LOG_H
#define LOG_H

typedef struct {
    char date[11];      
    char time[9];       
    char level[10];     
    char message[256];  
} LogEntry;

LogEntry create_log_struct(const char* log_infos);

LogEntry* load_logs(const char* filename, int* count);

void free_logs(LogEntry* logs);

#endif