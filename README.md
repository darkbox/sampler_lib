# Sampler Lib
Simple Arduino library to average samples.

## Use example
```cpp
#include "Sampler.h"

// Create the sampler object and assign the pool size
Sampler<float>* s1 = new Sampler<float>(8);
 
// Add new samples to the pool
s1->add(new_sampled_value);

// Get averaged value
float current_average = s1->get();
```