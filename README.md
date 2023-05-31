            start.S                         sme_init.c        sme_trap.c
_start_warm-->|                                 |                  |
              |-----sme_secure_monitor_init---->|                  |
              |<------(ecall)_trap_handler------|                  |
              |--------------sme_monitor_trap_handler------------->|
              |<-----------------------return----------------------|
