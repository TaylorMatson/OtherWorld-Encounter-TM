#include <MIDI.h>

#if defined(USBCON)
#include <midi_UsbTransport.h>

const int RelayForward = 2;
const int RelayReverse = 3;
const int RelayStop = 4;

static const unsigned sUsbTransportBufferSize = 16;
typedef midi::UsbTransport<sUsbTransportBufferSize> UsbTransport;

UsbTransport sUsbTransport;

MIDI_CREATE_INSTANCE(UsbTransport, sUsbTransport, MIDI);

#else // No USB available, fallback to Serial
MIDI_CREATE_DEFAULT_INSTANCE();
#endif

// --

void handleNoteOn(byte inChannel, byte inNumber, byte inVelocity)
{
    Serial.print("NoteOn  ");
    Serial.print(inNumber);
    Serial.print("\tvelocity: ");
    Serial.println(inVelocity);

  if (inNumber == 1){
      //FORWARD
  digitalWrite(RelayForward, LOW);
  digitalWrite(RelayReverse, HIGH);
  digitalWrite(RelayStop, HIGH);
  delay(1000);} else if (inNumber == 2)
  {
      //REVERSE
  digitalWrite(RelayForward, HIGH);
  digitalWrite(RelayReverse, LOW);
  digitalWrite(RelayStop, HIGH);
  delay(1000);
  }
}
void handleNoteOff(byte inChannel, byte inNumber, byte inVelocity)
{
    Serial.print("NoteOff ");
    Serial.print(inNumber);
    Serial.print("\tvelocity: ");
    Serial.println(inVelocity);

      digitalWrite(RelayForward, HIGH);
  digitalWrite(RelayReverse, HIGH);
  digitalWrite(RelayStop, LOW);
  delay(1000);
}

void setup() {
    Serial.begin(115200);
    while (!Serial);
    MIDI.begin();
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
    Serial.println("Arduino ready.");
      pinMode(RelayForward, OUTPUT);
  pinMode(RelayReverse, OUTPUT);
  pinMode(RelayStop, OUTPUT);
}

void loop() {
    MIDI.read();
}
