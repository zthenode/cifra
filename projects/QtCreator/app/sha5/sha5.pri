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
#   File: sha5.pri
#
# Author: $author$
#   Date: 9/30/2021
#
# QtCreator .pri file for cifra executable sha5
########################################################################

########################################################################
# sha5

# sha5 TARGET
#
sha5_TARGET = sha5

# sha5 INCLUDEPATH
#
sha5_INCLUDEPATH += \
$${cifra_INCLUDEPATH} \

# sha5 DEFINES
#
sha5_DEFINES += \
$${cifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_CRYPTO_HASH_SHA512_MAIN_INSTANCE \

########################################################################
# sha5 OBJECTIVE_HEADERS
#
#sha5_OBJECTIVE_HEADERS += \
#$${CIFRA_SRC}/xos/app/console/crypto/hash/sha512/main.hh \

# sha5 OBJECTIVE_SOURCES
#
#sha5_OBJECTIVE_SOURCES += \
#$${CIFRA_SRC}/xos/app/console/crypto/hash/sha512/main.mm \

########################################################################
# sha5 HEADERS
#
sha5_HEADERS += \
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

# sha5 SOURCES
#
sha5_SOURCES += \
$${CIFRA_SRC}/xos/app/console/crypto/hash/sha512/main_opt.cpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/sha512/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# sha5 FRAMEWORKS
#
sha5_FRAMEWORKS += \
$${cifra_FRAMEWORKS} \

# sha5 LIBS
#
sha5_LIBS += \
$${cifra_LIBS} \

########################################################################
# NO Qt
QT -= gui core


