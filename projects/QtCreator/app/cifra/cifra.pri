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
#   File: cifra.pri
#
# Author: $author$
#   Date: 7/31/2021
#
# QtCreator .pri file for cifra executable cifra
########################################################################

########################################################################
# cifra

# cifra_exe TARGET
#
cifra_exe_TARGET = cifra

# cifra_exe INCLUDEPATH
#
cifra_exe_INCLUDEPATH += \
$${cifra_INCLUDEPATH} \

# cifra_exe DEFINES
#
cifra_exe_DEFINES += \
$${cifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_CIFRA_MAIN_INSTANCE \

########################################################################
# cifra_exe OBJECTIVE_HEADERS
#
#cifra_exe_OBJECTIVE_HEADERS += \
#$${CIFRA_SRC}/cifra/app/console/cifra/main.hh \

# cifra_exe OBJECTIVE_SOURCES
#
#cifra_exe_OBJECTIVE_SOURCES += \
#$${CIFRA_SRC}/cifra/app/console/cifra/main.mm \

########################################################################
# cifra_exe HEADERS
#
cifra_exe_HEADERS += \
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
$${CIFRA_SRC}/xos/crypto/hash/openssl/md5.hpp \
$${CIFRA_SRC}/xos/crypto/hash/sha1.hpp \
$${CIFRA_SRC}/xos/crypto/hash/openssl/sha1.hpp \
$${CIFRA_SRC}/xos/crypto/hash/sha256.hpp \
$${CIFRA_SRC}/xos/crypto/hash/openssl/sha256.hpp \
$${CIFRA_SRC}/xos/crypto/hash/sha512.hpp \
$${CIFRA_SRC}/xos/crypto/hash/openssl/sha512.hpp \
$${CIFRA_SRC}/xos/crypto/hash/implemented.hpp \
$${CIFRA_SRC}/xos/crypto/hash.hpp \
\
$${CIFRA_SRC}/xos/crypto/random/generator.hpp \
$${CIFRA_SRC}/xos/crypto/random/pseudo/generator.hpp \
$${CIFRA_SRC}/xos/crypto/random/implemented.hpp \
$${CIFRA_SRC}/xos/crypto/random.hpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/hash/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/hash/main.hpp \
\
$${CIFRA_SRC}/xos/app/console/cifra/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/cifra/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# cifra_exe SOURCES
#
cifra_exe_SOURCES += \
$${CIFRA_SRC}/xos/crypto/base.cpp \
$${CIFRA_SRC}/xos/crypto/hash.cpp \
$${CIFRA_SRC}/xos/crypto/random.cpp \
\
$${CIFRA_SRC}/xos/app/console/cifra/main_opt.cpp \
$${CIFRA_SRC}/xos/app/console/cifra/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# cifra_exe FRAMEWORKS
#
cifra_exe_FRAMEWORKS += \
$${cifra_FRAMEWORKS} \

# cifra_exe LIBS
#
cifra_exe_LIBS += \
$${cifra_LIBS} \


