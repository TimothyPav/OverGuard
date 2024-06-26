# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/tim/OverGuard/backend/build/_deps/cpr-src"
  "/home/tim/OverGuard/backend/build/_deps/cpr-build"
  "/home/tim/OverGuard/backend/build/_deps/cpr-subbuild/cpr-populate-prefix"
  "/home/tim/OverGuard/backend/build/_deps/cpr-subbuild/cpr-populate-prefix/tmp"
  "/home/tim/OverGuard/backend/build/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp"
  "/home/tim/OverGuard/backend/build/_deps/cpr-subbuild/cpr-populate-prefix/src"
  "/home/tim/OverGuard/backend/build/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/tim/OverGuard/backend/build/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/tim/OverGuard/backend/build/_deps/cpr-subbuild/cpr-populate-prefix/src/cpr-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
