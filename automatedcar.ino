#include<Servo.h>
Servo leftServo;
Servo rightServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  leftServo.attach(13);
  rightServo.attach(11);
  float* out = new float[2];
  Serial.print("1,0: ");
  Serial.println(run(1,0,out)[0]);
  Serial.println(run(1,0,out)[1]);
  

  
}

void loop() {
  // put your main code here, to run repeatedly:
  float* out = new float[2];
  leftServo.attach(13);
  rightServo.attach(11);
  Serial.print("reading left");
  Serial.println(volts(3));
  Serial.print("reading right");
  Serial.println(volts(2));
  run(volts(3),volts(2),out);
  if(out[0]>95 && out[1]<85){
     Serial.println("Went Straight");
  }else if(out[0] > 95){
    Serial.println("Turned Right");
  }else{
    Serial.println("Turned Left");
  };

  Serial.print("bp.Train(");//generate bp.Train examples
  Serial.print(volts(3));
  Serial.print(",");                  
  Serial.print(volts(2));
   
  leftServo.write(out[0]);
  rightServo.write(out[1]);
  Serial.print("\nleft out: ");
  Serial.println(out[0]);
  Serial.print("right out: ");
  Serial.println(out[1]);
  delay(100);
  Serial.println("\n");
  leftServo.detach();
  rightServo.detach();
  delay(700);
  

}

float volts(int adPin)                       // Measures volts at adPin
{                                            // Returns floating point voltage
 return float(analogRead(adPin));// * 5.0 / 1024.0;
}

float* out = new float[2];

float Sigmoid(float num) {
  return (float)(1/(1+exp(-num)));
}


float* run(float i1, float i2, float* out){
  float net1, net2, i3, i4;
  const float m_fWeights[3][4] = 
/* place array of weights below   here */
{{-0.633278,-3.05979,0.0371301,-0.253077,},
{-1.26814,1.25544,0.388935,0.160511,},
{-1.325,-0.861953,0.175613,0.280976,},
};
/*^^^ place array of weights here ^^^*/

  i1/=5;
  i2/=5;
  
  net1 = 1 * m_fWeights[0][0] + i1 * m_fWeights[1][0] +
      i2 * m_fWeights[2][0];
  net2 = 1 * m_fWeights[0][1] + i1 * m_fWeights[1][1] +
      i2 * m_fWeights[2][1];

  i3 = Sigmoid(net1);
  i4 = Sigmoid(net2);

  net1 = 1 * m_fWeights[0][2] + i3 * m_fWeights[1][2] +
        i4 * m_fWeights[2][2];
  net2 = 1 * m_fWeights[0][3] + i3 * m_fWeights[1][3] +
        i4 * m_fWeights[2][3];
  
  out[0] = Sigmoid(net1)*180;
  out[1] = Sigmoid(net2)*180;
  return out;
}
