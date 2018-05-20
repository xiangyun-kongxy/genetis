#include "sem_osx.hpp"

#ifdef OS_MACOSX
#include <semaphore.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

int sem_timedwait(sem_t *sem, timespec *ts) {
    timespec now;
    do {
        if (sem_trywait(sem) == 0)
            return 0;
        usleep(10);
        clock_gettime(CLOCK_REALTIME, &now);
    } while(now.tv_sec * 1000000000 + now.tv_nsec <
            ts->tv_sec * 1000000000 + ts->tv_nsec);

    errno = ETIMEDOUT;
    return -1;
}

#endif

