
#include <iostream>
#include <random>
#include <vector>

double rand_uniform(double min_value, double max_value,
		    ::std::mt19937 & iGenerator) {
  auto lDist = ::std::uniform_real_distribution<double>(min_value,max_value);
  auto real_rand = lDist(iGenerator);
  return real_rand;
}

::std::vector<double>
generate_double_sequence
(double min_value, double max_value,
 ::std::mt19937 & iGenerator, size_t iLength) {
    ::std::vector<double> result(iLength);
    for(size_t i=0; i < iLength; ++i) {
      result[i] = rand_uniform(min_value, max_value, iGenerator);
    }
    return result;
}

int main() {
    ::std::mt19937 lGenerator;
    lGenerator.seed(1789);
    auto lSequence = generate_double_sequence(-10, 10, lGenerator, 100);
    for(size_t i=0; i < lSequence.size(); ++i) {
        std::cout << lSequence[i] << " ";
    }
    std::cout << std::endl << std::flush;
    return 0;
}

/*
g++ -o ./gen_sequence.exe tests/gen_sequence.cpp

output :

5.18761 -0.73608 -7.01618 0.31848 2.12175 -1.56727 -8.84256 3.72039 -4.79075 -7.75999 -9.87224 0.466323 -9.08487 8.18013 0.082479 0.570225 3.69 4.23403 8.758 5.3741 5.50191 9.08379 -7.70701 3.60618 8.57802 -6.4961 8.14968 4.46662 0.749905 5.71185 1.26197 5.75282 6.93151 -9.24749 9.54397 -8.13236 9.5618 3.94225 5.90718 -5.0505 7.03763 -0.896154 4.99712 -1.89473 -9.4609 9.01645 -2.03897 -8.95744 -3.04187 -2.03194 -7.06564 5.75123 8.5129 5.67779 0.942664 6.77879 -0.0245077 6.9426 -3.43792 -4.95519 5.56366 3.2413 -0.0264091 -4.02385 -9.45081 7.45555 -6.6174 -7.5592 -7.67795 -2.28974 -7.21012 1.9301 -7.9198 3.47154 2.68349 -6.61645 8.28767 -1.59331 -4.85899 -8.28019 -5.30093 9.61129 5.18776 7.34476 5.9823 -5.58215 4.64017 -4.34357 8.5159 1.13811 1.16979 9.1496 4.10419 -1.3582 5.52924 -2.64109 -5.18641 8.16239 -5.47754 -5.20888

*/
