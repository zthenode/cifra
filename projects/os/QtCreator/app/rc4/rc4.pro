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
#   File: rc4.pro
#
# Author: $author$
#   Date: 9/29/2021
#
# QtCreator .pro file for cifra executable rc4
########################################################################
include(../../../../../build/QtCreator/cifra.pri)
include(../../../../QtCreator/cifra.pri)
include(../../cifra.pri)
include(../../../../QtCreator/app/rc4/rc4.pri)

TARGET = $${rc4_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${rc4_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${rc4_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${rc4_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${rc4_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${rc4_HEADERS} \
$${rc4_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${rc4_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${rc4_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${rc4_LIBS} \
$${FRAMEWORKS} \


