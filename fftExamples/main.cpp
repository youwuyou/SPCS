#include <iostream>
#include <cmath>
#include <fftw3.h>


// Macros for real and imaginary parts
#define REAL 0
#define IMAG 1


int main(){

  // define the length of the complex arrays
  int n = 5;

  // declare input array x, output array y
  fftw_complex x[n], y[n]; // equivalent to double x[n][2]


  // fill the array x with some data
  for(int i = 0; i < n; i++){

      x[i][REAL] = i + 1; // i.e. {1,2,3,4,5}
      x[i][IMAG] = 0;
  }

  //plant the FFT and execute it
  fftw_plan plan = fftw_plan_dft_1d(n,x,y,FFTW_FORWARD, FFTW_ESTIMATE);
  fftw_execute(plan);


  // some clean-up jobs needed
  fftw_destroy_plan(plan);
  fftw_cleanup();


  // display the result
  std::cout << "FFT = "<< std::endl;
  for(int i = 0; i < n; ++i){
        if(y[i][IMAG] < 0){
            std::cout << y[i][REAL] << " - " << std::abs(y[i][IMAG]) << "i" << std::endl;
        }
        else{
            std::cout << y[i][REAL] << " + " << y[i][IMAG] << "i" << std::endl;
        }

  }

  return 0;
}
