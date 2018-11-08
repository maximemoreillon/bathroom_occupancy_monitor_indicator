void check_one_or_more_free(){

  boolean one_or_more_free = false;

  for(int toilet_index=0; toilet_index<TOILET_COUNT; toilet_index++){
    if(toilets_occupany[toilet_index] == 0){
      one_or_more_free = true;
    }
  }

  if(one_or_more_free){
    LED_set(0,255,0,0,0); // Green
    toilet_occupied = 0;
  }
  else {
    LED_set(255,0,0,0,0); // Red
    toilet_occupied = 1;
  }
}

void init_array(){
  for(int toilet_index=0; toilet_index<TOILET_COUNT; toilet_index++){
    toilets_occupany[toilet_index] = -1;
  }
}


