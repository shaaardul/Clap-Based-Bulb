int soundsensor = 7;
int relay = 6;
int clap = 0;
long detection_range_start  = 0;
long detection_range = 0;
boolean status_lights = false;
 
void  setup() {
 pinMode(soundsensor, INPUT);
 pinMode(relay, OUTPUT);
}
void loop() {
  int status_sensor = digitalRead(soundsensor);
  if (status_sensor  == 1)
  {
    if (clap == 0)
    {
      detection_range_start = detection_range  = millis();
      clap++;
    }
    else if (clap > 0 && millis()-detection_range  >= 50)
    {
      detection_range = millis();
      clap++;
    }
  }
  if (millis()-detection_range_start >= 400)
  {
    if (clap == 2)
    {
      if (!status_lights)
        {
          status_lights = true;
          digitalWrite(relay, HIGH);
        }
        else if (status_lights)
        {
          status_lights = false;
          digitalWrite(relay, LOW);
        }
    }
    clap = 0;
  }
}