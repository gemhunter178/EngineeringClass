/* PSEUDOCODE FOLLOWING:
1, INITIALIZE required libraries <cmath> <iostream>
2, DECLARE a function for trapezoidal rule with parameters bin number, start domain, end domain
3, START main()
4, DEClARE variables: 20 for bins, 0 for start doamin, 2 for end domain
5, CALL trapezoidal rule function
6, RETURN 0;

TRAPEZOIDAL FUNCTION (parameters bin number, start and end domain)
1, DECLARE variable binLength = (endDomain - startDomian) / binSize; also binArea;
2, START a loop for float lastTest = startDomain; lastTest > endDomain, lastTest += binLength
3, CALCULATE binArea = (pow(lastTest,2)+pow(lastTest-binLength,2))*binLength/2;
4, ADD binArea to a total
5, IF LOOP ENDS: OUTPUT total
6, RETURN;

x^2 from 0 to 2, 20 bins, trapezoidal
*/

#include <cmath>
#include <iostream>

using namespace std;

void trapez(int binNum, float startDomain, float endDomain);


int main(){
	int binNum = 20;
	//makes it a true float
	float startDomain = 0.0;
	float endDomain = 2;
	trapez(binNum,startDomain,endDomain);
	return 0;
}


void trapez(int binNum, float startDomain, float endDomain){
	float binLength = (endDomain - startDomain) / binNum;
	//bug fixing
	//cout<< binLength;
	float binArea;
	float totalArea;
	for(float lastTest = startDomain; lastTest < endDomain; lastTest += binLength){
		//more bug fixing
		//cout<< lastTest;
		binArea = (powf(lastTest,2) + pow(lastTest+binLength, 2)) * binLength / 2;
		//even more
		//cout<< binArea;
		totalArea += binArea;
	}
	cout<< totalArea;
}
