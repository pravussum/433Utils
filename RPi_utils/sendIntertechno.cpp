/*
 Usage: ./send <familyCode> <systemCode> <unitCode> <command>
 family: a - f
 Command is 0 for OFF and 1 for ON
 */

#include "../rc-switch/RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    /*
     output PIN is hardcoded for testing purposes
     see https://projects.drogon.net/raspberry-pi/wiringpi/pins/
     for pin mapping of the raspberry pi GPIO connector
     */
    int PIN = 0;
    char* familyStr = argv[1];
    printf("%s", familyStr);
    char family = familyStr[0];

    int systemCode = atoi(argv[2]);
    int unitCode = atoi(argv[3]);
    int command  = atoi(argv[4]);

    if (wiringPiSetup () == -1) return 1;
    printf("sending family [%c] systemCode[%i] unitCode[%i] command[%i]\n", family, systemCode, unitCode, command);
    RCSwitch mySwitch = RCSwitch();
    if (argv[5] != NULL) mySwitch.setPulseLength(atoi(argv[5]));
    mySwitch.enableTransmit(PIN);

    switch(command) {
        case 1:
            mySwitch.switchOn(family, systemCode, unitCode);
            break;
        case 0:
            mySwitch.switchOff(family, systemCode, unitCode);
            break;
        default:
            printf("command[%i] is unsupported\n", command);
            return -1;
    }
    return 0;
}
