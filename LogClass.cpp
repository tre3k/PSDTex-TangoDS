#include "LogClass.h"

LogClass::LogClass(std::string logfile){
	lf.open(logfile, std::ofstream::out | std::ofstream::app);
	
	return;
}


void LogClass::write(std::string text){
	time_t now = time(0);
	lf << ctime(&now) << " : " << text << std::endl;  
	return;
}


void LogClass::write4values(double x1,double x2,double y1, double y2,bool correct){
	lf << "\t" << "x1 = " << x1 << ", x2 = " << x2 << ", y1 = " << y1 << ", y2 = " << y2;
	if(correct) lf << ", 1" << std::endl;
	else lf << ", 0" << std::endl;
	return;
}
