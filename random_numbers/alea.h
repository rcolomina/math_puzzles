#include <pthread.h>
#include <deque>

#ifndef _ALEA_H_
#define _ALEA_H_

class Alea
{
  public:
     Alea(int seed=1234,int maxi=1000);
     ~Alea();
     int paraller_random();
     int serial_random();

  private:

     //constructores y operaciones prohibidas (error en link)
     Alea(const Alea &);
     Alea & operator=(const Alea &) const;

     //variables miembro para la cola circular
     const int _max;
     int _size;
     int *_pBuffer;
     int *_pInit;
     int *_pEnd;

     std::deque<int> _queue;

     //valores para el generador de numeros aleatorios
     static const int _a= 1103515245;
     static const int _c= 12345;
     static const int _m= 0x8fff;
     int _previous;
     int _previous2;

     //manejadores de hilos;
     static void *wrapper(void *);
     int work();
     pthread_t _thread;
     pthread_attr_t _attrib;
};
#endif
