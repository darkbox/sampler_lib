/*
 Copyright (c) 2023 Rafa G.M.

 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

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
