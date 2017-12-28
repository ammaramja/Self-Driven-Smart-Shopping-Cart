void forward()  {
    Serial.println("forward");
    analogWrite(m1pwm, 70);
    digitalWrite(m1dir, LOW);
    analogWrite(m2pwm, 70);
    digitalWrite(m2dir, HIGH);
    delay(pos);
}
void clockwise()  {
    analogWrite(m1pwm, 70);
    digitalWrite(m1dir, HIGH);
    analogWrite(m2pwm, 70);
    digitalWrite(m2dir, HIGH);
}
void anticlockwise()  {
  Serial.println("AntiClockwise");
    analogWrite(m1pwm, 70);
    digitalWrite(m1dir, LOW);
    analogWrite(m2pwm, 70);
    digitalWrite(m2dir, LOW);
   
}

void stopCart()  {
    analogWrite(m1pwm, 0);
    analogWrite(m2pwm, 0);
    
}

