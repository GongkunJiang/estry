mkdir verification
cd verification
repo init -u ssh://git@github.com/seL4/verification-manifest.git
repo sync
If you do not have ssh access set up for github, you can also use

repo init -u https://github.com/seL4/verification-manifest.git
For build instructions for the proofs, see the l4v/ repository.

For build instructions for the binary verification, see the graph-refine/ repository.

To set your repositories up for development, replace the init step with:

repo init -m devel.xml -u ssh://git@github.com/seL4/verification-manifest.git
Similarly, if you are looking to use the proofs for a specific release version of seL4, use the -m option to select the corresponding manifest file.
