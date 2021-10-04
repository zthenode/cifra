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
#   File: rc4.pri
#
# Author: $author$
#   Date: 9/29/2021
#
# QtCreator .pri file for cifra executable rc4
########################################################################

########################################################################
# rc4

# rc4 TARGET
#
rc4_TARGET = rc4

# rc4 INCLUDEPATH
#
rc4_INCLUDEPATH += \
$${cifra_INCLUDEPATH} \

# rc4 DEFINES
#
rc4_DEFINES += \
$${cifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_CRYPTO_CIPHER_RC4_MAIN_INSTANCE \

########################################################################
# rc4 OBJECTIVE_HEADERS
#
#rc4_OBJECTIVE_HEADERS += \
#$${CIFRA_SRC}/xos/app/console/crypto/cipher/rc4/main.hh \

# rc4 OBJECTIVE_SOURCES
#
#rc4_OBJECTIVE_SOURCES += \
#$${CIFRA_SRC}/xos/app/console/crypto/cipher/rc4/main.mm \

########################################################################
# rc4 HEADERS
#
rc4_HEADERS += \
$${NADIR_SRC}/xos/io/sequence.hpp \
$${NADIR_SRC}/xos/io/seeker.hpp \
$${NADIR_SRC}/xos/io/reader.hpp \
$${NADIR_SRC}/xos/io/writer.hpp \
$${NADIR_SRC}/xos/io/string/reader.hpp \
\
$${NADIR_SRC}/xos/console/main.hpp \
$${NADIR_SRC}/xos/console/getopt/main_opt.hpp \
$${NADIR_SRC}/xos/console/getopt/main.hpp \
$${NADIR_SRC}/xos/app/console/main_opt.hpp \
$${NADIR_SRC}/xos/app/console/main.hpp \
\
$${CIFRA_SRC}/xos/crypto/cipher/base.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/implement.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/extend.hpp \
\
$${CIFRA_SRC}/xos/crypto/cipher/aes/implement.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/aes/extend.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/aes/devine/constants.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/aes/devine/extend.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/aes/devine/implemented.hpp \
\
$${CIFRA_SRC}/xos/crypto/cipher/des/implement.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/des/extend.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/des3/implement.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/des3/extend.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/des/openssl/constants.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/des/openssl/implemented.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/des3/openssl/implemented.hpp \
\
$${CIFRA_SRC}/xos/crypto/cipher/rc4/implement.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/rc4/extend.hpp \
$${CIFRA_SRC}/xos/crypto/cipher/rc4/etiris/implemented.hpp \
\
$${CIFRA_SRC}/xos/crypto/cipher/implemented.hpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/base/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/base/main.hpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/cipher/base/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/cipher/base/main.hpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/cipher/aes/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/cipher/aes/main.hpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/cipher/des3/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/cipher/des3/main.hpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/cipher/rc4/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/cipher/rc4/main.hpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/cipher/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/cipher/main.hpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/sea/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/sea/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# rc4 SOURCES
#
rc4_SOURCES += \
$${NADIR_SRC}/xos/io/sequence.cpp \
$${NADIR_SRC}/xos/io/reader.cpp \
$${NADIR_SRC}/xos/io/writer.cpp \
\
$${NADIR_SRC}/xos/console/io.cpp \
\
$${CIFRA_SRC}/xos/crypto/cipher/implemented.cpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/cipher/rc4/main_opt.cpp \
$${CIFRA_SRC}/xos/app/console/crypto/cipher/rc4/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# rc4 FRAMEWORKS
#
rc4_FRAMEWORKS += \
$${cifra_FRAMEWORKS} \

# rc4 LIBS
#
rc4_LIBS += \
$${cifra_LIBS} \

########################################################################
# NO Qt
QT -= gui core


