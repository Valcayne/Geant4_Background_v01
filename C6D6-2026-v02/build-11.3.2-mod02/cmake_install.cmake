# Install script for directory: /mnt/lustre/home/u6979/geant4_programs/C6D6-2026-v01

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/myC6D6" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/myC6D6")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/myC6D6"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/mnt/lustre/home/u6979/geant4_programs/C6D6-2026-v01/build-11.3.2-mod02/myC6D6")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/myC6D6" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/myC6D6")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/myC6D6"
         OLD_RPATH "/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/mesa-22.1.6-xdhdscyqcj3n536bmvg2atsluld2f72x/lib:/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/libxmu-1.1.4-wss4pouo3czvkz4gwobnm5tbiexmn7av/lib:/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/libxext-1.3.3-cq2t2ab6spzv7wcyk36235y6b5tps2hb/lib:/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/libxt-1.1.5-7z2qtpt3wauw6ndlzbtzcg6tb2ddkdra/lib:/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/libice-1.0.9-yuhe3t7b5woyylfjdoxrndkuwpie2rsa/lib:/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/libsm-1.2.3-j7qahowkhwqqrvp3vdctbc23qujku2zv/lib:/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/oneapi-2023.1.0/libx11-1.8.4-aj3pqduvv2fzv7fo2yjbbrdshtniiary/lib:/mnt/lustre/home/spack/spack/opt/spack/linux-rocky8-icelake/gcc-8.5.0/expat-2.5.0-h45w6nutpclaoxlygi5i7rgjn2yec7tt/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/myC6D6")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/mnt/lustre/home/u6979/geant4_programs/C6D6-2026-v01/build-11.3.2-mod02/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
