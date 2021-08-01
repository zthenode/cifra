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
#   File: aes.pri
#
# Author: $author$
#   Date: 7/31/2021
#
# QtCreator .pri file for cifra executable aes
########################################################################

########################################################################
# aes

# aes TARGET
#
aes_TARGET = aes

# aes INCLUDEPATH
#
aes_INCLUDEPATH += \
$${cifra_INCLUDEPATH} \

# aes DEFINES
#
aes_DEFINES += \
$${cifra_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_CRYPTO_CIPHER_AES_MAIN_INSTANCE \

########################################################################
# aes OBJECTIVE_HEADERS
#
#aes_OBJECTIVE_HEADERS += \
#$${CIFRA_SRC}/cifra/app/console/aes/main.hh \

# aes OBJECTIVE_SOURCES
#
#aes_OBJECTIVE_SOURCES += \
#$${CIFRA_SRC}/cifra/app/console/aes/main.mm \

########################################################################
# aes HEADERS
#
aes_HEADERS += \
$${NADIR_SRC}/xos/io/sequence.hpp \
$${NADIR_SRC}/xos/io/seeker.hpp \
$${NADIR_SRC}/xos/io/reader.hpp \
$${NADIR_SRC}/xos/io/writer.hpp \
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
$${CIFRA_SRC}/xos/app/console/crypto/base/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/base/main.hpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/cipher/base/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/cipher/base/main.hpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/cipher/aes/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/crypto/cipher/aes/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# aes SOURCES
#
aes_SOURCES += \
$${CIFRA_SRC}/xos/crypto/cipher/aes/devine/implemented.cpp \
\
$${CIFRA_SRC}/xos/app/console/crypto/cipher/aes/main_opt.cpp \
$${CIFRA_SRC}/xos/app/console/crypto/cipher/aes/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \

########################################################################
# aes FRAMEWORKS
#
aes_FRAMEWORKS += \
$${cifra_FRAMEWORKS} \

# aes LIBS
#
aes_LIBS += \
$${cifra_LIBS} \


