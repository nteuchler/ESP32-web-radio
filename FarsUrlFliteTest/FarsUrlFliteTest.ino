/**
 * @file streams-url_aac-audiokit.ino
 * @author Phil Schatzmann
 * @brief decode MP3 stream from url and output it on I2S on audiokit
 * @version 0.1
 * @date 2021-96-25
 * 
 * @copyright Copyright (c) 2021
 */

// install https://github.com/pschatzmann/arduino-libhelix.git

#include "AudioTools.h"
//#include "AudioTools/AudioCodecs/CodecAACHelix.h"
#include "AudioTools.h"
#include "AudioTools/AudioCodecs/CodecMP3Helix.h"
#include "radioStations.h"
#include "AudioTools/AudioLibs/AudioBoardStream.h"

#include <AudioTools/CoreAudio/AudioActions.h>


URLStream url("Fars grillhytte","12345678");  // or replace with ICYStream to get metadata
AudioBoardStream kit(AudioKitEs8388V1); // final output of decoded stream
EncodedAudioStream dec(&kit, new MP3DecoderHelix()); // Decoding stream
StreamCopy copier(dec, url); // copy url to decoder



const char* tts(const char* text, const char* lang="da", const char* speed="1"){
  Str query("http://translate.google.com/translate_tts?ie=UTF-8&tl=%1&client=tw-ob&ttsspeed=%2&q=%3");
  query.replace("%1",lang);
  query.replace("%2",speed);

  Str encoded(text);
  encoded.urlEncode();
  query.replace("%3", encoded.c_str());
  return query.c_str();
}




int radioKanal = 0;

bool radioMode = true;

void Speak(){
  url.end();
  delay(100);
  kit.setVolume(1.0);
  const char* url_str = tts(radioListeText[radioKanal]);
  Serial.println(url_str);

  // generate mp3 with the help of google translate
  url.begin(url_str ,"audio/mp3");
  unsigned long startTime = millis();

  // Run the while loop for 3000 milliseconds (3 seconds)
  while (millis() - startTime < 1600) {
    copier.copy();
    kit.processActions();
  }
  kit.setVolume(0.8);
}

void button3(bool active, int pin, void* ptr){
    Serial.println("button 1 pressed");
    radioKanal = radioKanal + 1;
    if (radioKanal >= radioListeLength) {
      radioKanal = 0;
    }

    Serial.println(radioKanal);
    Serial.println("Afspiller Nu ::::::::");
    Serial.println(radioListeText[radioKanal]);

    Speak();
    url.begin(radioListe[radioKanal]);
}

void button4(bool active, int pin, void* ptr){
    Serial.print("button 2 pressed");
    radioKanal = radioKanal -1;
    if (radioKanal < 0) {
      radioKanal = radioListeLength - 1;
    }
  Serial.println("Afspiller Nu ::::::::");
  Serial.println(radioListeText[radioKanal]);
  

  Speak();

  url.begin(radioListe[radioKanal]);
}

/*
void button5(bool active, int pin, void* ptr){
  // Skifter mellem Radio og bluetooth

  if (radioMode == true) {  // Check if radioMode is TRUE
    // Switch to Bluetooth mode
    Serial.println("Changing to Bluetooth mode");
    radioMode = false;
  } else {
    // Switch to radio mode
    radioMode = true;
    Serial.println("Changing to radio mode");
    URLStream url("Fars grillhytte", "12345678");  // Replace with ICYStream if metadata is needed
    AudioBoardStream kit(AudioKitEs8388V1);  // Final output of decoded stream
    EncodedAudioStream dec(&kit, new MP3DecoderHelix());  // Decoding stream
    StreamCopy copier(dec, url);  // Copy URL to decoder

    // Setup I2S
    auto config = kit.defaultConfig(TX_MODE);
    kit.begin(config);

    // Setup I2S based on sampling rate provided by decoder
    dec.begin();

    // Start the AAC radio stream
    url.begin(radioListe[radioKanal]);
}}
*/




void setup(){
  Serial.begin(115200);
  AudioToolsLogger.begin(Serial, AudioToolsLogLevel::Warning);  

  // setup i2s
  auto config = kit.defaultConfig(TX_MODE);
  kit.begin(config);

  // Start in radio mode:
  dec.begin();
  // aac radio
  kit.setVolume(0.8);
  url.begin(radioListe[radioKanal]);




  kit.audioActions().add(kit.getKey(3), button3);
  kit.audioActions().add(kit.getKey(4), button4);



}



void loop(){
  copier.copy();
  kit.processActions();
}