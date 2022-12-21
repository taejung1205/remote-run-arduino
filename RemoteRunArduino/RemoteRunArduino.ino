// #include <LedControl.h>

unsigned long last_time = 0;
#define TRIG_1 10 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO_1 7 //ECHO 핀 설정 (초음파 받는 핀)
#define TRIG_2 9 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO_2 8 //ECHO 핀 설정 (초음파 받는 핀)

// LedControl LEDMatrix = LedControl(4, 3, 5, 1);
// DIN - PIN 4번
// CS - PIN 5번
// CLK - PIN 3번

//byte led[16][8] = {
//  {
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//  },
//  {
//    B10000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//  },
//  {
//    B01000000,
//    B10000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//  },
//  {
//    B00100000,
//    B01000000,
//    B10000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//  },
//  {
//    B00010000,
//    B00100000,
//    B01000000,
//    B10000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//  },
//  {
//    B00001000,
//    B00010000,
//    B00100000,
//    B01000000,
//    B10000000,
//    B00000000,
//    B00000000,
//    B00000000,
//  },
//  {
//    B00000100,
//    B00001000,
//    B00010000,
//    B00100000,
//    B01000000,
//    B10000000,
//    B00000000,
//    B00000000,
//  },
//  {
//    B00000010,
//    B00000100,
//    B00001000,
//    B00010000,
//    B00100000,
//    B01000000,
//    B10000000,
//    B00000000,
//  },
//  {
//    B00000001,
//    B00000010,
//    B00000100,
//    B00001000,
//    B00010000,
//    B00100000,
//    B01000000,
//    B10000000,
//  },
//  {
//    B00000000,
//    B00000001,
//    B00000010,
//    B00000100,
//    B00001000,
//    B00010000,
//    B00100000,
//    B01000000,
//  },
//  {
//    B00000000,
//    B00000000,
//    B00000001,
//    B00000010,
//    B00000100,
//    B00001000,
//    B00010000,
//    B00100000,
//  },
//  {
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000001,
//    B00000010,
//    B00000100,
//    B00001000,
//    B00010000,
//  },
//  {
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000001,
//    B00000010,
//    B00000100,
//    B00001000,
//  },
//  {
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000001,
//    B00000010,
//    B00000100,
//  },
//  {
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000001,
//    B00000010,
//  },
//  {
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000000,
//    B00000001,
//  }
//};

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_1, OUTPUT);
  pinMode(ECHO_1, INPUT);
  pinMode(TRIG_2, OUTPUT);
  pinMode(ECHO_2, INPUT);
//  LEDMatrix.shutdown(0, false);  // 절전모드로 (첫번째 모듈, 절전모드를 하지 않는다) 설정
//  LEDMatrix.setIntensity(0, 7);  // 밝기를 조절 (첫번째 모듈, 1~15까지 원하는 밝기) 설정
//  LEDMatrix.clearDisplay(0);     // LED를 초기화 설정 (첫번째 모듈)
}
void loop()
{

  double duration_1, duration_2;
  double distance_1, distance_2;

  digitalWrite(TRIG_1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_1, LOW);
  duration_1 = pulseIn (ECHO_1, HIGH);

  digitalWrite(TRIG_2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_2, LOW);
  duration_2 = pulseIn (ECHO_2, HIGH);
  //물체에 반사되어돌아온 초음파의 시간을 변수에 저장합니다.
  //34000*초음파가 물체로 부터 반사되어 돌아오는시간 /1000000 / 2(왕복값이아니라 편도값이기때문에 나누기2를 해줍니다.)

  //초음파센서의 거리값이 위 계산값과 동일하게 Cm로 환산되는 계산공식 입니다. 수식이 간단해지도록 적용했습니다.

  distance_1 = duration_1 * 17 / 1000.0;
  distance_2 = duration_2 * 17 / 1000.0;

  //Serial.println("Hello");
  String result = String(distance_1, 4) + " " + String(distance_2, 4);

  Serial.println(result);
  // setLED(distance_1 - distance_2);

  delay(100); //1초마다 측정값을 보여줍니다.
}

//void setLED(double dir) {
//  //-19.5 ~ 19.5
//  if (dir < -19.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[1][j]);
//    }
//  } else if (dir >= -19.5 && dir < -16.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[2][j]);
//    }
//  } else if (dir >= -16.5 && dir < -13.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[3][j]);
//    }
//  } else if (dir >= -13.5 && dir < -10.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[4][j]);
//    }
//  } else if (dir >= -10.5 && dir < -7.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[5][j]);
//    }
//  } else if (dir >= -7.5 && dir < -4.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[6][j]);
//    }
//  } else if (dir >= -4.5 && dir < -1.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[7][j]);
//    }
//  } else if (dir >= -1.5 && dir < 1.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[8][j]);
//    }
//  } else if (dir >= 1.5 && dir < 4.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[9][j]);
//    }
//  } else if (dir >= 4.5 && dir < 7.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[10][j]);
//    }
//  } else if (dir >= 7.5 && dir < 10.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[11][j]);
//    }
//  } else if (dir >= 10.5 && dir < 13.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[12][j]);
//    }
//  } else if (dir >= 13.5 && dir < 16.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[13][j]);
//    }
//  } else if (dir >= 16.5 && dir < 19.5) {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[14][j]);
//    }
//  } else {
//    for (int j = 0; j < 8; j++) {
//      LEDMatrix.setRow(0, j, led[15][j]);
//    }
//  }
//}
