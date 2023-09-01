# reproducible_random

A python random number generator that can be reproduced across hardware and software platforms. 

Based on the C++ standard random number generator (std::mt19937). 

https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine

Source only.

# Demo

```
import reproducible_random as rep

lGen = rep.ReproducibleGenerator()
lGen.set_seed(1789)
lSequence = lGen.generate_double_sequence(-10, 10, 100)
print(lSequence)
```
