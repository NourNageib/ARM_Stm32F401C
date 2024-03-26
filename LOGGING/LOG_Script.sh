#!/bin/bash

# Logging start time
echo "Build started at $(date)" > build.log

# Compile and log output
g++ -std=c++11 -Wall -g main.cpp Logger.cpp -o LOG_APP.exe >> build.log 2>&1

# Check build status and log result
if [ $? -eq 0 ]; then
    echo "Build successfully ; )" >> build.log
else
    echo "Build failed : ( " >> build.log
fi
