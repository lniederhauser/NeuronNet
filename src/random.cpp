#include "random.h"

RandomNumbers::RandomNumbers(unsigned long int s){
	if(s == 0){
        std::random_device rd;
        seed = rd();
    }
    rng = std::mt19937(seed);
}

void RandomNumbers::uniform_double(std::vector<double>& numbers, double lower, double upper){
	std::uniform_real_distribution<> unif_distr(lower, upper);
	for(size_t i(0); i < numbers.size(); ++i){
		numbers[i] = unif_distr(rng);
	}
}

double RandomNumbers::uniform_double(double lower, double upper){
	std::uniform_real_distribution<> unif_distr(lower, upper);
	return unif_distr(rng);
}

void RandomNumbers::normal(std::vector<double>& numbers, double mean, double sd){
	std::normal_distribution<> norm_distr(mean, sd);
	for(size_t i(0); i < numbers.size(); ++i){
		numbers[i] = norm_distr(rng);
	}
}

double RandomNumbers::normal(double mean, double sd){
	std::normal_distribution<> norm_distr(mean, sd);
	return norm_distr(rng);
}

void RandomNumbers::poisson(std::vector<int>& numbers, double mean){
	std::poisson_distribution<> poisson_distr(mean);
	for(size_t i(0); i < numbers.size(); ++i){
		numbers[i] = poisson_distr(rng);
	}
}

int RandomNumbers::poisson(double mean){
	std::poisson_distribution<> poisson_distr(mean);
	return poisson_distr(rng);
}

