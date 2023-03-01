https://www.cl.cam.ac.uk/research/hvg/Isabelle/dist/Isabelle2022_linux.tar.gz

sudo apt-get install \
    python3 python3-pip python3-dev \
    gcc-arm-none-eabi build-essential libxml2-utils ccache \
    ncurses-dev librsvg2-bin device-tree-compiler cmake \
    ninja-build curl zlib1g-dev texlive-fonts-recommended \
    texlive-latex-extra texlive-metapost texlive-bibtex-extra \
    mlton-compiler haskell-stack
    
Docker: Headless Ubuntu Linux
Requirements
Docker container for the host operating system
Docker image for Isabelle
Installation
The Docker image contains Ubuntu Linux 22.04 with Isabelle2022. It can be used, e.g. on another Linux host like this:

docker pull makarius/isabelle:Isabelle2022
docker run makarius/isabelle:Isabelle2022
That provides command-line access to the regular isabelle tool wrapper, with indirection through the Docker container infrastructure.

The default platform is Intel x86_64, but ARM is supported as well (e.g. for Apple M1):

docker pull makarius/isabelle:Isabelle2022_ARM
docker run makarius/isabelle:Isabelle2022_ARM
Linux
Requirements
Isabelle2022_linux.tar.gz
Proper Window manager / Desktop environment that works with Java/AWT/Swing
TeXLive for Isabelle/LaTeX document preparation
Installation
The bundled archive contains everything required for Isabelle on Linux. It can be unpacked into an arbitrary directory like this:

tar -xzf Isabelle2022_linux.tar.gz
The Isabelle/jEdit Prover IDE can be invoked like this:

Isabelle2022/Isabelle2022
Other Isabelle command-line tools can be invoked from the terminal like this:

Isabelle2022/bin/isabelle

Linux
Requirements
Isabelle2022_linux.tar.gz
Proper Window manager / Desktop environment that works with Java/AWT/Swing
TeXLive for Isabelle/LaTeX document preparation
Installation
The bundled archive contains everything required for Isabelle on Linux. It can be unpacked into an arbitrary directory like this:

tar -xzf Isabelle2022_linux.tar.gz
The Isabelle/jEdit Prover IDE can be invoked like this:

Isabelle2022/Isabelle2022
Other Isabelle command-line tools can be invoked from the terminal like this:

Isabelle2022/bin/isabelle
Windows (10, 11)
