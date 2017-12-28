//Video wala code
//Post request -> Bot aligning itself -> Covering the distance. Repeat until reaches the destination(counterForProduct).
String y;
int yaw;
String recv,imp_data,value1Str,value2Str;
int pos = 10 , orientation= -45 ,posReplied=0,orientationReplied=-60;
const int m1pwm = 2; //right
const int m1dir = 24;
const int m2pwm = 3; //left
const int m2dir = 22;

int aye = 0;
int ayeProduct = 0;
int anotherFlagg = true;

const int numberOfProduct = 5;
const int Array[5] = {2,1,2,1,2};  
int CounterForProduct = 3;


const int lenn = 22+34;
int globali;
bool isError = false;
//byte StartModule();
//void IMU();
//void forward();
//void stopCart();
//void align();
//void stopCart();

int bytes_to_send;

#define SSID        "nx"
#define PASS        "nextlevel12"

#define URL        "192.168.43.111"
#define PORT       8080

#define MAX_SERVER_CONNECT_ATTEMPTS 5

char buffer[1024];
String nm[10];
String strength[10];
int i , globlai;

char OKrn[] = "OK\r\n";
void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
  Serial3.begin(115200);
  pinMode(m1pwm, OUTPUT);
  pinMode(m1dir, OUTPUT);
  pinMode(m2pwm, OUTPUT);
  pinMode(m2dir, OUTPUT);
  
  while (!StartModule()) {
    delay(1000);
    Serial.println(F("***Calling StartModule Again***"));
  } 
  cwlap_post();
  aye++;
  //cwlap_post();
}
byte wait_for_esp_response(int timeout, char* term = OKrn, bool printFlag = false)
{
  unsigned long t = millis();
  bool found = false;
  int i = 0;
  int len = strlen(term);

  while (millis() < t + timeout) {
    if (Serial1.available()) {
      buffer[i++] = Serial1.read();
      if (i >= len) {
        if (strncmp(buffer + i - len, term, len) == 0) {
          found = true;
          break;
        }
      }
    }
  }
  buffer[i] = 0;
  if(printFlag)
    Serial.println(buffer);
  return found;
}

byte wait_for_esp_ack(int timeout, char* term = OKrn)
{
  unsigned long t = millis();
  bool found = false;
  int i = 0;
  int len = strlen(term);

  while (millis() < t + timeout) 
  {
    if (Serial1.available()) 
    {
      buffer[i++] = Serial1.read();
      if (i >= len) 
      {
        if (strncmp(buffer + i - len, term, len) == 0) 
        {
          found = true;
          break;
        }
      }
    }
  }
  
  buffer[i] = 0;
  recv=String(buffer);
  Serial.println(recv);
  
 // imp_data=recv.substring(239,247);
  imp_data = recv.substring(recv.length()-22, recv.length()-14);

// Serial.println("IMP DATA: "+imp_data);
  
  value1Str=imp_data.substring(0,4);
  value2Str=imp_data.substring(4,8);
  Serial.println("Value 1 String :"+value1Str);
  Serial.println("Value 2 String :"+value2Str);
  pos=value1Str.toInt();
//  if(posReplied > 1000)
//  {
//    posReplied = posReplied-1000;
//    posReplied = posReplied*-1;
//  }
  orientationReplied=value2Str.toInt();
//  if(orientationReplied > 1000)
//  {
//    orientationReplied = orientationReplied - 1000;
//    orientationReplied = orientationReplied*-1;
//  }
  Serial.println(pos);
  Serial.println(orientationReplied);
  return found;
}

byte parseAP(int timeout, char* term = OKrn)
{
  unsigned long t = millis();
  bool found = false;
  i = 0;
  int len = strlen(term);
  //bytes_to_send = 0;
  while (millis() < t + timeout) 
  {
    if (Serial1.available()) 
    {
      buffer[i++] = Serial1.read();
      if (i >= len) 
      {
        if (strncmp(buffer + i - len, term, len) == 0) 
        {
          found = true;
          break;
        }
      }
    }
  }
  
  buffer[i] = 0;
  recv=String(buffer);
  len = recv.length();

  //Serial.println("recv: ");
  //Serial.println(recv);
  i = 0;
  
  if(recv.startsWith("AT+CWLAP"))  {
    String kataHua = recv.substring(11, len);
    isError = false;
    while(kataHua.startsWith("+CWLAP:("))  {
      int start = kataHua.indexOf(",");
      int khatam = kataHua.indexOf(",", start+1 );
      //nm[i] = kataHua.substring(start+1, khatam);
      String temp = kataHua.substring(start+2, khatam-1);
      if(temp == "nx" || temp == "yx" || temp == "ax")  {
        nm[i] = temp; 
//        Serial.println(nm[i]);
        int khatam2 = kataHua.indexOf(",", khatam+1);      
        strength[i] = kataHua.substring(khatam+1, khatam2);
        i++;
      }
      
      int indexOfBracket = kataHua.indexOf(")");
      kataHua = kataHua.substring(indexOfBracket+3, len);
      //Serial.println("kataHua");
//      Serial.println(kataHua);
      }
  
      
      globali=i;
      //Serial.println("globali");
      //Serial.println(globali);
      i--;
      
    //tempK +=   recv.substring(15, 40);
    while(i>=0) {
      Serial.println("-------------------------------------------");
      Serial.print("nm: ");
      Serial.println(nm[i]);
      Serial.print("strength: ");
      Serial.println(strength[i]);
      i--;
    }
    i=0;
    while(i<globali)
    {
      bytes_to_send += nm[i].length();
      bytes_to_send += strength[i].length();
      
      i++;
    }
  }  
  else  {
     isError = true;
     Serial.println("error detected");
     
  }
  return found;
}
void loop()
{
  //pos *= 100; 
  while(ayeProduct < numberOfProduct)
  {
    CounterForProduct = Array[ayeProduct];
  while(aye<=CounterForProduct)
  {
  IMU();
  if(yaw <= orientationReplied+5  && yaw > orientationReplied-5)
  {
    forward();
    
    stopCart();
  }
  else
  {
    align();
    forward();
    stopCart();
  }
//  pos /= 100;
//  anotherFalgg = 1;
//if(aye<=CounterForProduct)
    { cwlap_post(); }

    aye++;
    Serial.print("aye");
    Serial.println(aye);
  }
 aye = 0; 
 ayeProduct++;
 }
} 
