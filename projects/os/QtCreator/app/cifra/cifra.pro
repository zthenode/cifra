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
#   File: cifra.pro
#
# Author: $author$
#   Date: 7/31/2021
#
# QtCreator .pro file for cifra executable cifra
########################################################################
include(../../../../../build/QtCreator/cifra.pri)
include(../../../../QtCreator/cifra.pri)
include(../../cifra.pri)
include(../../../../QtCreator/app/cifra/cifra.pri)

TARGET = $${cifra_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${cifra_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${cifra_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${cifra_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${cifra_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${cifra_exe_HEADERS} \
$${cifra_exe_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${cifra_exe_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${cifra_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${cifra_exe_LIBS} \
$${FRAMEWORKS} \


