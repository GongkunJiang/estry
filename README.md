If writing the firmware package to Package Resource has completed, or, if the device has downloaded the firmware package from the Package URI the state changes to Downloaded.
Writing an empty string to Package URI Resource or setting the Package Resource to NULL (‘\0’), resets the Firmware Update State Machine: the State Resource value is set to Idle and the Update Result Resource value is set to 0.
When in Downloaded state, and the executable Resource Update is triggered, the state changes to Updating.
If the Update Resource failed, the state returns at Downloaded.
If performing the Update Resource was successful, the state changes from Updating to Idle. 
The firmware update state machine is illustrated in Figure 29 of the LwM2M version 1.0 specification (and also in Figure E.6.1-1 of this specification). 

http://confluence.eswincomputing.com/pages/viewpage.action?pageId=57706561
