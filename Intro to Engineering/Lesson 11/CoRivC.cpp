#include <fstream>
#include <iostream>
#include <vector>

std::vector<float> extract365(std::string startdate, std::vector<std::string> dateVector, std::vector<float> disVect);
void rectrule(std::vector<float> yearDis, int year);

int main(){
	std::vector<std::string> date;
	std::vector<float> disVect;
	std::ifstream fileRead("Colorado_Discharge_UT_CO.txt");
	if(!fileRead.is_open()) {
		std::cout<< "could not open file! \n";
	} else {
		std::string tempdate = "fill";
		float tempDis;
		for(int i = 0; i < 24; i++){
			fileRead.ignore(5000,'\n');
		}
		//skips the headerlines
		while(fileRead.eof() == 0){
			fileRead.ignore(5000,'	');
			fileRead.ignore(5000,'	');
			fileRead>>tempdate;
			date.push_back(tempdate);
			fileRead>>tempDis;
			disVect.push_back(tempDis);
			fileRead.ignore(5000,'\n');
			//std::cout<< tempdate; //bug testing
		}
		//std::cout<< disVect.size();
	}//end of reading the file
	std::vector<float> an_discharge = extract365("1955-01-01",date,disVect);
	//std::cout<< an_discharge.size(); //debug
	rectrule(an_discharge, 1955);
	//extract data and use rectangle rule. the function also gives the output
	an_discharge = extract365("1960-01-01",date,disVect);
	rectrule(an_discharge, 1960);
	//repeat....
	an_discharge = extract365("1965-01-01",date,disVect);
	rectrule(an_discharge, 1965);
	an_discharge = extract365("1970-01-01",date,disVect);
	rectrule(an_discharge, 1970);
	an_discharge = extract365("1975-01-01",date,disVect);
	rectrule(an_discharge, 1975);
	an_discharge = extract365("1980-01-01",date,disVect);
	rectrule(an_discharge, 1980);
	an_discharge = extract365("1985-01-01",date,disVect);
	rectrule(an_discharge, 1985);
	an_discharge = extract365("1990-01-01",date,disVect);
	rectrule(an_discharge, 1990);
	an_discharge = extract365("1995-01-01",date,disVect);
	rectrule(an_discharge, 1995);
	an_discharge = extract365("2000-01-01",date,disVect);
	rectrule(an_discharge, 2000);
	an_discharge = extract365("2005-01-01",date,disVect);
	rectrule(an_discharge, 2005);
	an_discharge = extract365("2010-01-01",date,disVect);
	rectrule(an_discharge, 2010);
	an_discharge = extract365("2015-01-01",date,disVect);
	rectrule(an_discharge, 2015);
	return 0;
}

std::vector<float> extract365(std::string startdate, std::vector<std::string> dateVector, std::vector<float> disVect){
	std::vector<float> retVec;
	for(int loop = 0; loop < dateVector.size(); loop++){
		if(dateVector[loop] == startdate){
			//std::cout<<"read!"; //bugfix
			for(int daysince = 0; daysince < 365; daysince++){
				retVec.push_back(disVect[loop + daysince]);
				//std::cout<< disVect[loop + daysince] << " "; //bug testing
			}
			break;
			//stops outer for loop
		}
	}
	return retVec;
}

void rectrule(std::vector<float> yearDis, int year){
	double total = 0.0;
	for(int loop = 0; loop < yearDis.size(); loop++){
		total = yearDis[loop] + total;
	}
	total = 24 * 60 * 60 * total;
	std::cout<< "The total discharge for year " << year << " is " << total << " ft^3 \n";
	return;
}
