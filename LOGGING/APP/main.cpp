/************************************/
/*	Author	  :	Nour Abdel-aziz		*/
/*	SWC		  : logger_APP			*/
/*	Version	  :	1.1		  			*/
/*	Date	  :	Febraury 27, 2024	*/
/*	Last Edit :	Febraury 29, 2024	*/
/************************************/
#include "Logger.h"

int main()

{
    /* Set log file name  */
    Logger logger("LOGGER_Test.txt");

/*       
	          Set the log level 
	options : (DEBUG, INFO, WARNING, ERROR)
*/
	/*Change log level as needed*/
    logger.setLogLevel(Severity::INFO); 

    logger.log(Severity::DEBUG, "This is a debug message");
    logger.log(Severity::INFO, "This is an info message");
    logger.log(Severity::WARNING, "This is a warning message");
    logger.log(Severity::ERROR, "This is an error message");

    return 0;
}
