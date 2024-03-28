#include <iostream>
#include <vector>
#include <algorithm>
void print_reconstruct(const int max_power, const std::vector<int>& speeds, const std::vector<int>& table){
	std::vector<int> reconstruct(speeds.size(), 0);
	int i = max_power;
	while(table[i] > 0){
		int prev_max = 0;
		int speed_used;
		for(int speed : speeds){
			if(prev_max < table[i - speed]){
				prev_max = table[i - speed];
				speed_used = speed;
			}
		}

		i -= speed_used;
		int j = 0;
		while(speeds[j++] != speed_used);
		++reconstruct[j];
	}

	for(int speed : speeds){
		std::cout << speed << " ";
	}
	std::cout << std::endl;

	for(int val : reconstruct){
		std::cout << val << " ";
	}
	std::cout << std::endl;
}

int max_speed(const int max_power, const std::vector<int>& speeds){
	std::vector<int> chosen(speeds.size(), 0);
	//create a table 
	std::vector<int> table(max_power+1, 0);

	const int len = speeds.size();
	for(int i = speeds[0]; i <= max_power; ++i){
		int max = 0;
		int index_chosen = 0;
		for(int j = 0; j < len && i >= speeds[j]; ++j){
			int speed = speeds[j] + table[i-speeds[j]];
			if(max < speed && speed <= max_power){
				max = speed;
				index_chosen = j;
			}
		}
		table[i] = max;
		++chosen[index_chosen];
	}

//	for(int speed : speeds){
//		std::cout << speed << " ";
//	}
//	std::cout << std::endl;
//
//	for(int cho: chosen){
//		std::cout << cho << " ";
//	}
//	std::cout << std::endl;

	print_reconstruct(max_power, speeds, table);
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
