repo init -u ssh://Gerrit账户@gerrit.eswincomputing.com:29418/e315s/manifest -b 分支名 --repo-url=ssh://Gerrit账户@gerrit.eswincomputing.com:29418/tools/git-repo

repo sync -cdj4 --no-tags
repo forall -c git lfs pull

分支名可用e315s-d_sf，e315s-d_sme，e315s-d_saas 任一替换。

PubkeyAcceptedKeyTypes=+ssh-rsa
