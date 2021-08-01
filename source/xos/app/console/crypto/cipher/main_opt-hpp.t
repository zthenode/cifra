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
%#   File: main_opt-hpp.t
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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: %date()%
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_CIPHER_%CIPHER%_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_CIPHER_%CIPHER%_MAIN_OPT_HPP

#include "xos/app/console/crypto/cipher/base/main.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace cipher {
namespace %cipher% {

/// class main_optt
template 
<class TExtends = crypto::cipher::base::main, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::string_reader_t string_reader_t;
    typedef typename extends::char_reader_t char_reader_t;
    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };

    /// constructor / destructor
    main_optt() {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace %cipher%
} /// namespace cipher
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_CIPHER_%CIPHER%_MAIN_OPT_HPP
%
%)%)%