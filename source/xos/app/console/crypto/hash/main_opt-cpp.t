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
%#   File: main_opt-cpp.t
%#
%# Author: $author$
%#   Date: 2/8/2021
%########################################################################
%with(%
%is_algorithm,%(%else-then(%is_algorithm%,%(%is_Algorithm%)%)%)%,%
%algorithm,%(%else-then(%if-no(%is_algorithm%,,%(%algorithm%)%)%,%(%if-no(%is_algorithm%,,%(Algorithm)%)%)%)%)%,%
%Algorithm,%(%else-then(%if-no(%is_algorithm%,,%(%Algorithm%)%)%,%(%if-no(%is_algorithm%,,%(%algorithm%)%)%)%)%)%,%
%ALGORITHM,%(%else-then(%ALGORITHM%,%(%toupper(%Algorithm%)%)%)%)%,%
%algorithm,%(%else-then(%_algorithm%,%(%tolower(%Algorithm%)%)%)%)%,%
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
///   File: main_opt.cpp
///
/// Author: $author$
///   Date: %date()%
///////////////////////////////////////////////////////////////////////
#include "xos/app/console/crypto/hash/%algorithm%/main_opt.hpp"

#if !defined(XOS_APP_CONSOLE_CRYPTO_HASH_%ALGORITHM%_MAIN_OPT_INSTANCE)
///#define XOS_APP_CONSOLE_CRYPTO_HASH_%ALGORITHM%_MAIN_OPT_INSTANCE
#endif /// !defined(XOS_APP_CONSOLE_CRYPTO_HASH_%ALGORITHM%_MAIN_OPT_INSTANCE)

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace hash {
namespace %algorithm% {

/// class main_optt
#if defined(XOS_APP_CONSOLE_CRYPTO_HASH_%ALGORITHM%_MAIN_OPT_INSTANCE)
static main_opt the_main_opt;
#endif /// defined(XOS_APP_CONSOLE_CRYPTO_HASH_%ALGORITHM%_MAIN_OPT_INSTANCE)

} /// namespace %algorithm%
} /// namespace hash
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos
%
%)%)%