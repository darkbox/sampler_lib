#pragma once

template<typename T>
class Sampler {
  private:
    T* samples;
    int n_samples;
    int index = 0;
    int initial_counter = 0;
    
  public:
    Sampler(int n_samples) {
      this->n_samples = n_samples;
      samples = new T[n_samples]{};  
    };
    void add(T value){
      samples[this->index] = value;
      this->index++;
  
      if (this->index >= this->n_samples) {
        this->index = 0;
      }

      if (initial_counter < n_samples) initial_counter++;
    };
    T get() {
       T sum = 0;
  
      for (int i = 0; i < this->n_samples; i++) {
        sum += samples[i];
      }
      
      return initial_counter < n_samples ? sum / initial_counter : sum / n_samples;  
    };
};
