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
