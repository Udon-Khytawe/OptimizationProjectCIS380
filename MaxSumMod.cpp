#include <iostream>
#include <vector>
#include <algorithm>

int max_speed_dp(const int max_power, const std::vector<int>& speeds){
	//create a table 
	std::vector<int> table(max_power+1, 0);

	const int len = speeds.size();
	for(int i = speeds[0]; i <= max_power; ++i){
		int max = 0;
		for(int j = 0; j < len && i >= speeds[j]; ++j){
			int speed = speeds[j] + table[i-speeds[j]];
			if(max < speed && speed <= max_power){
				max = speed;
			}
		}
		table[i] = max;
	}

	return table[max_power];
}


//speeds must be a sorted vector
int max_speed(const int max_power, const std::vector<int>& speeds){
	
	//since speeds is sorted min is the first element 
	int min_speed = speeds[0];

	//if the max power cannot be made then 0 is as close as it gets
	if(max_power < min_speed){
		return 0;
	}

	//iterate through each speed
	int len = speeds.size();
	for(int i = 1; i < len; ++i){
		int speed = speeds[i];
		if(max_power >= speed*min_speed){
			return max_power;
		}
	}

	return max_speed_dp(max_power, speeds);
}

int main(){
	//read in the number of cases
	int num_cases;
	std::cin >> num_cases;

	//for each test case
	for(int i = 0; i < num_cases; ++i){
		//read in the number of brick types and max power
		int num_brick_types, max_power;
		std::cin >> num_brick_types >> max_power;

		//create a vector for the brick types
		std::vector<int> speeds;
		speeds.reserve(2*num_brick_types);

		//read in the brick types
		for(int i = 0; i < num_brick_types; ++i){
			int speed;
			std::cin >> speed;
			speeds.push_back(speed);
		}
		
		//sort the speeds
		std::sort(speeds.begin(), speeds.end());
		//print out the max speed
		std::cout << max_speed(max_power, speeds) << std::endl;
	}

	return 0;
}
