#include<stdio.h>
#include<math.h>

int getHeartRate(int,short *);
void presentHeartRate(unsigned short);
void prepareHeartRate(int,unsigned short *);
int bitRead(unsigned short ,int);
void bitSet(unsigned short *,int);
void bitClear(unsigned short *,int);
void printAsBinary(unsigned short);

void main(){
     int heartBPM;
     printf("Input the data for user heart rate in beats per minute.\n");
     scanf("%d",&heartBPM);
     unsigned short heartRate;
     int sensorFunction=getHeartRate(heartBPM,&heartRate);
     prepareHeartRate(sensorFunction,&heartRate);
     presentHeartRate(heartRate);
}

//to print the heart Rate ouput
void presentHeartRate(unsigned short heartRate){
     int deviceReading=bitRead(heartRate,0);
     int sensorReset=bitRead(heartRate,1);
     int abnormalReading=bitRead(heartRate,2);
     int volumeOfHeartRate=bitRead(heartRate,11)+bitRead(heartRate,12)*2;
     int parity=bitRead(heartRate,15);
     
     printf("Heart Rate Sensor Information:\n");
     printf("THe output of the heart rate sensor is 0x%4X = ",heartRate);
     printAsBinary(heartRate);
     printf("the value of bit 0 is %d which indicates the device is %s reading\n",deviceReading,deviceReading ? "incorrect":"correct");
     printf("the value of bit 1 is %d which indicates the sesor id %s to reset\n",sensorReset,sensorReset?"required":"not required");
     printf("the value of bit 2 is %d which indicates abnormal heart rate is %s\n",abnormalReading,abnormalReading ? "detacted":"not detacted");
     printf("the value of bits 3 to 10 is 0x%02X, which indicates the heart rate is %d bpm\n",(heartRate >> 3) & 0xFF,(heartRate >> 3) & 0xFF);
     if(volumeOfHeartRate==2){
       printf("The value of bits 11 to 12 is 2, which indicates a high heart rate.\n");
     }else{
       printf("The value of bits 11 to 12 is 3, which indicates a high heart rate.\n");
     }
     printf("the value of bit 15 is %d which indicates %s output \n",parity,parity ? "abnormal":"normal");
}

//prepare the heart rate according to sensor function
void prepareHeartRate(int sensorFunction,unsigned short *heartRate){
     if(sensorFunction==1){
       bitSet(heartRate,1);
       bitSet(heartRate,15);
     }else{
       int heartBPM= (*heartRate>>3)&0xFF;
       bitSet(heartRate,2);
       if(heartBPM<50){
         bitSet(heartRate,11);
         bitSet(heartRate,12);
       }else if(heartBPM>165){
         bitSet(heartRate,12);
       }
     }
}

//to get the sensor output
int getHeartRate(int heartBPM,short *heartRate){

   *heartRate=0;
   
   // Check if the heartBPM is within the legal range
    if (heartBPM < 0 || heartBPM > 255) {
        bitSet(heartRate,15);
        return 1;
    }

    *heartRate = (short)(heartBPM & 0xFF) << 3;

    return 0; // Request completed correctly
}

void bitSet(unsigned short *num,int pos){
    *num |=(1<<pos);
}

void bitClear(unsigned short *num , int pos){
    *num &= ~(1<<pos);
}

int bitRead(unsigned short num,int pos){
    return (num>>pos)&1;
}

//to print heartrate in binary format
void printAsBinary(unsigned short n) {
    for (int i=15; i>=0; i--) {
    if ((int)(n/pow(2,i)) > 0) {
     printf("1");
     n = n - pow(2,i);
    }
    else
     printf("0");
    }
    printf("\n");
}

