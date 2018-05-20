#ifndef __sem_osx_h__
#define __sem_osx_h__

#ifdef OS_MACOSX

#include <semaphore.h>
int sem_timedwait(sem_t *sem, timespec *ts);

#endif

#endif
