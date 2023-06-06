commit 0fee31d0cda3610ef6ab591d3f642a69f65a9fe7
Author: lixiaoqin <lixiaoqin@eswincomputing.com>
Date:   Mon Oct 31 15:51:33 2022 +0800

    Import A710_SDK_LIN_220922 from IDE v0.9.6.2
    
    Change-Id: I9a574547cd16b14937f2118bb358ceb5c0793876

commit 3b5089dc9192c336ab15f2a1a7b1cccdbf230f5f
Author: du pu <dupu@eswin.com>
Date:   Mon Sep 28 05:34:37 2020 +0000

    Initial empty repository


start.S                         sme_init.c        sme_trap.c
_start_warm-->|                                 |                  |
              |-----sme_secure_monitor_init---->|                  |
              |<------(ecall)_trap_handler------|                  |
              |--------------sme_monitor_trap_handler------------->|
              |<-----------------------return----------------------|
              
              
