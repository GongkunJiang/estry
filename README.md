
			start.S             			sme_init.c        sme_trap.c
_start_warm-->| 								|
			  |-----sme_secure_monitor_init---->|				  |
			  |<------(ecall)_trap_handler------|                 |
			  |--------------sme_monitor_trap_handler------------>|
			  |<-----------------------return---------------------|

https://marketplace.visualstudio.com/_apis/public/gallery/publishers/luveti/vsextensions/kconfig/1.0.3/vspackage
