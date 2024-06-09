/*

https://github.com/crayzeewulf/libserial/blob/master/examples/Makefile.am

old: https://libserial.readthedocs.io/en/latest/tutorial.html

sudo apt install libserial-dev
(libserial1)

g++ test.cpp -lserial

*/

#include <libserial/SerialPort.h>

#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <unistd.h>

using namespace LibSerial;

int main()
{
    // Create and open the serial port for communication.
SerialPort serial_port;
    try
    {
        serial_port.Open("/dev/ttyACM0");
    }
    catch (const OpenFailed&)
    {
        std::cerr << "The serial port did not open correctly." << std::endl ;
        return EXIT_FAILURE ;
    }


/*
// Obtain the serial port name from user input.
std::cout << "Please enter the name of the serial device, (e.g. /dev/ttyUSB0): " << std::flush;
std::string serial_port_name;
std::cin >> serial_port_name;

// Open the serial port for communication.
my_serial_port.Open( serial_port_name );
my_serial_stream.Open( serial_port_name );
*/

// Set the desired baud rate using a SetBaudRate() method call.
// Available baud rate values are defined in SerialStreamConstants.h.

my_serial_port.SetBaudRate(LibSerial::BaudRate::BAUD_38400);
//my_serial_stream.SetBaudRate( BAUD_9600 );

// Set the desired character size using a SetCharacterSize() method call.
// Available character size values are defined in SerialStreamConstants.h.
my_serial_port.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);
//my_serial_stream.SetCharacterSize( CHAR_SIZE_8 );

// Set the desired flow control type using a SetFlowControl() method call.
// Available flow control types are defined in SerialStreamConstants.h.
my_serial_port.SetFlowControl( LibSerial::FlowControl::FLOW_CONTROL_NONE );
//my_serial_stream.SetFlowControl( FLOW_CONTROL_HARD );

// Set the desired parity type using a SetParity() method call.
// Available parity types are defined in SerialStreamConstants.h.
my_serial_port.SetParity( LibSerial::Parity::PARITY_ODD );
//my_serial_stream.SetParity( PARITY_ODD );

// Set the number of stop bits using a SetNumOfStopBits() method call.
// Available stop bit values are defined in SerialStreamConstants.h.
my_serial_port.SetStopBits( LibSerial::StopBits::STOP_BITS_1 ) ;
//my_serial_stream.SetNumOfStopBits( STOP_BITS_1 ) ;

// Read one character from the serial port within the timeout allowed.
int timeout_ms = 0; // timeout value in milliseconds
char next_char;      // variable to store the read result

for (;;) {
  my_serial_port.ReadByte( next_char, timeout_ms );
  //my_serial_stream.read( next_char );
  printf("%c", next_char);
}

/*
// Read one character from the serial port.
char next_char;
my_serial_stream >> next_char;

// You can also read other types of values from the serial port in a similar fashion.
int data_size;
my_serial_stream >> data_size;



// Read one byte from the serial port.
char next_byte;
my_serial_stream.get( next_byte );

*/

my_serial_port.Close();
//my_serial_stream.Close();
}

