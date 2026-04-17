
#ifndef WIRE_H_
#define WIRE_H_


void delay(unsigned int val);

class TwoWire
{
public:
	TwoWire();
	~TwoWire();


	void begin();

	void beginTransmission(unsigned int val);
	unsigned int read();
	void requestFrom(unsigned int val1, unsigned int val2);
	void write(unsigned int val);
	unsigned int endTransmission();
	unsigned int available();

private:

};


#endif

