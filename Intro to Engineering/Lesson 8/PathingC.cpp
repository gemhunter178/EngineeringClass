//for random paths
#include <algorithm>
//for input for how many paths to run
#include <iostream>
//to read the file
#include <fstream>
//to find distances
#include <cmath>
//to make the grids and such display nicely
#include <iomanip>
//to set the rand seed
#include <ctime>

//finds distance between two points.
float distance(float n_start_loc, float n_end_loc, float w_start_loc, float w_end_loc);

int main(){
	//declares vectors that will be written to later
	std::vector<std::string> location;
	std::vector<float> w_dist;
	std::vector<float> n_dist;
	//opens file
	std::ifstream fileRead("Distance.txt");
	if(!fileRead.is_open()) {
		std::cout<< "could not open file! \n";
	} else {
		//ignores essentially the first line, which are words
		fileRead.ignore(5000,'\n');
		//these vaiables are used in reading the file
		std::string tempWord;
		float tempNum;
		//this reads the file and writes to the appropriate vectors
		while(n_dist.size() < 15){
			//location name
			fileRead >> tempWord;
			location.push_back(tempWord);
			//west distances
			fileRead >> tempNum;
			w_dist.push_back(tempNum);
			//north distances
			fileRead >> tempNum;
			n_dist.push_back(tempNum);
		}
		//since we know how mig we need an array of distances to be, we'll be using an array
		float distanceArray[15][15];
		//now, with the distance function, we'll make an array of distances
		//these are for row and column numbers
		int row = 0, column = 0;
		while(row < 15){
			distanceArray[row][column] = distance(n_dist[row],n_dist[column],w_dist[row],w_dist[column]);
			//seeing if it wrote properly
			//std::cout<< std::setw(20) << distanceArray[row][column];
			if(column == 14){
				row++;
				column = 0;
				//std::cout<< std::endl;
			} else {
				column++;
			}
		}
		//SETUP IS NOW DONE, ON TO FINDING PATHS
		//this is the default starting path
		int path[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0};
		int tries;
		//this is to make the paths "more random"
		std::srand(std::time(NULL));
		//value for a total distance
		float total_dist;
		//these are going to be used for shortest path
		//no path is longer than 1000000
		float shortest_dist = 1000000;
		int shortest_path[16];
		//read how many tries
		std::cout<< "How many random paths do you wish to try?\n";
		std::cin>> tries;
		//test that many tries of paths
		for(int testNum = 0; testNum < tries; testNum++){
			std::random_shuffle(&path[1],&path[15]);
			//see if path is different
			/*for(int i = 0; i < 16; i++){
				std::cout<< path[i] << "  ";
			}
			std::cout<< std::endl;*/
			total_dist = 0;
			for(int pathstep = 1; pathstep <= 15; pathstep++){
				total_dist = total_dist + distanceArray[path[pathstep - 1]][path[pathstep]];
			}
			//store shortest path if the last one was shorter than shortest path
			if(total_dist < shortest_dist){
				shortest_dist = total_dist;
				for(int overwrite = 0; overwrite < 16; overwrite++){
					shortest_path[overwrite] = path[overwrite];
				}
			}
		}
		//outputs everything needed
		std::cout<< "The shortest path tried ran " << shortest_dist << " miles.\n\n";
		std::cout<< "It ran through (in order):";
		for(int disp = 0; disp < 16; disp++){
			std::cout<< "\n" << location[shortest_path[disp]];
		}
	}
	return 0;
}

float distance(float n_start_loc, float n_end_loc, float w_start_loc, float w_end_loc) {
    float n_diff = n_start_loc - n_end_loc;
    float w_diff = w_start_loc - w_end_loc;
    return sqrt(pow(n_diff, 2) + pow(w_diff, 2));
}

