void web_server_setup(){
  www_server.on("/", handle_root);
  www_server.on("/update_form", handle_update_form);
  www_server.on("/update",HTTP_POST, handle_update, handle_update_upload);
  www_server.on("/status_update", handle_status_update);
  www_server.on("/off", handleOff);
  www_server.begin();
}


void handle_root() {

  String root_main_v2 = "";

  for(int toilet_index=0; toilet_index<TOILET_COUNT; toilet_index++){
    root_main_v2 += String(toilets_occupany[toilet_index]) + "<br>";
  }
  
  String html = pre_main + root_main_v2 + post_main;

  
  www_server.sendHeader("Connection", "close");
  www_server.sendHeader("Access-Control-Allow-Origin", "*");
  www_server.send(200, "text/html", html);
  
}

void handle_update_form(){
  String html = pre_main + update_form + post_main;
  www_server.sendHeader("Connection", "close");
  www_server.sendHeader("Access-Control-Allow-Origin", "*");
  www_server.send(200, "text/html", html);
}

void handle_update(){

  String upload_status;
  if(Update.hasError()){
    upload_status = "Upload failed";
  }
  else {
    upload_status = "Upload success";
  }
  String html = pre_main + upload_status + post_main;
  www_server.sendHeader("Connection", "close");
  www_server.sendHeader("Access-Control-Allow-Origin", "*");
  www_server.send(200, "text/html", html);
  ESP.restart();
  
}

void handle_update_upload(){
  HTTPUpload& upload = www_server.upload();
  if(upload.status == UPLOAD_FILE_START){
    Serial.setDebugOutput(true);
    WiFiUDP::stopAll();
    Serial.printf("Update: %s\n", upload.filename.c_str());
    uint32_t maxSketchSpace = (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
    if(!Update.begin(maxSketchSpace)){//start with max available size
      Update.printError(Serial);
    }
  } else if(upload.status == UPLOAD_FILE_WRITE){
    if(Update.write(upload.buf, upload.currentSize) != upload.currentSize){
      Update.printError(Serial);
    }
  } else if(upload.status == UPLOAD_FILE_END){
    if(Update.end(true)){ //true to set the size to the current progress
      Serial.printf("Update Success: %u\nRebooting...\n", upload.totalSize);
    } else {
      Update.printError(Serial);
    }
    Serial.setDebugOutput(false);
  }
  yield();
}


void handle_status_update() {

  // The API

  // Check the request body for occupancy information
  if (www_server.hasArg("occupied")){

    int toilet_index = www_server.client().remoteIP()[3];
    
    if( www_server.arg("occupied").equals("1") ){
      toilets_occupany[toilet_index] = 1;
      
    }
    else if( www_server.arg("occupied").equals("0") ){
      toilets_occupany[toilet_index] = 0;
    }

    check_one_or_more_free();
  }

  // Might not be the right response
  String html = pre_main + "OK"+ post_main;
  www_server.send(200, "text/html", html);
  
}



void handleOff() {
  LED_set(0,0,0,0,0);

  String html = pre_main +"<h1>Lamp off</h1>"+ post_main;
  www_server.send(200, "text/html", html);
}
