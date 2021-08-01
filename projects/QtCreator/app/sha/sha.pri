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
#   File: sha.pri
#
# Author: $author$
#   Date: 7/31/2021
#
# QtCreator .pri file for cifra executable sha
########################################################################

########################################################################
# sha

# sha TARGET
#
sha_TARGET = sha

# sha INCLUDEPATH
#
sha_INCLUDEPATH += \
$${cifra_INCLUDEPATH} \

# sha DEFINES
#
sha_DEFINES += \
$${cifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_CRYPTO_SHA_MAIN_INSTANCE \

########################################################################
# sha OBJECTIVE_HEADERS
#
#sha_OBJECTIVE_HEADERS += \
#$${CIFRA_SRC}/cifra/app/console/sha/main.hh \

# sha OBJECTIVE_SOURCES
#
#sha_OBJECTIVE_SOURCES += \
#$${CIFRA_SRC}/cifra/app/console/sha/main.mm \

########################################################################
# sha HEADERS
#
sha_HEADERS += \
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
$${CIFRA_SRC}/xos/app/console/crypto/hash/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/main.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/sha/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/sha/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# sha SOURCES
#
sha_SOURCES += \
$${CIFRA_SRC}/xos/app/console/crypto/sha/main_opt.cpp \
$${CIFRA_SRC}/xos/app/console/crypto/sha/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# sha FRAMEWORKS
#
sha_FRAMEWORKS += \
$${cifra_FRAMEWORKS} \

# sha LIBS
#
sha_LIBS += \
$${cifra_LIBS} \


