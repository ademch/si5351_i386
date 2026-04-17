// si5351_i386.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "si_5351.h"

Si5351 si5351;

int main()
{
    std::cout << "Hello World!\n";

	bool i2c_found;
	i2c_found = si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0);
	if (!i2c_found)
	{
		//Serial.println("Device not found on I2C bus!");
	}

	// Set CLK0 to output 140 MHz
	si5351.set_freq(SI5351_CLK0, 14000000000ULL);

	// Set CLK1 to output 175 MHz
	si5351.set_multisynth_source(SI5351_CLK1, SI5351_PLLB);
	si5351.set_freq_manual(SI5351_CLK1, 17500000000ULL);

	// Query a status update and wait a bit to let the Si5351 populate the
	// status flags correctly.
	si5351.update_status();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
