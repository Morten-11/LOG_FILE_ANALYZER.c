# LOG file analyzer in C

## Description
This project is a log file analyzer written in C. The program allows you to read in log files, parse their content into structured data and compute basic statistics such as error counts or event frequencies.

## Features
- input files & parse them
- generate an output file
- analyzes the input file for simple statistics
- able to choose your input file
- simple build with the provided makefile

## How to build & run
First move into the root folder of this repository and then make use of the makefile in the terminal to run the application:
```
make run
```

## Usage
An example of an input file is already provided under /input/logfile.txt. To be able to use this application, you need to provide a suitable input file in the input folder. The format of the input file is the following for every line:
```
year-month-day hour:minute:second level further description
```
The level specifies at which level the log appeared, for example at the info, warning or error level. 

## Example
For the provided input example in the input folder:
```
2026-04-20 10:15:23 INFO System started
2026-04-20 10:16:01 WARNING High memory usage
2026-04-20 10:17:45 ERROR Connection failed
2026-04-20 10:18:02 INFO Retry connection
2026-04-20 10:18:10 ERROR Connection failed
```
You can find an output in the output folder, looking like this:
```
Total level count: 3
INFO: 2
WARNING: 1
ERROR: 2
Most often level: INFO
```
The application will count all the log levels and list the quantities of each of them, as well as the log level that appeared most often. Additionally it will count how many different levels were specified in total.
