sudo apt-get install cmake ccache ninja-build cmake-curses-gui
sudo apt-get install libxml2-utils ncurses-dev
sudo apt-get install curl git doxygen device-tree-compiler
sudo apt-get install u-boot-tools

sudo apt-get install python3-dev python3-pip python-is-python3
sudo apt-get install protobuf-compiler python3-protobuf

Simulating with QEMU

In order to run seL4 projects on a simulator you will need QEMU:

sudo apt-get install qemu-system-arm qemu-system-x86 qemu-system-misc
Cross-compiling for ARM targets

To build for ARM targets you will need a cross compiler:

sudo apt-get install gcc-arm-linux-gnueabi g++-arm-linux-gnueabi
sudo apt-get install gcc-aarch64-linux-gnu g++-aarch64-linux-gnu
(you can install the hardware floating point versions as well if you wish)

sudo apt-get install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf
Cross-compiling for RISC-V targets

To build for RISC-V targets you will need a cross compiler:

It is recommended to build the toolchain from source.

 git clone https://github.com/riscv/riscv-gnu-toolchain.git
 cd riscv-gnu-toolchain
 git submodule update --init --recursive
 export RISCV=/opt/riscv
 ./configure --prefix="${RISCV}" --enable-multilib
 make linux
After it is built, add the $RISCV/bin folder to your PATH. The built toolchain works for both 32-bit and 64-bit.

Alternatively, any pre-built toolchain with multilib enabled should work.

Builidng the seL4 manual

If you would like to build the seL4 manual, you will need the following LaTeX pacakges:

sudo apt-get install texlive texlive-latex-extra texlive-fonts-extra
Debian
For Debian Stretch or later
The dependencies listed in our docker files repository will work for a Debian installation. You can refer to this repository for an up-to-date list of base build dependencies. Specifically refer to the dependencies listed in the:

Base Tools Dockerfile
seL4 Dockerfile
LaTeX
The version of cmake in Debian stretch is too old to build seL4 projects (buster and later are OK). If you are on stretch, install cmake from stretch-backports:

Add the stretch-backports repository like this (substitute a local mirror for ftp.debian.org if you like)

sudo sh -c "echo 'deb http://ftp.debian.org/debian stretch-backports main' > /etc/apt/sources.list.d/backports.list"
Then install cmake with

sudo apt-get update
sudo apt-get -t stretch-backports install cmake
Python Dependencies
Regardless of your Linux distribution, python dependencies are required to build seL4, the manual and its proofs. To install you can run:

pip3 install --user setuptools
pip3 install --user sel4-deps
# Currently we duplicate dependencies for python2 and python3 as a python3 upgrade is in process
pip install --user setuptools
pip install --user sel4-deps
(Some distributions use pip for python3 and pip2 for python2; others uses pip for python2 and pip3 for python3. Use the Python 3 version for your distribution)

CAmkES Build Dependencies
To build a CAmkES based project on seL4, additional dependencies need to be installed on your host machine. Projects using CAmkES (the seL4 component system) need Haskell and some extra Python libraries in addition to the standard build tools. The following instructions cover the CAmkES build dependencies for Ubuntu/Debian. Please ensure you have installed the dependencies listed in sections seL4 Build Dependencies and Get Google’s Repo tool prior to building a CAmkES project.

Python Dependencies
The Python dependencies required by the CAmkES build toolchain can be installed via pip:

pip3 install --user camkes-deps
# Currently we duplicate dependencies for python2 and python3 as a python3 upgrade is in process
pip install --user camkes-deps
Haskell Dependencies
The CAmkES build toolchain additionally requires Haskell. You can install the Haskell stack on your distribution by running:

curl -sSL https://get.haskellstack.org/ | sh
If you prefer not to bypass your distribution’s package manager, you can do

sudo apt-get install haskell-stack
Build Dependencies
Ubuntu
These instructions are intended for Ubuntu LTS versions 18.04, 20.04, and 22.04.

Install the following packages:

sudo apt-get install clang gdb
sudo apt-get install libssl-dev libclang-dev libcunit1-dev libsqlite3-dev
sudo apt-get install qemu-kvm
Debian
For Debian Stretch or later
The dependencies listed in our docker files repository will work for a Debian installation. You can refer to this repository for an up-to-date list of base build dependencies. Specifically refer to the dependencies listed in the:

CAmkES Dockerfile
Proof and Isabelle Dependencies
Proof Dependencies
Linux Packages - Debian
On Buster or Bullseye, to run all proofs against the ARMv7-A architecture you will need to install the following packages:

