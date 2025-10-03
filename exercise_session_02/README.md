# Exercise Session 02 #
In this session, you will compile and run your first programs on Eiger. This directory contains two versions of the code that were parallelized using MPI or OpenMP.

## Exercise 2.2

module list:

Derzeit geladene Module:
  1) craype-x86-rome                                 8) cray/23.12
  2) libfabric/1.22.0                                9) craype/2.7.30
  3) craype-network-ofi                             10) cray-dsmml/0.2.2
  4) xpmem/2.9.6-1.1_20240510205610__g087dc11fc19d  11) cray-mpich/8.1.28
  5) cce/17.0.0                                     12) cray-libsci/23.12.5
  6) perftools-base/23.12.0                         13) PrgEnv-cray/8.5.0
  7) cpe/23.12

module avail:

------------- /opt/cray/pe/lmod/modulefiles/mpi/crayclang/17.0/ofi/1.0/cray-mpich/8.0 --------------
   cray-hdf5-parallel/1.12.2.9    cray-mpixlate/1.0.3    cray-parallel-netcdf/1.12.3.9

------------------------------- /capstor/apps/cscs/eiger/modulefiles -------------------------------
   CMake/3.20.1                 cpeGNU/23.12                reframe-cscs-tests/24.05
   CMake/3.21.2                 cpeIntel/23.12              reframe-cscs-tests/24.07
   CMake/3.22.1                 ddt/22.1.3-linux-x86_64     reframe-cscs-tests/24.08 (D)
   CMake/3.26.5          (D)    git-lfs/3.4.1               reframe/4.5.1
   EasyBuild-custom/cscs        hub/2.14.2                  reframe/4.6.0            (D)
   NCL/6.6.2                    hwloc/2.4.1                 singularity/3.6.4-eiger
   OOOPS/1.0                    jupyter-utils/0.1           w3m/0.5.3+git20210102-6
   cpeAMD/23.12                 patchelf/0.18.0
   cpeCray/23.12                reframe-cscs-tests/24.03

------------------------- /opt/cray/pe/lmod/modulefiles/perftools/23.12.0 --------------------------
   perftools-lite-events    perftools-lite-hbm      perftools-lite       perftools
   perftools-lite-gpu       perftools-lite-loops    perftools-preload

------------------- /opt/cray/pe/lmod/modulefiles/comnet/crayclang/17.0/ofi/1.0 --------------------
   cray-mpich-abi/8.1.28    cray-mpich/8.1.28 (L)

---------------------- /opt/cray/pe/lmod/modulefiles/compiler/crayclang/17.0 -----------------------
   cray-hdf5/1.12.2.9    cray-libsci/23.12.5 (L)

--------------------------- /opt/cray/pe/lmod/modulefiles/mix_compilers ----------------------------
   amd-mixed/6.1.0          intel-classic-mixed/2023.2.0 (D)    intel-oneapi-mixed/2023.2.0 (D)
   aocc-mixed/4.1.0         intel-classic-mixed/2024.0          intel-oneapi-mixed/2024.0
   cce-mixed/17.0.0         intel-mixed/2023.2.0         (D)    nvhpc-mixed/24.3
   gcc-native-mixed/12.3    intel-mixed/2024.0                  nvidia-mixed/24.3

---------------------------- /opt/cray/pe/lmod/modulefiles/net/ofi/1.0 -----------------------------
   cray-openshmemx/11.7.0

module spider:

------------------------------------------------------------------------------------------------
Dies ist eine Liste aller verfügbaren Module:
------------------------------------------------------------------------------------------------
  Boost: Boost/1.78.0-python3, Boost/1.78.0
    Boost provides free peer-reviewed portable C++ source libraries. 

  CDI: CDI/2.2.4-parallel
    CDI is a C and Fortran Interface to access Climate and NWP model Data. Supported data
    formats are GRIB, netCDF, SERVICE, EXTRA and IEG. 

  CDO: CDO/1.9.10
    CDO is a collection of command line Operators to manipulate and analyse Climate and NWP
    model Data. 

  CMake: CMake/3.20.1, CMake/3.21.2, CMake/3.22.1, CMake/3.26.5
    CMake, the cross-platform, open-source build system. CMake is a family of tools designed to
    build, test and package software. 

  CP2K: CP2K/9.1
    CP2K is a freely available (GPL) program, written in Fortran 95, to perform atomistic and
    molecular simulations of solid state, liquid, molecular and biological systems. It provides
    a general framework for different methods such as e.g. density functional theory (DFT)
    using a mixed Gaussian and plane waves approach (GPW), and classical pair and many-body
    potentials. 

  Catalyst: Catalyst/2.0.0-rc4, Catalyst/2.0.0
    Catalyst is an API specification developed for simulations (and other scientific data
    producers) to analyze and visualize data in situ.

  Charm++: Charm++/6.10.2
    Charm++ is a machine independent parallel programming system. Programs written using this
    system will run unchanged on MIMD machines with or without a shared memory. 
