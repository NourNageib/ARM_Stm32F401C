# **Logging Application :**

Mainly, logging application is useful way to capture and record history of all messages and data and what happened in details during software execution with timestamp and its  very useful when you want to re-watch what happened in details,Thus this application is use to record all this data in log.txt file for later analysis and review or you can share it easily.

* Besides, Logging may be used to configure and monitor the status of more than one software application







-------------------------------------------------------------

## **To have your windows LOG application follow the following steps :**

(Note : these steps on vs code)

* ### **Step  "1" : **                                                                                                                                                                                                                                                                                     

  Create `customloggingfilename.cpp` ,`customloggingfilename.h` and `main.cpp` files 

  from terminal :

  ```cmd
  touch Log.cpp Log.h main.cpp
  ```

* ### **Step  "2" : **    

  **Log.h** :

  ```c++
  #ifndef LOG_H
  #define LOG_H
  
  #include <string>
  
  enum class LoggingLevel {
      INFO,
      WARNING,
      ERROR,
      CRITICAL
  };
  
  class Logger {
  public:
      static void log(const std::string& message, LoggingLevel level = LoggingLevel::INFO);
  };
  
  #endif
  ```

  