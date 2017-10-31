
// библиотека для работы I²C
#include <Wire.h>
// библиотека для работы с модулями IMU
#include <TroykaIMU.h>
 
// создаём объект для работы с гироскопом
Gyroscope gyro;
// создаём объект для работы с акселерометром
Accelerometer accel;
// создаём объект для работы с компасом
Compass compass;
// создаём объект для работы с барометром
Barometer barometer;
 
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
  // выводим сообщение о начале инициализации
  Serial.println("Begin init...");
  // инициализация гироскопа
  gyro.begin();
  // инициализация акселерометра
  accel.begin();
  // инициализация компаса
  compass.begin();
  // инициализация барометра
  barometer.begin();
  // калибровка компаса
  compass.calibrateMatrix(compassCalibrationMatrix, compassCalibrationBias);
  // выводим сообщение об удачной инициализации
  Serial.println("Initialization completed");
  Serial.println("Gyroscope\t\t\tAccelerometer\t\t\tCompass\t\tBarometer");
}
 
void loop()
{
  // вывод угловой скорости в градусах в секунду относительно оси X
  Serial.print(gyro.readDegPerSecX());
  Serial.print("\t");
  // вывод угловой скорости в градусах в секунду относительно оси Y
  Serial.print(gyro.readDegPerSecY());
  Serial.print("\t");
  // вывод угловой скорости в градусах в секунду относительно оси Z
  Serial.print(gyro.readDegPerSecZ());
  Serial.print("\t\t");
  // вывод направления и величины ускорения в м/с² по оси X
  Serial.print(accel.readAX());
  Serial.print("\t");
  // вывод направления и величины ускорения в м/с² по оси Y
  Serial.print(accel.readAY());
  Serial.print("\t");
  // вывод направления и величины ускорения в м/с² по оси Z
  Serial.print(accel.readAZ());
  Serial.print("\t\t");
  // выводим азимут относительно оси Z
  Serial.print(compass.readAzimut());
  Serial.print(" Degrees\t");
  // вывод значения абсолютного давления
  Serial.print(barometer.readPressureMillibars());
  Serial.print("\t");
  // вывод значения температуры окружающей среды
  Serial.print(barometer.readTemperatureC());
  Serial.print("\t");
  Serial.println("");
  delay(100);
}
