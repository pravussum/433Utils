# Defines the RPI variable which is needed by rc-switch/RCSwitch.h
CXXFLAGS=-DRPI

all: send sendIntertechno codesend RFSniffer

send: ../rc-switch/RCSwitch.o send.o
        $(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

sendIntertechno: ../rc-switch/RCSwitch.o sendIntertechno.o
        $(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

codesend: ../rc-switch/RCSwitch.o codesend.o
        $(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

RFSniffer: ../rc-switch/RCSwitch.o RFSniffer.o
        $(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi


clean:
        $(RM) ../rc-switch/*.o *.o send sendIntertechno codesend servo RFSniffer
