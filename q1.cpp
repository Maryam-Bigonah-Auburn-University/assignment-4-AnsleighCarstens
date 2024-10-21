#include <iostream>
#include <cstdlib>

using namespace std;

class GasPump {
	private:
		//Private member variables
		float pricePerGallon;
		int gallons;
		float amount;

	public:
		// Constructor
		GasPump(float pricePerGallon, int gallons, float amount)  {
			this->pricePerGallon = pricePerGallon;
			this->gallons = gallons;
			this ->amount = amount;
		}
        
		// Resets the values of pump display counters
		void reset() {
			gallons = 0;
			amount = 0;
		}

		// Resets the displays, dispenses gasoline, computes values, and displays values as gas is being pumped
		void fill() {
			reset();
			int dispensed = quantity();
			for (int i = 0; i <= dispensed; i++) {
				display();
				gallons += 1;
				amount += pricePerGallon;
			}
		}

		// Prints the pump displays - price per gallon, # of gallons, and total price
		void display() {
			cout << "Price: $" << pricePerGallon << " Gallons: " << gallons << " Amount: $" << amount << amount << endl;
		}

		// Call display to print the current display of the pump
		void start_() {
			display();
		}

		// Generate a random number to represent the amount of gasoline dispensed
		int start_buy() {
			display();
	}		
};
	
int main() {
	int k;
	cout << "Enter k (number of gas purchases to stimulate): ";
	cin >> k ;

	GasPump pump(3.15, 10, 31.50);

	for (int i = 1; i <= k; i++) {
		cout << i << ":" << endl;
		pump.start_buy();
		pump.fill();
		cout << "End of fill." <<endl << endl;
	}
	
	return 0;
}
