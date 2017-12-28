void cwlap_post()
{
  /*
  unsigned long int t = millis();  
  while(millis()<t+pos)
  {
      forward(); 
  }
    stopCart();
  */
  //+((globali-1)*14);
  if(aye == CounterForProduct || aye == 0)  
  {
  bytes_to_send = 24+35+13+5+1+5+1;  
  buffer[0] = '\0';
  Serial1.println("AT+CWLAP");
  Serial.println("AT+CWLAP sent************************************");
  parseAP(9000);
  bytes_to_send += ((globali-1)*14);
  }
  else{
    bytes_to_send = 24+35+5+6;
  }
  if(!isError)  {
  
    Serial1.print("AT+CIPSEND=");
    Serial1.println(bytes_to_send);

    if (!wait_for_esp_response(9000, "> ", true)) {
      Serial1.println("AT+CIPCLOSE");
      Serial.println("send timeout - resetting wifi module");
      delay(1000);
      
      if(!ConnectToXampp()) 
        StartModule();
        cwlap_post();
    }
    else
    { 
      if(aye == 0 || aye == CounterForProduct)
      {
        Serial1.print("POST /project/index.php?");
        Serial.print("POST /project/index.php?");
        int j = 0;
      while(j<globali)
      {
        if(j==0)
          Serial1.print("SSID" + String(j) + "=" + nm[j] + "&RSSI" + String(j) + "=" + strength[j] +"&ACK" + "=" + String(aye) +"&PRO" + "=" + String(ayeProduct));
        else
          Serial1.print("&SSID" + String(j) + "=" + nm[j] + "&RSSI" + String(j) + "=" + strength[j]);
        j++;
      }
      Serial1.print(" HTTP/1.1\r\nHost: 192.168.43.111\r\n\r\n");
      Serial.print(" HTTP/1.1\r\nHost: 192.168.43.111\r\n\r\n");
      wait_for_esp_ack(9000,"Data Received\n");
      delay(1000);
      }
      else
      {
        Serial1.print("POST /project/index.php?");
        //Serial.print("POST /project/index.php?");
          Serial1.print("ACK=" + String(aye) + "&PRO" + "=" + String(ayeProduct));
        
      Serial1.print(" HTTP/1.1\r\nHost: 192.168.43.111\r\n\r\n");
      //Serial.print(" HTTP/1.1\r\nHost: 192.168.43.111\r\n\r\n");
      wait_for_esp_ack(9000,"Data Received\n");
      delay(1000);
      }
    }
  }
  else // agar error aye toh i.e first time wala parsig error
  {
    cwlap_post();
  }
}
