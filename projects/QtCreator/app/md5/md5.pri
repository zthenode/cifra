########################################################################
# Copyright (c) 1988-2021 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: md5.pri
#
# Author: $author$
#   Date: 9/29/2021
#
# QtCreator .pri file for cifra executable md5
########################################################################

########################################################################
# md5

# md5 TARGET
#
md5_TARGET = md5

# md5 INCLUDEPATH
#
md5_INCLUDEPATH += \
$${cifra_INCLUDEPATH} \

# md5 DEFINES
#
md5_DEFINES += \
$${cifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_CRYPTO_HASH_MD5_MAIN_INSTANCE \

########################################################################
# md5 OBJECTIVE_HEADERS
#
#md5_OBJECTIVE_HEADERS += \
#$${CIFRA_SRC}/xos/app/console/crypto/hash/md5/main.hh \

# md5 OBJECTIVE_SOURCES
#
#md5_OBJECTIVE_SOURCES += \
#$${CIFRA_SRC}/xos/app/console/crypto/hash/md5/main.mm \

########################################################################
# md5 HEADERS
#
md5_HEADERS += \
$${NADIR_SRC}/xos/console/io.hpp \
$${NADIR_SRC}/xos/console/getopt/main_opt.hpp \
$${NADIR_SRC}/xos/console/getopt/main.hpp \
$${NADIR_SRC}/xos/app/console/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/main.hpp \
$${NADIR_SRC}/xos/app/console/version/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/version/main.hpp \
\
$${CIFRA_SRC}/xos/crypto/base/error.hpp \
$${CIFRA_SRC}/xos/crypto/base/exception.hpp \
$${CIFRA_SRC}/xos/crypto/base/implement.hpp \
$${CIFRA_SRC}/xos/crypto/base/extend.hpp \
$${CIFRA_SRC}/xos/crypto/base.hpp \
\
$${CIFRA_SRC}/xos/crypto/hash/algorithm.hpp \
$${CIFRA_SRC}/xos/crypto/hash/implement.hpp \
$${CIFRA_SRC}/xos/crypto/hash/extend.hpp \
$${CIFRA_SRC}/xos/crypto/hash/md5.hpp \
$${CIFRA_SRC}/xos/crypto/hash/sha1.hpp \
$${CIFRA_SRC}/xos/crypto/hash/sha256.hpp \
$${CIFRA_SRC}/xos/crypto/hash/sha512.hpp \
$${CIFRA_SRC}/xos/crypto/hash/openssl/md5.hpp \
$${CIFRA_SRC}/xos/crypto/hash/openssl/sha1.hpp \
$${CIFRA_SRC}/xos/crypto/hash/openssl/sha256.hpp \
$${CIFRA_SRC}/xos/crypto/hash/openssl/sha512.hpp \
$${CIFRA_SRC}/xos/crypto/hash/implemented.hpp \
$${CIFRA_SRC}/xos/crypto/hash.hpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/base/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/base/main.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/base/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/base/main.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/md5/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/md5/main.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/sha1/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/sha1/main.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/sha256/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/sha256/main.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/sha512/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/sha512/main.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/main.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/sha/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/sha/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# md5 SOURCES
#
md5_SOURCES += \
$${CIFRA_SRC}/xos/app/console/crypto/hash/md5/main_opt.cpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/md5/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# md5 FRAMEWORKS
#
md5_FRAMEWORKS += \
$${cifra_FRAMEWORKS} \

# md5 LIBS
#
md5_LIBS += \
$${cifra_LIBS} \

########################################################################
# NO Qt
QT -= gui core
