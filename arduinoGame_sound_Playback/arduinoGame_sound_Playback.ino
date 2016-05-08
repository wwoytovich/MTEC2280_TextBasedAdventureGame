////////////////////////////////
///////declarations////////////
///////////////////////////////////
#include "pitches.h"
int qN = 50;
int hN = 100;

int trapRoomBeats[10] = {150,200,150,150,750,50,50,50,50,50};
int trapRoomNotes[10] = {NOTE_GS4,NOTE_G4,NOTE_FS4,NOTE_AS4,NOTE_FS4,NOTE_DS4,0,0,0,0};


int introSongBeats[10] = {100,200,300,400,500,600,700,800,900,1000};
int introSongNotes[10] = {100,200,300,400,500,600,700,800,900,1000};


int monsterRoomBeats[10] = {100,200,300,400,500,600,700,800,900,1000};
int monsterRoomNotes[100] = {100,200,300,400,500,600,700,800,900,1000};


int nothingRoomBeats[10] = {100,200,300,400,500,600,700,800,900,1000};
int nothingRoomNotes[100] = {100,200,300,400,500,600,700,800,900,1000};


int youDiedBeats[10] = {100,200,300,400,500,600,700,800,900,1000};
int youDiedNotes[10] = {100,200,300,400,500,600,700,800,900,1000};


int newLevelBeats[10] = {100,200,300,400,500,600,700,800,900,1000};
int newLevelNotes[10] = {100,200,300,400,500,600,700,800,900,1000};


int rareEncounterBeats[10] = {100,200,300,400,500,600,700,800,900,1000};
int rareEncounterNotes[10] = {100,200,300,400,500,600,700,800,900,1000};


int healthRoomBeats[10] = {100,200,300,400,500,600,700,800,900,1000};
int healthRoomNotes[10] = {100,200,300,400,500,600,700,800,900,1000};


int takeDamageBeats[10] = {100,200,300,400,500,600,700,800,900,1000};
int takeDamageNotes[100] = {100,200,300,400,500,600,700,800,900,1000};


int winSongBeats[10] = {100,200,300,400,500,600,700,800,900,1000};
int winSongNotes[10] = {100,200,300,400,500,600,700,800,900,1000};
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
    Serial.print("I received: ");
    Serial.println(incomingByte);
    switch(char(incomingByte))
    {
      case 't': //trap room
          for(int i = 0 ; i < 9 ; i++ )
        {
          currentSongnotes[i] = trapRoomNotes[i];
          currentSongbeats[i] = trapRoomBeats[i];
        }
        playSong();
        incomingByte = 'q';
        //Serial.println("playing trap room song");
        //tone(8, 1000, 100);
        break;
        
      case 'i': //intro song
        for(int i = 0 ; i < 9 ; i++ )
        {
          currentSongnotes[i] = introSongNotes[i];
          currentSongbeats[i] = introSongBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;
        
      case 'm': //monster room
        for(int i = 0 ; i < 9 ; i++ )
        {
          currentSongnotes[i] = monsterRoomNotes[i];
          currentSongbeats[i] = monsterRoomBeats[i];
        } 
        playSong(); 
        incomingByte = 'q';
        break;
        
      case 'k': // you die (are killed)
        for(int i = 0 ; i < 9 ; i++ )
        {
          currentSongnotes[i] = youDiedNotes[i];
          currentSongbeats[i] = youDiedBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;
        
      case 'l': // new level
        for(int i = 0 ; i < 9 ; i++ )
        {
          currentSongnotes[i] = newLevelNotes[i];
          currentSongbeats[i] = newLevelBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;
        
      case 'r':
        for(int i = 0 ; i < 9 ; i++ )
        {
          currentSongnotes[i] = rareEncounterNotes[i];
          currentSongbeats[i] = rareEncounterBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;
        
      case 'h':
        for(int i = 0 ; i < 9 ; i++ )
        {
          currentSongnotes[i] = healthRoomNotes[i];
          currentSongbeats[i] = healthRoomBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;

      case 'w':
        for(int i = 0 ; i < 9 ; i++ )
        {
          currentSongnotes[i] = winSongNotes[i];
          currentSongbeats[i] = winSongBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;

      case 'd': // take damage
        for(int i = 0 ; i < 9 ; i++ )
        {
          currentSongnotes[i] = takeDamageNotes[i];
          currentSongbeats[i] = takeDamageBeats[i];
        }
        playSong();
        incomingByte = 'q';
        break;

      default:
        tone(8, 444,20);
        delay(200);
        tone(8, 444,20);
        delay(200);
        tone(8, 444,20);
        delay(200);
        incomingByte = 'q';
        break;
    }   
  }
}

void playSong()
{
  for(int tmp = 0; tmp < 9; tmp++ )
  {
    Serial.println("playing song");
    tone(speaker, currentSongnotes[tmp], currentSongbeats[tmp]);
    delay(currentSongbeats[tmp]+2);
  }
  incomingByte = 'q';
}

