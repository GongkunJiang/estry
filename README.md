repo init -u ssh://liushiwei@gerrit.eswincomputing.com:29418/platform/manifest -b a710-tee --repo-url=ssh://liushiwei@gerrit.eswincomputing.com:29418/tools/git-repo 
repo sync -cdj4 --no-tags 
repo forall -c git lfs pull
