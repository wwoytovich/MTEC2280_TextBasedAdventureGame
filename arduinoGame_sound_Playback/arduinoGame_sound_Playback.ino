////////////////////////////////
///////declarations////////////
///////////////////////////////////
#include "pitches.h"
int qN = 50;
int hN = 100;

int trapRoomBeats[10] = {150,200,150,150,750,75,75,75,100,200};
int trapRoomNotes[10] = {NOTE_GS4,NOTE_G4,NOTE_FS4,NOTE_AS4,NOTE_FS4,NOTE_DS4,NOTE_FS4,NOTE_AS4,NOTE_FS4,NOTE_DS4};


int introSongBeats[10] = {500,200,500,200,1500,400,500,705,1025,250};
int introSongNotes[10] = {NOTE_AS5,NOTE_A6,NOTE_AS5,NOTE_B5,NOTE_C6,NOTE_G5,NOTE_A5,NOTE_DS6,NOTE_C6,0};


int monsterRoomBeats[10] = {100,50,100,50,300,100,50,100,50,300};
int monsterRoomNotes[10] = {NOTE_C3,0,NOTE_C3,0,NOTE_DS3,NOTE_C3,0,NOTE_C3,0,NOTE_DS3};


int nothingRoomBeats[10] = {100,200,300,400,500,400,300,200,100,10};
int nothingRoomNotes[10] = {500,600,700,800,900,1000,850,760,540,280};


int youDiedBeats[10] = {200,200,200,200,200,200,200,200,20,2500};
int youDiedNotes[10] = {1000,0,1000,0,1000,724,526,357,0,1000};


int newLevelBeats[10] = {88,90,92,95,98,105,110,125,130,135};
int newLevelNotes[10] = {250,300,400,500,450,250,300,400,500,600};


int rareEncounterBeats[10] = {50,50,50,50,50,50,50,50,50,200};
int rareEncounterNotes[10] = {1000,1505,1000,1500,1000,1475,1000,1440,1000,1390};


int healthRoomBeats[10] = {200,150,250,150,100,200,150,150,125,125};
int healthRoomNotes[10] = {200,0,300,00,1000,0,200,0,600,0};


int takeDamageBeats[10] = {100,75,300,100,75,40,40,40,20,40};
int takeDamageNotes[100] = {540,500,0,540,500,220,220,220,220,0};


int winSongBeats[10] = {100,200,300,100,200,300,100,200,100,100};
int winSongNotes[10] = {100,200,400,100,200,400,100,200,400,600};
/////////////////////////////////////
///////////////////////////////////////
/////////////////////////////////////
// shit why does this not work in a different tab?
/////////////////////////
/////////////////
////////////////////////
////////////////////

int currentSongnotes[10] ={};
int currentSongbeats[10] ={};
int speaker = 8; //speaker connected to pin 8
char incomingByte;   // for incoming serial data
char english; // for using a char to compare to
//String currentSongnotes; // songsnote name array
//String currentSongbeats; // name of song beat array
//String currentSongLen; // name of song length int


void setup() 
{
  Serial.begin(9600); 
}

void loop() 
{
  readinput();
}


void readinput()
{
  if (Serial.available() > 0) 
  {
    // read the incoming byte:
    incomingByte = Serial.read();
   // Serial.print("I received: ");
    //Serial.println(incomingByte);
    switch(char(incomingByte))
    {
      case 't': //trap room
          for(int i = 0 ; i < 10 ; i++ )
        {
          currentSongnotes[i] = trapRoomNotes[i];
          currentSongbeats[i] = trapRoomBeats[i];
        }
        playSong();
        incomingByte = 'q';
        //Serial.println("playing trap room song");
        //tone(8, 1000, 100);
        break;
        
      case 'p': //intro song
        for(int i = 0 ; i < 10 ; i++ )
        {
          currentSongnotes[i] = introSongNotes[i];
          currentSongbeats[i] = introSongBeats[i];
        }
        playSong();
        playSong();
        incomingByte = 'q';
        break;
        
      case 'm': //monster room
        for(int i = 0 ; i < 10 ; i++ )
        {
          currentSongnotes[i] = monsterRoomNotes[i];
          currentSongbeats[i] = monsterRoomBeats[i];
        } 
        playSong();
        playSong();
        playSong(); 
        incomingByte = 'q';
        break;
        
      case 'k': // you die (are killed)
        for(int i = 0 ; i < 10 ; i++ )
        {
          currentSongnotes[i] = youDiedNotes[i];
          currentSongbeats[i] = youDiedBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;
        
      case 'l': // new level
        for(int i = 0 ; i < 10 ; i++ )
        {
          currentSongnotes[i] = newLevelNotes[i];
          currentSongbeats[i] = newLevelBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;
        
      case 'r': //rare encounter
        for(int i = 0 ; i < 10 ; i++ )
        {
          currentSongnotes[i] = rareEncounterNotes[i];
          currentSongbeats[i] = rareEncounterBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;
        
      case 'h':
        for(int i = 0 ; i < 10 ; i++ )
        {
          currentSongnotes[i] = healthRoomNotes[i];
          currentSongbeats[i] = healthRoomBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;

      case 'w':
        for(int i = 0 ; i < 10 ; i++ )
        {
          currentSongnotes[i] = winSongNotes[i];
          currentSongbeats[i] = winSongBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;

      case 'd': // take damage
        for(int i = 0 ; i < 10 ; i++ )
        {
          currentSongnotes[i] = takeDamageNotes[i];
          currentSongbeats[i] = takeDamageBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;

      default:
        //tone(8, 444,20);
        delay(200);
        //tone(8, 444,20);
        delay(200);
        //tone(8, 444,20);
        delay(200);
        incomingByte = 'q';
        break;
    }   
  }
}

void playSong()
{
  for(int tmp = 0; tmp < 10; tmp++ )
  {
    //Serial.println("playing song");
    tone(speaker, currentSongnotes[tmp], currentSongbeats[tmp]);
    delay(currentSongbeats[tmp]+2);
  }
  incomingByte = 'q';
}

