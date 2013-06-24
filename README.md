scons-versioned-lib-demo
========================

Demonstrates how to use and package shared libraries with SCons by using InstallVersionedLib and Package/Tag

To build:
scons --prefix=$(pwd)/isntall .

Issues:

1) Removing the 'dev link' (e.g. the shared object symlink with no version info) from either the build directory or the install directory does not cause a rebuild of that file.

2) The value returned from InstallVersionedLib doesn't contain all of the artifacts so there is no way to tag them separately (e.g. put the hard file and the soname-symlink into the main package, and the dev-link into the -dev package). (see NOTEs 1 and 3).

3) The file added to _INSTALLED_FILES for the dev link needs to be done within brackets, otherwise gets interpreted character by character. (see NOTE 2)

4) Tarfile packages get built with paths that encode the variant dir and packaging directory, meaning that the files are not solely prefixed by $PREFIX in the tarfile as they should be. This might be my misunderstanding of how packaging works. Also, there should probably be a way to tell Packaging to package relative to $PREFIX, which is useful if the packages should be 'run anywhere'. (See NOTE 4).
