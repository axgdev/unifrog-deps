#ifndef SF2000_COMPAT_H
#define SF2000_COMPAT_H

#include <stdint.h>

#if defined(SF2000)
typedef long ssize_t;

extern int dly_tsk(unsigned ms);
extern uint32_t os_get_tick_count(void);

#define nanosleep(rqtp, rmtp) \
   ({ \
      const struct timespec *sf2000_rqtp = (rqtp); \
      struct timespec *sf2000_rmtp = (rmtp); \
      dly_tsk(1000000L * sf2000_rqtp->tv_sec + sf2000_rqtp->tv_nsec / 1000); \
      if (sf2000_rmtp) \
      { \
         sf2000_rmtp->tv_sec = 0; \
         sf2000_rmtp->tv_nsec = 0; \
      } \
      0; \
   })
#endif

#endif
