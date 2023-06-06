6f0674a92b2c9ccdf29400cd524f5de8611c1210

commit ad446a3c6620f8ffb5887069485c65d8faf8d93b

commit 2ebb7452adb9e37b72bd81b4fb443adc2f5c71cd


start.S                         sme_init.c        sme_trap.c
_start_warm-->|                                 |                  |
              |-----sme_secure_monitor_init---->|                  |
              |<------(ecall)_trap_handler------|                  |
              |--------------sme_monitor_trap_handler------------->|
              |<-----------------------return----------------------|
              
              
