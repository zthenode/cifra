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
#   File: sha1.pro
#
# Author: $author$
#   Date: 9/29/2021
#
# QtCreator .pro file for cifra executable sha1
########################################################################
include(../../../../../build/QtCreator/cifra.pri)
include(../../../../QtCreator/cifra.pri)
include(../../cifra.pri)
include(../../../../QtCreator/app/sha1/sha1.pri)

TARGET = $${sha1_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${sha1_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${sha1_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${sha1_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${sha1_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${sha1_HEADERS} \
$${sha1_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${sha1_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${sha1_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${sha1_LIBS} \
$${FRAMEWORKS} \