sudo apt-get install \
    python3 python3-pip python3-dev \
    gcc-arm-none-eabi build-essential libxml2-utils ccache \
    ncurses-dev librsvg2-bin device-tree-compiler cmake \
    ninja-build curl zlib1g-dev texlive-fonts-recommended \
    texlive-latex-extra texlive-metapost texlive-bibtex-extra \
    rsync
There is no package for the MLton compiler on Buster or Bullseye, so you will need to install it from the MLton website.

The Haskell Stack package is unavailable on Bullseye and out-of-date on Buster, so you will need to install it from the Haskell Stack website.

Linux Packages - Ubuntu
These instructions are intended for Ubuntu LTS versions 18.04, 20.04, and 22.04.

To run all proofs against the ARMv7-A architecture you will need to install the following packages:

sudo apt-get install \
    python3 python3-pip python3-dev \
    gcc-arm-none-eabi build-essential libxml2-utils ccache \
    ncurses-dev librsvg2-bin device-tree-compiler cmake \
    ninja-build curl zlib1g-dev texlive-fonts-recommended \
    texlive-latex-extra texlive-metapost texlive-bibtex-extra \
    mlton-compiler haskell-stack
macOS packages
These instructions use Homebrew, which can be installed from their website. The main packages that are needed are:

brew install git libxml2 ncurses librsvg dtc cmake ninja texlive rysnc python ccache \
    zstd haskell-stack
The installation of mlton on Apple silicon is currently not well supported. One approach would be to cross-compile mlton on another architecture and transfer it. On Intel machines, the following works:

brew install mlton
To install the cross-compilers, run

brew install --cask gcc-arm-embedded

brew install arm-none-eabi-gcc

brew tap messense/macos-cross-toolchains
brew install x86_64-unknown-linux-gnu aarch64-unknown-linux-gnu

brew tap riscv/riscv
brew install riscv-tools
Note that CMake will require the x86 compiler before it can be invoked.

The instructions in the sections below should apply for both Linux and macOS.

Python
The build system for the seL4 kernel requires several python packages:

pip3 install --user --upgrade pip
pip3 install --user sel4-deps
Haskell Stack
After installing haskell-stack, make sure you’ve adjusted your PATH to include $HOME/.local/bin, and that you’re running an up-to-date version:

stack upgrade --binary-only
which stack # should be $HOME/.local/bin/stack
Isabelle Setup
After the repository is set up using repo with seL4/verification-manifest, you should have following directory structure, where l4v is the repository you are currently looking at:

verification/
    HOL4/
    graph-refine/
    isabelle/
    l4v/
    seL4/
To set up Isabelle for use in l4v/, assuming you have no previous installation of Isabelle, run the following commands in the directory verification/l4v/:

mkdir -p ~/.isabelle/etc
cp -i misc/etc/settings ~/.isabelle/etc/settings
./isabelle/bin/isabelle components -a
./isabelle/bin/isabelle jedit -bf
./isabelle/bin/isabelle build -bv HOL
These commands perform the following steps:

create an Isabelle user settings directory.
install L4.verified Isabelle settings. These settings initialise the Isabelle installation to use the standard Isabelle contrib tools from the Munich Isabelle repository and set up paths such that multiple Isabelle repository installations can be used side by side without interfering with each other.
download contrib components from the Isabelle repository. This includes Scala, a Java JDK, PolyML, and multiple external provers. You should download these, even if you have these tools previously installed elsewhere to make sure you have the right versions. Depending on your internet connection, this may take some time.
compile and build the Isabelle PIDE jEdit interface.
build basic Isabelle images to ensure that the installation works. This may take a few minutes.
Alternatively, it is possible to use the official Isabelle2021 release bundle for your platform from the Isabelle website. In this case, the installation steps above can be skipped, and you would replace the directory verification/isabelle/ with a symbolic link to the Isabelle home directory of the release version. Note that this is not recommended for development, since Google repo will overwrite this link when you synchronise repositories and Isabelle upgrades will have to be performed manually as development progresses.

PIDE Tools
The following tools and tips can make writing proofs easier and more efficient when using the Isabelle PIDE jEdit interface.

WhiteSpace plugin
The WhiteSpace plugin can highlight normally invisible whitespace characters such as tabs and spaces, and can remove trailing whitespace on save. To install and configure the WhiteSpace plug-in for jEdit, follow the instructions below.

