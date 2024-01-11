#include <Arduino.h>
#include "config.h"
#include "DFRobot_AirQualitySensor.h"


#define I2C_ADDRESS    0x19
  DFRobot_AirQualitySensor particle(&Wire ,I2C_ADDRESS);

void setup() {
  Serial.begin(115200);
/**
  Sensor initialization is used to initialize IIC, which is determined by the communication mode used at this time.
*/
  while(!particle.begin())
  {
    Serial.println("NO PM2.5 air quality sensor Found !");
    delay(1000);
  }
  Serial.println("PM2.5 air quality sensor Found!");
  delay(1000);
/**
  Get sensor version number
*/
  uint8_t version = particle.gainVersion();
  Serial.print("version is : ");
  Serial.println(version);
  delay(1000);
}

void loop() {

/**
 *@brief : Get concentration of PM1.0 
 *@param :PARTICLE_PM1_0_STANDARD  Standard particle 
          PARTICLE_PM2_5_STANDARD  Standard particle
          PARTICLE_PM10_STANDARD   Standard particle  
          PARTICLE_PM1_0_ATMOSPHERE  In atmospheric environment
          PARTICLE_PM2_5_ATMOSPHERE  In atmospheric environment
          PARTICLE_PM10_ATMOSPHERE   In atmospheric environment
*/  
  uint16_t PM2_5 = particle.gainParticleConcentration_ugm3(PARTICLE_PM2_5_ATMOSPHERE );
  uint16_t PM1_0 = particle.gainParticleConcentration_ugm3(PARTICLE_PM1_0_ATMOSPHERE );
  uint16_t PM10 = particle.gainParticleConcentration_ugm3(PARTICLE_PM10_ATMOSPHERE);
  uint16_t pnum = particle.gainParticleNum_Every0_1L(PARTICLENUM_0_3_UM_EVERY0_1L_AIR);
  Serial.print("The number of particles with a diameter of 0.3um per 0.1 in lift-off is: ");
  Serial.println(pnum);
  Serial.print("PM2.5 concentration:");
  Serial.print(PM2_5);
  Serial.println(" ug/m3");
  Serial.print("PM1.0 concentration:");
  Serial.print(PM1_0);
  Serial.println(" ug/m3");
  Serial.print("PM10 concentration:");
  Serial.print(PM10);
  Serial.println(" ug/m3");
  Serial.println(DBAR);
  delay(3000);
}