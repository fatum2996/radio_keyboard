#include <HID-Project.h>                    //include HID_Project library
#include <HID-Settings.h>
#include <RCSwitch.h>

long sendTemp = 0;

RCSwitch mySwitch = RCSwitch();

uint8_t allowButton = 0;

long onValue = 11356161; //ИЗМЕНИТЬ НА ЗНАЧЕНИЕ ОТ ПЕРВОЙ КНОПКИ

void setup() {
  Consumer.begin();                         //initialize computer connection
  delay(1000);  
  mySwitch.enableReceive(1);  // Receiver on interrupt 1 => that is pin #2  
  delay(2);
}

void loop() {  
  if (mySwitch.available()) {    
    sendTemp = mySwitch.getReceivedValue();     
    mySwitch.resetAvailable();
    delay(2);
  } 
  delay(2);
  if((allowButton < 255)){
      allowButton++;        
  }  
  if(sendTemp == onValue){
    if(allowButton ==255 ){
      Consumer.write(MEDIA_VOLUME_MUTE);      //set the volume to 0
      delay(2);     
      allowButton = 0;
    }
  }
  if(sendTemp == onValue+1){
  }
  if(sendTemp == onValue+2){
    if(allowButton ==255 ){   
      Consumer.write(MEDIA_PLAY_PAUSE);    
      delay(2);  
      allowButton = 0;
    } 
  }
  if(sendTemp == onValue+3){
  }  
  if(sendTemp == onValue+4){
    if(allowButton ==255 ){   
      Consumer.write(MEDIA_NEXT);  
      delay(2);       
      allowButton = 0;
    }
  }  
  if(sendTemp == onValue+5){
    Consumer.write(MEDIA_VOLUME_UP );   
    delay(2);   
  }    
  if(sendTemp == onValue+6){
  } 
  if(sendTemp == onValue+7){
    if(allowButton ==255 ){   
      Consumer.write(MEDIA_PREVIOUS);      
      delay(2);   
      allowButton = 0;
    }
  }   
  if(sendTemp == onValue+8){
    Consumer.write(MEDIA_VOLUME_DOWN );     
    delay(2);       
  }     
  if(sendTemp == onValue+9){
    Keyboard.press(KEY_LEFT_WINDOWS);
    Keyboard.press(KEY_L);
    Keyboard.releaseAll();
  }   
  if(sendTemp == onValue+10){
  }   
  if(sendTemp == onValue+11){
  }   
  if(sendTemp == onValue+12){
  }  
  if(sendTemp == onValue+13){
  }    
  if(sendTemp == onValue+14){
  }     
  if(sendTemp == onValue+15){
  }      
  if(sendTemp == onValue+16){
  }  
  if(sendTemp == onValue+17){
  }   
  if(sendTemp == onValue+18){
  }    
  if(sendTemp == onValue+19){
  }     
  if(sendTemp == onValue+20){
  }  
  sendTemp = 0;   
}