Go to Plugins -> Plugin manager -> Install.
Search for WhiteSpace and install the plugin.
Go to Plugins -> Plugin Options -> WhiteSpace -> On save actions.
Check “Remove trailing whitespace” and click Apply.
Key bindings for Navigator
The Isabelle PIDE provides “Back” and “Forward” actions that allow you to easily navigate to previous positions in your edit history. Follow the steps below to bind a key to the “Back” function. We recommend [ctrl]+[`].

Go to Utilities -> Global Options -> jEdit -> Shortcuts.
Select Action Set -> Plugin: Navigator.
Set a shortcut for Back.
Go-to-error macro
Run the following commands in the directory verification/l4v/:

mkdir -p ~/.isabelle/jedit/macros
cp misc/jedit/macros/goto-error.bsh ~/.isabelle/jedit/macros/.
You can add keybindings for this macro in the usual way, by going to Utilities -> Global Options -> jEdit -> Shortcuts.

git clone https://github.com/seL4/seL4-CAmkES-L4v-dockerfiles.git
Get Camkes
Make sure that you already have the tools to build seL4 and Camkes.
Download Camkes:
mkdir camkes-project
cd camkes-project
repo init -u https://github.com/seL4/camkes-manifest.git
repo sync
Build and run simple application
The following will configure, build, and run a simple example CAmkES system:

cd camkes-project
mkdir build
cd build
../init-build.sh -DPLATFORM=sabre -DAARCH32=1 -DCAMKES_APP=adder -DSIMULATION=1
ninja
./simulate

Configuring and building an seL4 project
This page contains documentation for how to interact with and build a project that is using this build system. For new project development, see incorporating the build system.

Basic build initialisation
In the root directory of a seL4-based project, first create a separate build directory for the output binaries, then initialize CMake:

mkdir build
cd build
cmake -DCROSS_COMPILER_PREFIX=arm-linux-gnueabi- -DCMAKE_TOOLCHAIN_FILE=../kernel/gcc.cmake <OTHER_COMMAND_LINE_OPTIONS_HERE> -G Ninja ..
We now break down each component in the above invocation:

-D defines a variable, in the form X=Y.
CROSS_COMPILER_PREFIX specifies the toolchain for cross-compilation, which cannot be changed after build directory initialisation. For further details, please see “Cross Compiling” below.
CMAKE_TOOLCHAIN_FILE which indicates that CMake should load the specified file as a ‘toolchain’ file. A toolchain file is able to set up the C compiler, linker etc., for building the project. In the example we assume a typical project layout, where seL4 is in the ‘kernel’ directory, at the top level. The gcc.cmake’ file from the seL4 repository sets up C compilers and linkers using the CROSS_COMPILER_PREFIX.
-G Ninja tells CMake to generate Ninja build scripts as opposed to GNU Makefiles. Only Ninja scripts are supported by parts of the kernel.
.. is the path to the top-level CMakeLists.txt file describing this project, which in this case is placed in the root directory of the project.
We also provide a shorthand wrapping script which abstracts the above into a shorter command:

../init-build -DCROSS_COMPILER_PREFIX=arm-linux-gnueabi- <COMMAND_LINE_OPTIONS_HERE>
After configuration, you can build the project by invoking ninja:

ninja
After the build has completed, the resulting binaries will be in the images/ subdirectory.

Configuration
Types of Options
CMake has two types of configuration options:

Boolean options, which are are either ON or OFF,
String options, which can be set to any value, subject to restrictions set by the project authors.
String options can have ‘hints’, which specify can one of several fixed values. CMake configuration editors respect these and provide a radio selection.

Selecting Options
Many projects have some degree of customisation available via configuration options. Once the build directory is initialised, you can use the following approaches to bring up a user-interface for option configuration:

A ncurses based configuration:
ccmake .
Graphical configuration:
cmake-gui .
In both cases the path . should resolve to the same directory used in the build configuration.

Changing option values
Any changes to configuration options will not be reflected in the user interface unless explicitly requested by using (c)onfigure, which may result in changes to the options available. For example if option A depends on boolean option B, A will not show up until B is enabled and (c)onfigure is used to reprocess the CMake files.

To exit the configuration interface, use (g)enerate and exit or (q)uit without generation. CMake will not permit generation if the configuration is incomplete ((c)onfigure must be run and all options set).

To rebuild after changing configuration options, invoke ninja:

ninja
Initial configuration:
Many of our projects support multiple configurations, where the following broad approaches are used to present simple options to the user:

CMake cache scripts: These files can assign initial values to any number of configuration variables. By combining one or more of these together you can configure an entire system.
Meta configuration options: Meta configuration options are normally passed as initial -DVAR=FOO command line arguments to CMake and will be programatically inspected by projects’ CMake scripts to (re)configure the system.
CMake cache scripts:
CMake cache scripts provide subsets of preconfigured options, which allow the user of a project to avoid manually setting each option. Cache scripts have the file extension .cmake.

Projects may provide cache script files which each contain the cache settings necessary to configure a single feature or option. By combining multiple .cmake files, a project can be initialised in a specific way. Cache script configurations are provided by passing -C <file> to cmake when initialising the build directory. For example, given a typical project structure, one might invoke cmake or init-build.sh with several of cache scripts as arguments.

Multiple cached scripts can be specified on the command line, although if the same option is set twice only one value is used. Consider an example with several cache scripts for setting the architecture details (arm.cmake, x86.cmake) and for setting build options (debug.cmake, release.cmake). The intended usage is that one architectural cache file is used, and one build options file, as demonstrated below:

cmake -C../projects/awesome_project/configs/arm.cmake -C../projects/awesome_project/configs/debug.cmake -DCROSS_COMPILER_PREFIX=arm-linux-gnueabi- -DCMAKE_TOOLCHAIN_FILE=../kernel/gcc.cmake -G Ninja ..
While nothing prevents the usage of both arm.cmake and x86.cmake at the same time, this does not make sense, and only one value for each option will be used. For projects with multiple cache scripts, check which can be used together.

Meta configuration options:
Some seL4 projects provide top-level variables which, used across projects, have the same behaviour. These options are as follows:

-DPLATFORM=<YOUR_PREFERENCE>: Selects the target system for the resulting binaries. Valid values for this variable are the first value (preceding the semicolon) on each line of the config_choice directive for each architecture:
For ARM: List in source.
For X86: List in source.
For RISC-V: List in source.
-DRELEASE: Set to 0 or 1: Turning this off compiles a debug build. Turning it on compiles the project without debugging features enabled.
-DVERIFICATION: Set to 0 or 1: This is used to generate the version of the seL4 kernel source which is VERIFIABLE. This does not produce a binary for the verified kernel platform.
-DSMP: Set to 0 or 1: Turns SMP (symmetric multiprocessing) support on or off. By default it will enable support for up to 4 processors. To explicitly set the maximum number of supported CPUs, try setting -DKernelMaxNumNodes=<YOUR_PREFERENCE>.
-DSIMULATION: Set to 0 or 1: This produces a build of the project which is suited for running in an emulator such as QEMU.
Both the seL4test and seL4bench projects follow this form.

sel4test example:
For more information on configuring, building and running the sel4test suite, please see the main page on seL4test.

Cross compiling:
Cross compilation refers to compiling a program for a target machine which is different from the machine you are using to compile the program.

Generally, in order to cross-compile, a separate compiler is required which specifically targets the foreign machine.

For ARM-based targets:
You can use the following command line options when when cross-compiling for an ARM-based machine:

-DAARCH32=TRUE: Tells the build system that you are building for a 32-bit ARM target. This will cause the build system to assume that you have a cross compiler installed which targets a system with the triplet name arm-linux-gnueabi-.
-DAARCH32HF=TRUE: Tells the build system you’re building for a 32-bit ARM target which has hardware floating point support. Assumes you have a cross- compiler installed which targets arm-linux-gnueabihf-.
-DAARCH64=TRUE: Tells the build system you’re building for a 64-bit ARM target. Assumes you have a cross-compiler installed which targets aarch64-linux-gnu-.
Another option is to explicitly specify the toolchain through -DCROSS_COMPILER_PREFIX, which can be used to set the prefix of the cross-compiler to use.

For RISC-V based targets:
You can use the following options when cross compiling for a RISC-V target:

-DRISCV32=TRUE: Tells the build system that you are building for a 32-bit RISC-V target. This will cause the build system to assume that you have a cross- compiler installed which targets a system with the triplet name riscv32-unknown-elf-.
-DRISCV64=TRUE: Tells the build system you’re building for a 64-bit RISC-V target. Assumes you have a cross-compiler installed which targets riscv64-unknown-elf-.
Like ARM, you can explicitly specify the toolchain through -DCROSS_COMPILER_PREFIX, which can be used to set the prefix of the cross-compiler to use.

CMAKE_BUILD_TYPE
The CMAKE_BUILD_TYPE option appears in CMake configuration editors and allows users to configure that build type (release, debug etc.). Note that this option is not respected by the seL4 kernel.

Building with Clang
The kernel as well as, some other projects, can be built using the clang compiler. To select this configuration, the -DTRIPLE variable must be set in the initial configuration step i.e pass in as an argument to the init-build script.

The value of the TRIPLE should be the target for which you are compiling.

../init-build -DTRIPLE=x86_64-linux-gnu <COMMAND_LINE_OPTIONS_HERE>
The CROSS_COMPILER_PREFIX argument is unnecessary and ignored when compiling with clang. When building for arm based targets, the target TRIPLE will be equal to the CROSS_COMPILER_PREFIX (when using gcc) without the trailing ‘-‘.

Using clang to compile for RISC-V based targets is currently not supported.
