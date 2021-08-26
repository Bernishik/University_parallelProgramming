#include <stdio.h>

int main() {
  int nDevices;

  cudaGetDeviceCount(&nDevices);
  for (int i = 0; i < nDevices; i++) {
      cudaDeviceProp prop;
      cudaGetDeviceProperties(&prop, i);
      printf("Device Number: %d\n", i); //Номер девайсу
      printf("  Device name: %s\n", prop.name); //Назва девайсу:
      printf("Major cap: %d\n",prop.major); // Основна версія (обчислювальних можливостей)
      printf("Minor cap: %d\n",prop.minor); // Вторинна версія (обчислювальних можливостей)
      printf("  Memory Clock Rate (KHz): %d\n",prop.memoryClockRate); // Тактова частота
      printf("Global memory %zu\n",prop.totalGlobalMem); // Глобальна память
      printf("Constant memory %d\n",int(prop.totalConstMem)); // Память констант
      printf("Shared memory %d\n",int(prop.sharedMemPerMultiprocessor)); //Спільна память
      printf("Multiproccessors %d\n",prop.multiProcessorCount); // Кількість мультипроцессорів
      printf("Threads in block %d\n",prop.maxThreadsPerBlock); //Максимальна кількість потоків у блоці
      printf("Threads size %d\t %d\t %d\n",prop.maxThreadsDim[0],prop.maxThreadsDim[1],prop.maxThreadsDim[2]); //Розмірність потоку
      printf("Grid  size %d\t %d\t  %d\n",prop.maxGridSize[0],prop.maxGridSize[1],prop.maxGridSize[2]); //Розмірність Сітки
      printf("Single to double precision %d\n",prop.singleToDoublePrecisionPerfRatio);//Співвідношення еффективності одиничної та подвійної точності

  }


}
