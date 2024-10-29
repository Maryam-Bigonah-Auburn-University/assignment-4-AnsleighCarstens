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
		    
		void setTempKelvin(double degreesKelvin) { 
			TempertureKelvin = kelvin;
		}
		double getTempKelvin() {  }
		void setTempCelsius() {  }
		double getTempCelsius() {  } 
		void setTempFahrenheit() {  }
		double getTempFahrenheit() { }
};

int main() {

}
