#include "Arduino.h"
bool serialRecivied;
String command;
void setup() {
// Add your initialization code here
}


void loop() {
	if(serialRecivied) {
		switch(command) {
		case "reset":
			reset();
			break;
		}
	}
}

void reset() {

}
