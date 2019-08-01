[![Build status](https://ci.appveyor.com/api/projects/status/j2t87b4gkg33yo2b?svg=true)](https://ci.appveyor.com/project/SSE4/dirent-h)

header-only Windows implementation of the `<dirent.h>` header.

tested on the following compilers:
- Visual Studio
- Clang for Windows (clang-cl)
- GCC (MinGW)

implements the following functions:
- opendir
- _wopendir
- fdopendir
- closedir
- readdir
- readdir_r
- rewinddir
- telldir
- seekdir
- dirfd
- scandir
- alphasort
- versionsort
