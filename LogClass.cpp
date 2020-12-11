#include "LogClass.h"

LogClass::LogClass(std::string logfile){
	lf.open(logfile, std::ofstream::out | std::ofstream::app);
	_logfile = logfile;
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


void LogClass::initRaw(){
	time_t now = time(0);
	struct tm *t = gmtime(&now);

	std::string ss = std::to_string(t->tm_sec);
	if(t->tm_sec < 10) ss = "0"+std::to_string(t->tm_sec);
	std::string mm = std::to_string(t->tm_min);
	if(t->tm_min < 10) mm = "0"+std::to_string(t->tm_min);
	std::string hh = std::to_string(t->tm_hour);

	std::string day = std::to_string(t->tm_mday);
	std::string mon = std::to_string(t->tm_mon+1);
	if(t->tm_mon+1 < 10) mon = "0"+std::to_string(t->tm_mon+1);
	std::string year = std::to_string(t->tm_year+1900);
	
	rf = fopen(std::string(_logfile+"."+hh+"."+mm+"."+ss+"_("+day+"-"+mon+"-"+year+").raw").c_str(),"w+");
}

void LogClass::stopRaw(){
	if(rf == nullptr) return;
	fclose(rf);
}

void LogClass::writeRaw(std::vector<PLX9030Detector::raw_data> raw_values){
	if(rf == nullptr) return;
	int size = sizeof(PLX9030Detector::raw_data);
	
	for(auto raw : raw_values){
		fwrite((char *)&raw,1,size,rf);
	}
}


