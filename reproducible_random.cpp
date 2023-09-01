#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

#include <iostream>
#include <random>

namespace py = pybind11;

class cReproducibleRandomNumberGenerator {
  size_t mSeed;
  ::std::mt19937 mGenerator;

public:
  cReproducibleRandomNumberGenerator() : mSeed(1789), mGenerator(){
    mGenerator.seed(mSeed);
  }

  ~cReproducibleRandomNumberGenerator() {

  }

  void set_seed(size_t iSeed) {
    mSeed = iSeed;
    mGenerator.seed(mSeed);    
  }

  size_t rand_int(size_t low, size_t high) {
    auto lDist = ::std::uniform_int_distribution<size_t>(low, high - 1);
    auto int_rand = lDist(mGenerator);
    return int_rand;
  }

  double rand_uniform(double min_value, double max_value) {
    auto lDist = ::std::uniform_real_distribution<double>(min_value,max_value);
    auto real_rand = lDist(mGenerator);
    return real_rand;
  }

  
  py::array_t<double>
  generate_double_sequence
  (double min_value, double max_value, size_t iLength) {
    ::std::vector<double> result(iLength);
    for(size_t i=0; i < iLength; ++i) {
      result[i] = rand_uniform(min_value, max_value);
    }
    py::array result1 = py::cast(result);
    return result1;
  }
  
  py::array_t<size_t>
  generate_int_sequence
  (size_t min_value, size_t max_value, size_t iLength) {
    ::std::vector<size_t> result(iLength);
    for(size_t i=0; i < iLength; ++i) {
      result[i] = rand_int(min_value, max_value);
    }
    py::array result1 = py::cast(result);
    return result1;
  }
  
};

template<class tGen>
void registerClass(py::module_ & m, std::string const & iName) {
  auto lObject = py::class_<tGen>(m, iName.c_str());
    lObject.def(py::init());
    lObject.def("generate_int_sequence", &tGen::generate_int_sequence);
    lObject.def("generate_double_sequence", &tGen::generate_double_sequence);
    lObject.def("set_seed", &tGen::set_seed);
    lObject.def("rand_int", &tGen::rand_int);
    lObject.def("rand_uniform", &tGen::rand_uniform);
}



PYBIND11_MODULE(reproducible_random, m) {
  registerClass<cReproducibleRandomNumberGenerator>(m, "ReproducibleGenerator");
}
