git clone https://git.kernel.org/pub/scm/linux/kernel/git/
torvalds/linux.git --depth 1 
git checkout v5.10
ls
sudo apt-get install git fakeroot build-essential ncurses-dev xz-utils libssl-dev bc flex libelf-dev bison 

lwm2m_step
	registration_step
		prv_register
			transaction_send
				lwm2m_buffer_send
					connection_send
						send_data

for (objectP = contextP->objectList; objectP != NULL; objectP = objectP->next)
Client_identity:000102030405060708090a0b0c0d0e0f

Setup DTLS security in Leshan Demo Server:
Open up the Leshan Demo Server web UI
Click on “Security”
Click on “Add new client security configuration”
Enter the following data:
Client endpoint: qemu_x86
Security mode: Pre-Shared Key
Identity: Client_identity
Key: 000102030405060708090a0b0c0d0e0f

https://github.com/eclipse/leshan/wiki/Credential-files-format
https://marketplace.visualstudio.com/_apis/public/gallery/publishers/josetr/vsextensions/cmake-language-support-vscode/0.0.9/vspackage
