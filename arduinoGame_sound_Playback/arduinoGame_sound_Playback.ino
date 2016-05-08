////////////////////////////////
///////declarations////////////
///////////////////////////////////

int trapRoomBeats[30] = {};
int trapRoomNotes[30] = {};


int introSongBeats[30] = {};
int introSongNotes[30] = {};


int monsterRoomBeats[30] = {};
int monsterRoomNotes[30] = {};


int nothingRoomBeats[30] = {};
int nothingRoomNotes[30] = {};


int youDiedBeats[30] = {};
int youDiedNotes[30] = {};


int newLevelBeats[30] = {};
int newLevelNotes[30] = {};


int rareEncounterBeats[30] = {};
int rareEncounterNotes[30] = {};


int healthRoomBeats[30] = {};
int healthRoomNotes[30] = {};


int takeDamageBeats[30] = {};
int takeDamageNotes[30] = {};


int winSongBeats[30] = {};
int winSongNotes[30] = {};
/////////////////////////////////////
///////////////////////////////////////
/////////////////////////////////////
// shit why does this not work in a different tab?
/////////////////////////
/////////////////
////////////////////////
////////////////////



int speaker = 8; //speaker connected to pin 8
char incomingByte;   // for incoming serial data
char english; // for using a char to compare to
String currentSongnotes; // songsnote name array
String currentSongbeats; // name of song beat array
String currentSongLen; // name of song length int


void setup() 
{
  Serial.begin(9600); 
}

void loop() 
{
  readinput();
  playSong();
}


void readinput()
{
  if (Serial.available() > 0) 
  {
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte);
    switch(incomingByte)
    {
      case 't': //trap room
          for(int i = 0 ; i < 30 ; i++ )
          {
            currentSongnotes[i] = trapRoomNotes[i];
            currentSongbeats[i] = trapRoomBeats[i];
          }
        break;
        
      case 'i': //intro song
        for(int i = 0 ; i < 30 ; i++ )
          {
            currentSongnotes[i] = introSongNotes[i];
            currentSongbeats[i] = introSongBeats[i];
          }
        break;
        
      case 'm': //monster room
        for(int i = 0 ; i < 30 ; i++ )
          {
            currentSongnotes[i] = monsterRoomNotes[i];
            currentSongbeats[i] = monsterRoomBeats[i];
          }  
        break;
        
      case 'k': // you die (are killed)
        for(int i = 0 ; i < 30 ; i++ )
          {
            currentSongnotes[i] = youDiedNotes[i];
            currentSongbeats[i] = youDiedBeats[i];
          }
        break;
        
      case 'l': // new level
        for(int i = 0 ; i < 30 ; i++ )
          {
            currentSongnotes[i] = newLevelNotes[i];
            currentSongbeats[i] = newLevelBeats[i];
          }
        break;
        
      case 'r':
        for(int i = 0 ; i < 30 ; i++ )
          {
            currentSongnotes[i] = rareEncounterNotes[i];
            currentSongbeats[i] = rareEncounterBeats[i];
          }
        break;
        
      case 'h':
        for(int i = 0 ; i < 30 ; i++ )
          {
            currentSongnotes[i] = healthRoomNotes[i];
            currentSongbeats[i] = healthRoomBeats[i];
          }
        break;

      case 'w':
        for(int i = 0 ; i < 30 ; i++ )
          {
            currentSongnotes[i] = winSongNotes[i];
            currentSongbeats[i] = winSongBeats[i];
          }
        break;

      case 'd': // take damage
        for(int i = 0 ; i < 30 ; i++ )
          {
            currentSongnotes[i] = takeDamageNotes[i];
            currentSongbeats[i] = takeDamageBeats[i];
          }
        break;

      default:
        for(int i = 0 ; i < 30 ; i++ )
          {
            currentSongnotes[i] = nothingRoomNotes[i];
            currentSongbeats[i] = nothingRoomBeats[i];
          }
        break;
    }   
  }
}

void playSong()
{
  if(incomingByte == 'x')
  {
    for(int i = 0; i < currentSongLen[i]; i++ )
    {
      tone(speaker, currentSongnotes[i], currentSongbeats[i]);
    }
  }
}

