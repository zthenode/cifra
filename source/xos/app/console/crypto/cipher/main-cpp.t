%########################################################################
%# Copyright (c) 1988-2021 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: main-cpp.t
%#
%# Author: $author$
%#   Date: 2/6/2021
%########################################################################
%with(%
%is_cipher,%(%else-then(%is_cipher%,%(%is_Cipher%)%)%)%,%
%cipher,%(%else-then(%if-no(%is_cipher%,,%(%cipher%)%)%,%(%if-no(%is_cipher%,,%(Cipher)%)%)%)%)%,%
%Cipher,%(%else-then(%if-no(%is_cipher%,,%(%Cipher%)%)%,%(%if-no(%is_cipher%,,%(%cipher%)%)%)%)%)%,%
%CIPHER,%(%else-then(%CIPHER%,%(%toupper(%Cipher%)%)%)%)%,%
%cipher,%(%else-then(%_cipher%,%(%tolower(%Cipher%)%)%)%)%,%
%is_implemented,%(%else-then(%is_implemented%,%(%is_Implemented%)%)%)%,%
%implemented,%(%else-then(%if-no(%is_implemented%,,%(%implemented%)%)%,%(%if-no(%is_implemented%,,%(Implemented)%)%)%)%)%,%
%Implemented,%(%else-then(%if-no(%is_implemented%,,%(%Implemented%)%)%,%(%if-no(%is_implemented%,,%(%implemented%)%)%)%)%)%,%
%IMPLEMENTED,%(%else-then(%IMPLEMENTED%,%(%toupper(%Implemented%)%)%)%)%,%
%implemented,%(%else-then(%_implemented%,%(%tolower(%Implemented%)%)%)%)%,%
%%(%
%///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-%year()% $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.cpp
///
/// Author: $author$
///   Date: %date()%
///////////////////////////////////////////////////////////////////////
#include "xos/app/console/crypto/cipher/%cipher%/main.hpp"

#if !defined(XOS_APP_CONSOLE_CRYPTO_CIPHER_%CIPHER%_MAIN_INSTANCE)
///#define XOS_APP_CONSOLE_CRYPTO_CIPHER_%CIPHER%_MAIN_INSTANCE
#endif /// !defined(XOS_APP_CONSOLE_CRYPTO_CIPHER_%CIPHER%_MAIN_NSTANCE)

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {
namespace %cipher% {

/// class main
#if defined(XOS_APP_CONSOLE_CRYPTO_CIPHER_%CIPHER%_MAIN_INSTANCE)
static main the_main;
#endif /// defined(XOS_APP_CONSOLE_CRYPTO_CIPHER_%CIPHER%_MAIN_INSTANCE)

} /// namespace %cipher%
} /// namespace cipher
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos
%
%)%)%