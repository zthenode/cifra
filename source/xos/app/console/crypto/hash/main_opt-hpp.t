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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: %date()%
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_CRYPTO_HASH_%ALGORITHM%_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_CRYPTO_HASH_%ALGORITHM%_MAIN_OPT_HPP

#include "xos/app/console/crypto/hash/base/main.hpp"
#include "xos/crypto/hash/%algorithm%.hpp"

namespace xos {
namespace app {
namespace console {
namespace crypto {
namespace hash {
namespace %algorithm% {

/// class main_optt
template 
<class TExtends = crypto::hash::base::main, 
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
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;
    
protected:
    /// ...hash_algorithm
    virtual xos::crypto::hash::algorithm* hash_algorithm() const {
        return %algorithm%_algorithm();
    }
    virtual xos::crypto::hash::%algorithm%* %algorithm%_algorithm() const {
        return 0;
    }
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace %algorithm%
} /// namespace hash
} /// namespace crypto
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_CRYPTO_HASH_%ALGORITHM%_MAIN_OPT_HPP
%
%)%)%