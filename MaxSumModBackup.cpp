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

	//find the max_power moded by min_speed
	int max_power_mod = max_power % min_speed;

	//if the max power cannot be made then 0 is as close as it gets
	if(max_power < min_speed){
		return 0;
	}

	//iterate through each speed
	int max_speed_mod = 0; //get this close to max_power_mod 
	int len = speeds.size();
	for(int i = 1; i < len; ++i){
		int speed = speeds[i];
		int accumulated_speed = speed;
		while(accumulated_speed < max_power && max_speed_mod != max_power_mod){
			int speed_mod = accumulated_speed % min_speed;//find the new speed mod
			//if speed mod is less than or equal to max_power_mod
			//and is greater than max_speed_mod
			//then set a new max_speed_mod
			if(speed_mod <= max_power_mod && speed_mod > max_speed_mod){
				max_speed_mod = speed_mod;
			}
			accumulated_speed += speed;//add to the speed
		}
	}

	if(max_power_mod != max_speed_mod){
		return max_speed_dp(max_power, speeds);
	}

	return max_power - (max_power_mod - max_speed_mod);
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
