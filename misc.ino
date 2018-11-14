void check_one_or_more_free(){
  // TODO: BLUE IF ALL UNKNOWN
  // Sets the light according to occupancy status
  
  boolean one_or_more_free = false;
  boolean one_or_more_occupied = false;
  
  for(int toilet_index=0; toilet_index<TOILET_COUNT; toilet_index++){
    if(toilets_occupany[toilet_index] == 0){
      one_or_more_free = true;
    }
    else if(toilets_occupany[toilet_index] == 1){
      one_or_more_occupied = true;
    }
  }

  if(one_or_more_free){
    LED_set(0,255,0,0,0); // Green
  }
  else if(one_or_more_occupied){
    LED_set(255,0,0,0,0); // Red
  }
  else {
    LED_set(0,0,255,0,0); // Blue
  }
}

void init_array(){
  for(int toilet_index=0; toilet_index<TOILET_COUNT; toilet_index++){
    toilets_occupany[toilet_index] = -1;
  }
}

void party(){

  long now = millis();
  
  if(now - party_start_time < PARTY_DURATION){
    // The party is ongoing
    if(!party_ongoing){
      // Acknowledge that the party is ongoing
      party_ongoing = true;
    }
    if(now - party_last_color_change > PARTY_COLOR_CHANGE_PERIOD){
      // The light has stayed a certain color for too long
      // Acknowledge it
      party_last_color_change = now;

      // Change the color
      LED_set(random(0, 255),random(0, 255),random(0, 255),0,0);
    }
  }
  else  {
    // The time has come, the party is over :(
    if(party_ongoing){
      // Acknowledge that the party is over
      party_ongoing = false;
      
      // resore the previous light state
      check_one_or_more_free();
    }
  }  
}

