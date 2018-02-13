 // скетч для вывода кватернионов в serial-порт
// для дальнейшего графического просмотра ориентации объекта
// в среде processing «MadgwickProcessingDraw9DOF.pde»
 
// библиотека для работы I²C
#include <Wire.h>
// библиотека для работы с модулями IMU
#include <TroykaIMU.h>
 
// множитель фильтра
#define BETA 0.22
 
// создаём объект для фильтра Madgwick
Madgwick filter;
 
// создаём объект для работы с акселерометром
Accelerometer accel;
// создаём объект для работы с гироскопом
Gyroscope gyro;
// создаём объект для работы с компасом
Compass compass;
 
// переменные для данных с гироскопа, акселерометра и компаса
float gx, gy, gz, ax, ay, az, mx, my, mz;
 
// получаемые углы ориентации (Эйлера)
float yaw, pitch, roll;
 
// переменная для хранения частоты выборок фильтра
float fps = 100;
 
// калибровочные значения компаса
// полученные в калибровочной матрице из примера «compassCalibrateMatrix»
const double compassCalibrationBias[3] = {
  601.967,
  -1261.978,
  2997.613
};
 
const double compassCalibrationMatrix[3][3] = {
  {1.436, 0.086, -0.011},
  {-0.016, 1.489, 0.039},
  {0.067, -0.005, 1.593}
};
 
void setup()
{
  // открываем последовательный порт
  Serial.begin(115200);
  // инициализация акселерометра
  accel.begin();
  // инициализация гироскопа
  gyro.begin();
  // инициализация компаса
  compass.begin();
  // калибровка компаса
  compass.calibrateMatrix(compassCalibrationMatrix, compassCalibrationBias);
}
 
void loop()
{
  // запоминаем текущее время
  unsigned long startMillis = millis();
  // считываем данные с акселерометра в единицах G
  accel.readGXYZ(&ax, &ay, &az);
  // считываем данные с гироскопа в радианах в секунду
  gyro.readRadPerSecXYZ(&gx, &gy, &gz);
  // считываем данные с компаса в Гауссах
  compass.readCalibrateGaussXYZ(&mx, &my, &mz);
  // устанавливаем коэффициенты фильтра
  filter.setKoeff(fps, BETA);
  // обновляем входные данные в фильтр
  filter.update(gx, gy, gz, ax, ay, az, mx, my, mz);
 
  if (Serial.available() > 0) {
    int val = Serial.read();
    // если пришёл символ 's'
    if (val == 's') {
      float q0, q1, q2, q3;
      filter.readQuaternions(&q0, &q1, &q2, &q3);
      // выводим кватернионы в serial-порт
      Serial.print(q0);
      Serial.print(",");
      Serial.print(q2);
      Serial.print(",");
      Serial.print(q1*-1);
      Serial.print(",");
      Serial.println(q3);
    }
  }
  // вычисляем затраченное время на обработку данных
  unsigned long deltaMillis = millis() - startMillis;
  // вычисляем частоту обработки фильтра
  fps = 1000 / deltaMillis;
}
