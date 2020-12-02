#ifndef LOG_CLASS_H
#define LOG_CLASS_H

#include <iostream>
#include <fstream>
#include <ctime>

class LogClass{
protected:
	std::string _logfile;
	std::ofstream lf;
public:
	LogClass(std::string logfile);
	~LogClass(void){lf.close();}
	void write(std::string text);
	void write4values(double x1,double x2,double y1, double y2);

};


#endif
