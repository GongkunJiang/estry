repo init -u ssh://Gerrit账户@gerrit.eswincomputing.com:29418/e315s/manifest -b 分支名 --repo-url=ssh://Gerrit账户@gerrit.eswincomputing.com:29418/tools/git-repo

repo sync -cdj4 --no-tags
repo forall -c git lfs pull

分支名可用e315s-d_sf，e315s-d_sme，e315s-d_saas 任一替换。

PubkeyAcceptedKeyTypes=+ssh-rsa

wget -qO - https://download.sublimetext.com/sublimehq-pub.gpg | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/sublimehq-archive.gpg
echo "deb https://download.sublimetext.com/ apt/stable/" | sudo tee /etc/apt/sources.list.d/sublime-text.list
sudo apt-get update
sudo apt-get install sublime-text
sudo apt-get install apt-transport-https

VBoxGuestAdditions_6.1.38.iso
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
