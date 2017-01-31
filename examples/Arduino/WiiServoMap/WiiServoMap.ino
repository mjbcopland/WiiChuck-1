#include <WiiChuck.h>

#if defined(ARDUINO_ARCH_ESP8266)
#define SDA D2
#define SCL D1
#endif
WiiChuck myChuck(SDA, SCL);

void setup() {

	Serial.begin(115200);
	Serial.println("\n\nStarting WiiChuck Demo");
	//myChuck.type=OFFICIALWII;
	myChuck.type = THIRDPARTYWII;
	//myChuck.type = WIICLASSIC;
	// optional functions 
	//JOY_X,JOY_Y,ROLL,PITCH,ACCELX,ACCELY ,ACCELZ,
	//classic controller
	//RSPRESSURE,LSPRESSURE,LEFTSTICKX,LEFTSTICKY,RIGHTSTICKX,RIGHTSTICKY
	myChuck.addControlMap(D3, // Servo IO pin
			17, // Servo low value
			50, // servo middle
			160, // servo upper bound
			-63, // ontroller lower bound
			0, // controller middle
			100, //controller upper bound
			JOY_X); // Enum for the data source
	myChuck.addControlMap(D4, // Servo IO pin
			160, // mapping cna be reversed by swapping upper and lower
			50, // swapping upper and lower pivots around center
			17, // upper value need not be larger than the lower
			-50, //lower bound cna be non symetric with upper bound
			0, // controller middle
			100, // upper controller bound
			JOY_Y);// different enum for another function
	// button mapping
	//CBUTTON,ZBUTTON 
	//classic controller
	//LZ,RZ,LD,RD,UD,DD,SL,H,START,X,Y,A,B
	myChuck.addButtonMap(D6, // Servo IO pin
			17,// released value
			160, //pressed falue
			ZBUTTON);// select a button funtion
	myChuck.begin();

}
void loop() {

	myChuck.readData();
	delay(40);
}
