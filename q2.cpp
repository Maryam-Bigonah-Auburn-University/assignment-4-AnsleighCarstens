#include <iostream>

using namespace std;

class Temperature {
	private:
		double degreesKelvin,
		double degreesFahrenheit,
		int degreesCelsius;
	public:
	    // Constrcutor
	    Tempature() : tempaturekelvin (0), tempHistory(nullptr), historySize(0)

	   // Destructor
	   ~Tempature() {
		Delete[] tempHistory;
	    }

	   // Mutator functions
	   void setTempKelvin(double kelvin) {
		 temperatureKelvin = kelvin;
		 updateHistory();
	    }
	   void setTempCelsius(double celsius) { 
	   	temperatureKelvin = celsius + 273.15;
	   	updateHistory();
	   }	

	   void setTempFahrenheit(double fahrenheit) {  
	   	temperatureKelvin = (fahrenheit - 32) / (5.0/9) + 273.15;
	   	updateHistory();
	   }

	   // Accessor functions
   	   double getTempKelvin() const {
        	return temperatureKelvin;
	   }
		
	   double getTempCelsius() const { 
		return temperatureKelvin - 273.15;
	   } 

	   double getTempFahrenheit() const { 
		 return (temperatureKelvin - 273.15) * 5.0/9 + 32;
	   }

	private:
	   // Private helper function to update temperature history
	   void updateHistory() {
	   // Increase the size of tempHistory
	   double* newHistory = new double[historySize + 1];
		   
	   // Copy old values
           for (int i = 0; i < historySize; ++i) {
        	newHistory[i] = tempHistory[i];
          }
		   
	  // Add the new temperature
          newHistory[historySize] = temperatureKelvin;

	  // Update class variables
          delete[] tempHistory;
          tempHistory = newHistory;
          ++historySize;
    }		
};

int main() {
    // Test the Temperature class
    Temperature temp;

    temp.setTempKelvin(300);
    std::cout << "Temperature in Kelvin: " << temp.getTempKelvin() << std::endl;
    std::cout << "Temperature in Celsius: " << temp.getTempCelsius() << std::endl;
    std::cout << "Temperature in Fahrenheit: " << temp.getTempFahrenheit() << std::endl;

    temp.setTempCelsius(25);
    std::cout << "Temperature in Kelvin: " << temp.getTempKelvin() << std::endl;
    std::cout << "Temperature in Celsius: " << temp.getTempCelsius() << std::endl;
    std::cout << "Temperature in Fahrenheit: " << temp.getTempFahrenheit() << std::endl;

    temp.setTempFahrenheit(212);
    std::cout << "Temperature in Kelvin: " << temp.getTempKelvin() << std::endl;
    std::cout << "Temperature in Celsius: " << temp.getTempCelsius() << std::endl;
    std::cout << "Temperature in Fahrenheit: " << temp.getTempFahrenheit() << std::endl

    return 0;
}

