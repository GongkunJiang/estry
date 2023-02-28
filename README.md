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

Building a kernel standalone
Initialising build directory with existing configuration
Building the kernel standalone requires initialising a cmake build directory using the seL4 repo as the root CMake project:

├── seL4/
│   └── CMakeLists.txt
├── build/ # Current directory
The build directory is initialised as follows:

cmake -DCROSS_COMPILER_PREFIX= -DCMAKE_TOOLCHAIN_FILE=../seL4/gcc.cmake -G Ninja -C ../seL4/configs/X64_verified.cmake ../seL4/
We use the X64_verified.cmake file for configuration values.

To find available verification configurations:

ls ../seL4/configs/*.cmake
# ../seL4/configs/ARM_HYP_verified.cmake  ../seL4/configs/X64_verified.cmake
# ../seL4/configs/ARM_verified.cmake
A typical verification configuration (cat ../seL4/configs/X64_verified.cmake):

#!/usr/bin/env -S cmake -P
#
# Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
#
# SPDX-License-Identifier: GPL-2.0-only
#

# If this file is executed then build the kernel.elf and kernel_all_pp.c file
include(${CMAKE_CURRENT_LIST_DIR}/../tools/helpers.cmake)
cmake_script_build_kernel()

set(KernelPlatform "pc99" CACHE STRING "")
set(KernelSel4Arch "x86_64" CACHE STRING "")
set(KernelVerificationBuild ON CACHE BOOL "")
set(KernelMaxNumNodes "1" CACHE STRING "")
set(KernelOptimisation "-O2" CACHE STRING "")
set(KernelRetypeFanOutLimit "256" CACHE STRING "")
set(KernelBenchmarks "none" CACHE STRING "")
set(KernelDangerousCodeInjection OFF CACHE BOOL "")
set(KernelFastpath ON CACHE BOOL "")
set(KernelPrinting OFF CACHE BOOL "")
set(KernelNumDomains 16 CACHE STRING "")
set(KernelMaxNumBootinfoUntypedCap 166 CACHE STRING "")
set(KernelRootCNodeSizeBits 19 CACHE STRING "")
set(KernelMaxNumBootinfoUntypedCaps 50 CACHE STRING "")
set(KernelFSGSBase "inst" CACHE STRING "")
At this point you could use ccmake ../seL4 to browse the configuration.

Building the kernel target
The kernel target needs to be specified to ninja otherwise it won’t be built.

ninja kernel.elf
Looking in the build directory:

ls
# autoconf                 gen_config       kernel_all_pp.c                      kernel.elf
# build.ninja              generated        kernel_all_pp_prune.c                linker.lds_pp
# circular_includes_valid  generated_prune  kernel_all_pp_prune_wrapper_temp.c   linker_ld_wrapper_temp.c
# CMakeCache.txt           gen_headers      kernel_bf_gen_target_111_pbf_temp.c  rules.ninja
# CMakeFiles               kernel_all.c     kernel_bf_gen_target_11_pbf_temp.c
# cmake_install.cmake      kernel_all.i     kernel_bf_gen_target_1_pbf_temp.c
The kernel.elf can now be used in other build environments.

file kernel.elf
# kernel.elf: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), statically linked, not stripped
