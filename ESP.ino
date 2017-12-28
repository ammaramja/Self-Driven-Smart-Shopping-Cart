byte StartModule()
{
  bool module_responding =  false;
  bool connected_to_access_point = false; 
  Serial.println("Starting module");

  while(!module_responding){
  
    Serial1.println("AT+RST");
    
  
    if (wait_for_esp_response(5000, "OK",false)){
      Serial.println("Module is responding");
      module_responding = true;
    }
    else{
      Serial.println("Module not responding to reset");
      delay(1000);
    }
  }
    
  Serial.println(F("Connecting to WiFi access point..."));
  
  String cmd = "AT+CWJAP=\"";
  cmd += SSID;
  cmd += "\",\"";
  cmd += PASS;
  cmd += "\"";
  
  Serial.println(cmd);
  Serial1.println(cmd);
  
  connected_to_access_point = wait_for_esp_response(9000,"GOT IP", false);
  
  if(!connected_to_access_point){
    Serial.println(F("Attempt to connect to access point failed. Restarting module."));
    return false; 
  }
  else
  {
    Serial.println(F("CONNECTED TO ACCESS POINT"));
  }

  bool connected_to_xampp = false;
  int connection_attempts = 0;
  Serial.println(F("Connecting to XAMPP..."));
  while((!connected_to_xampp)&&(connection_attempts < MAX_SERVER_CONNECT_ATTEMPTS)){
    cmd = "AT+CIPSTART=\"TCP\",\"";
    cmd += URL;
    cmd += "\",";
    cmd += PORT;
    Serial1.println(cmd);
    connected_to_xampp = wait_for_esp_response(9000,"CONNECTED", false);
    connection_attempts += 1;
    
  }
  return connected_to_xampp;
}

byte ConnectToXampp()
{
  String cmd;
//  bool module_responding =  false;
//  bool connected_to_access_point = false; 
  Serial.println("ReEstablishing Connection with the Server");

//  while(!module_responding){
//  
//    Serial1.println("AT+RST");
//    
//  
//    if (wait_for_esp_response(5000, "OK")){
//      Serial.println("Module is responding");
//      module_responding = true;
//    }
//    else{
//      Serial.println("Module not responding to reset");
//      delay(1000);
//    }
//  }
    
//  Serial.println(F("Connecting to WiFi access point..."));
//  
//  String cmd = "AT+CWJAP=\"";
//  cmd += SSID;
//  cmd += "\",\"";
//  cmd += PASS;
//  cmd += "\"";
//  
//  Serial.println(cmd);
//  Serial1.println(cmd);
// 
//  connected_to_access_point = wait_for_esp_response(9000,"GOT IP");
//    if(!connected_to_access_point){
//    Serial.println(F("Attempt to connect to access point failed. Restarting module."));
//    return false; 
//  }
//  else
//  {
//    Serial.println(F("CONNECTED TO ACCESS POINT"));
//  }

  bool connected_to_xampp = false;
  int connection_attempts = 0;
  while((!connected_to_xampp)&&(connection_attempts < MAX_SERVER_CONNECT_ATTEMPTS)){
    cmd = "AT+CIPSTART=\"TCP\",\"";
    cmd += URL;
    cmd += "\",";
    cmd += PORT;
    Serial1.println(cmd);
    connected_to_xampp = wait_for_esp_response(9000,"CONNECTED",true);
    connection_attempts += 1;
    
  }
  return connected_to_xampp;
}
