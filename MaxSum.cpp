#include <iostream>
#include <vector>
#include <algorithm>

int max_speed(const int max_power, const std::vector<int>& speeds){
	//create a table 
	std::vector<int> table(max_power+1, 0);

	const int len = speeds.size();
	//iterate over the table starting at first speed
	for(int i = speeds[0]; i <= max_power; ++i){
		//find the maximum value in the table looking back
		int max = 0;
		for(int j = 0; j < len && i >= speeds[j]; ++j){
			int speed = speeds[j] + table[i-speeds[j]];
			if(max < speed && speed <= max_power){
				max = speed;
			}
		}
		table[i] = max;
	}

	//return the final table element
	return table[max_power];
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
		speeds.reserve(num_brick_types);

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
